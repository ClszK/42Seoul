/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh <ljh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 01:43:11 by ljh               #+#    #+#             */
/*   Updated: 2023/09/26 16:29:36 by ljh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clear_img(t_game *game, int move);

int	next_x(int flag)
{
	if (flag == LEFT)
		return (-1);
	else if (flag == RIGHT)
		return (1);
	else
		return (0);
}

int	next_y(int flag)
{
	if (flag == UP)
		return (-1);
	else if (flag == DOWN)
		return (1);
	else
		return (0);
}

void	my_pixel_put(t_game *game, t_imgdata i_cfg)
{
	t_map	*m_cfg;

	m_cfg = game->m_cfg;
	i_cfg.pixel_pos = (i_cfg.y * i_cfg.line + i_cfg.x * (i_cfg.bpp / 8));
	i_cfg.pixel_data = *(unsigned int *)(i_cfg.img_data + i_cfg.pixel_pos);
	if (i_cfg.pixel_data != 0x00000000)
		mlx_pixel_put(game->mlx_ptr, game->win_ptr, \
					m_cfg->pos_x * WIDTH + WIDTH - (i_cfg.x_range - i_cfg.x) + game->key_flag.pos_cnt * next_x(game->key_flag.flag), \
					m_cfg->pos_y * HEIGHT + HEIGHT - (i_cfg.y_range - i_cfg.y) + game->key_flag.pos_cnt * next_y(game->key_flag.flag), \
					i_cfg.pixel_data);
}

void	character_move(t_game *game, int move, int state)
{
	t_imgdata	i_cfg;

	i_cfg.img_data = mlx_get_data_addr(game->img->character, &i_cfg.bpp, &i_cfg.line, &i_cfg.endian);
	if (i_cfg.img_data == NULL)
		error_msg(game->m_cfg, "힝...");
	i_cfg.x = state * WIDTH;
	i_cfg.x_range = i_cfg.x + WIDTH;
	i_cfg.y = move * HEIGHT;
	i_cfg.y_range = i_cfg.y + HEIGHT;
	clear_img(game, move);
	while (i_cfg.y++ < i_cfg.y_range - 1)
	{
		while (i_cfg.x++ < i_cfg.x_range - 1)
			my_pixel_put(game, i_cfg);
		i_cfg.x = state * WIDTH;
	}
	game->key_flag.pos_cnt += 6;
}

void	clear_img(t_game *game, int move)
{
	size_t	x;
	size_t	y;
	t_map	*m_cfg;
	void	*img_tmp;

	m_cfg = game->m_cfg;
	x = m_cfg->pos_x + next_x(move) - 1;
	y = m_cfg->pos_y + next_y(move) - 1;
	while (y <= m_cfg->pos_y + next_y(move) + 1)
	{
		while (x <= m_cfg->pos_x +next_x(move) + 1)
		{
			if (game->m_cfg->map[y][x] == '1')
				img_tmp = game->img->wall_ptr;
			else if (game->m_cfg->map[y][x] == '0')
				img_tmp = game->img->tile_ptr;
			else if (game->m_cfg->map[y][x] == 'E')
				img_tmp = game->img->exit_ptr;
			else if (game->m_cfg->map[y][x] == 'C')
				img_tmp = game->img->collect_ptr;
			else
				img_tmp = game->img->tile_ptr;
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img_tmp, WIDTH * x, HEIGHT * y);
			x++;
		}
		x = m_cfg->pos_x + next_x(move) - 1;
		ft_printf("%d %d\n", x, y);
		y++;
	}
}

int		close_program(t_game *game)
{
	t_map 	*m_cfg;

	m_cfg = game->m_cfg;
	while (m_cfg->y > 0)
	{
		m_cfg->y--;
		ft_printf("%d\n", m_cfg->y);
		free(m_cfg->map[m_cfg->y]);
	}
	free(m_cfg->map);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	atexit(check_leak);
	exit(0);
	return (0);
}
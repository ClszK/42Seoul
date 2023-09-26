/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 22:39:16 by jeholee           #+#    #+#             */
/*   Updated: 2023/09/27 06:22:00 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	loop_hook(t_game *game)
{
	t_key	*key_flag;
	t_map	*m_cfg;

	key_flag = &game->key_flag;
	m_cfg = game->m_cfg;
	if (key_flag->rock == 1)
	{
		if (key_flag->pos_cnt < 24 || key_flag->pos_cnt > 48)
			key_flag->state = MOVE_1;
		else
			key_flag->state = MOVE_2;
		splite_move(game, key_flag->state, m_cfg->pos_x \
		+ next_x(key_flag->flag), m_cfg->pos_y + next_y(key_flag->flag));
		if (m_cfg->map[m_cfg->pos_y][m_cfg->pos_x] == 'E')
		{
			ft_printf("!!Game Complete!!\n");
			exit(0);
		}
		if (m_cfg->map[m_cfg->pos_y][m_cfg->pos_x] == 'X')
		{
			ft_printf("!!Game Over!!\n");
			exit(0);
		}
	}
	return (0);
}

void	splite_move(t_game *game, int state, size_t x, size_t y)
{
	t_map	*m_cfg;
	t_key	*key_flag;

	m_cfg = game->m_cfg;
	key_flag = &game->key_flag;
	character_move(game, key_flag->flag, state);
	if (key_flag->pos_cnt == 56)
	{
		if (m_cfg->map[y][x] == 'C')
		{
			m_cfg->map[y][x] = '0';
			m_cfg->c_cnt--;
		}
		character_move(game, key_flag->flag, STOP);
		key_flag->pos_cnt = 0;
		m_cfg->pos_x += next_x(key_flag->flag);
		m_cfg->pos_y += next_y(key_flag->flag);
		game->move_cnt++;
		if (game->print == MANDANTORY)
			ft_printf("Current move : %d\n", game->move_cnt);
		else
			bonus_move_print(game);
		key_flag->rock = 0;
	}
}

void	bonus_move_print(t_game *game)
{
	char	str[29];
	size_t	x;
	char	*move_int;

	x = 0;
	ft_strcpy(str, "Currnent move : ");
	move_int = ft_itoa(game->move_cnt);
	if (move_int == NULL)
		error_msg(game->m_cfg, NULL);
	(void)ft_strlcat(str, move_int, 29);
	while (x++ < game->m_cfg->x)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->img->wall_ptr, WIDTH * x, 0);
	(void)mlx_string_put(game->mlx_ptr, game->win_ptr, \
						32, 32, 0xFF0000, str);
	free(move_int);
}

void	map_free(char **map_cpy, size_t y)
{
	if (map_cpy == NULL)
		return ;
	while (y > 0)
		free(map_cpy[--y]);
	free(map_cpy);
}

void	my_image_destory(t_game *game)
{
	t_img	*img;

	img = game->img;
	if (img->tile_ptr != NULL)
		mlx_destroy_image(game->win_ptr, img->tile_ptr);
	if (img->down_ptr != NULL)
		mlx_destroy_image(game->win_ptr, img->down_ptr);
	if (img->wall_ptr != NULL)
		mlx_destroy_image(game->win_ptr, img->wall_ptr);
	if (img->exit_ptr != NULL)
		mlx_destroy_image(game->win_ptr, img->exit_ptr);
	if (img->enemy_ptr != NULL)
		mlx_destroy_image(game->win_ptr, img->enemy_ptr);
	if (img->collect_ptr != NULL)
		mlx_destroy_image(game->win_ptr, img->collect_ptr);
	if (img->character != NULL)
		mlx_destroy_image(game->win_ptr, img->character);
}

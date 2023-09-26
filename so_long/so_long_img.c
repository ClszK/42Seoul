/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh <ljh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:57:48 by jeholee           #+#    #+#             */
/*   Updated: 2023/09/26 15:48:39 by ljh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_generate(t_game *game)
{
	t_map	*m_cfg;

	m_cfg = game->m_cfg;
	game->img = node_img_generate();
	img_save_ptr(game);
	img_push(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->down_ptr , WIDTH * m_cfg->pos_x, HEIGHT * m_cfg->pos_y);
}

void	img_save_ptr(t_game *game)
{
	int	img_width;
	int	img_height;
	t_img	*img;

	img = game->img;
	img->tile_ptr = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/tile.xpm", &img_width, &img_height);
	img->down_ptr = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/down.xpm", &img_width, &img_height);
	img->wall_ptr = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/wall.xpm", &img_width, &img_height);
	img->exit_ptr = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/exit.xpm", &img_width, &img_height);
	img->collect_ptr = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/collect.xpm", &img_width, &img_height);
	img->enemy_ptr = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/down.xpm", &img_width, &img_height);
	img->character = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/character.xpm", &img_width, &img_height);
}

void	img_push(t_game *game)
{
	size_t	x;	
	size_t	y;
	void	*img_tmp;

	y = (size_t)(-1);
	while (++y < game->m_cfg->y)
	{
		x = (size_t)(-1);
		while (++x < game->m_cfg->x)
		{
			if (game->m_cfg->map[y][x] == '1')
				img_tmp = game->img->wall_ptr;
			else if (game->m_cfg->map[y][x] == '0')
				img_tmp = game->img->tile_ptr;
			else if (game->m_cfg->map[y][x] == 'E')
				img_tmp = game->img->exit_ptr;
			else if (game->m_cfg->map[y][x] == 'C')
				img_tmp = game->img->collect_ptr;
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img_tmp, WIDTH * x, HEIGHT * y);
		}
	}
}
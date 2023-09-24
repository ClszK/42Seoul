/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:57:48 by jeholee           #+#    #+#             */
/*   Updated: 2023/09/24 12:06:59 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	*node_img_generate();

void	img_generate(t_game *game)
{
	game->img = node_img_generate();
	img_save_ptr(game);
	img_push(game);
}

void	img_save_ptr(t_game *game)
{
	int	img_width;
	int	img_height;
	t_img	*img;

	img = game->img;
	img->tile_ptr = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/background.xpm", &img_width, &img_height);
	img->down_ptr = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/down.xpm", &img_width, &img_height);
	img->wall_ptr = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/wall.xpm", &img_width, &img_height);
	img->exit_ptr = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/exit.xpm", &img_width, &img_height);
	img->collect_ptr = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/collect.xpm", &img_width, &img_height);
	img->up_ptr = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/up.xpm", &img_width, &img_height);
	img->left_ptr = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/left.xpm", &img_width, &img_height);
	img->right_ptr = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/right.xpm", &img_width, &img_height);
	img->enemy_ptr = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/down.xpm", &img_width, &img_height);
	img->test = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/test2.xpm", &img_width, &img_height);

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
			else if (game->m_cfg->map[y][x] == 'P')
				img_tmp = game->img->down_ptr;
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img_tmp, WIDTH * x, HEIGHT * y);
		}
	}
}

t_img	*node_img_generate()
{
	t_img	*node;

	node = (t_img*)malloc(sizeof(t_img));
	if (node == NULL)
		error_msg(NULL,NULL);	
	node->tile_ptr = NULL;
	node->up_ptr = NULL;
	node->down_ptr = NULL;
	node->left_ptr = NULL;
	node->right_ptr = NULL;
	node->wall_ptr = NULL;
	node->exit_ptr = NULL;
	node->enemy_ptr = NULL;
	node->collect_ptr = NULL;
	return (node);
}


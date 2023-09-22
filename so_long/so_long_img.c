/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:57:48 by jeholee           #+#    #+#             */
/*   Updated: 2023/09/22 17:56:30 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_create(t_vars *vars, t_img *img, t_map *m_cfg)
{
	img_save_ptr(vars, img, m_cfg);
	img_push(vars, img, m_cfg);
}

void	img_save_ptr(t_vars *vars, t_img *img, t_map *m_cfg)
{
	int		img_width;
	int		img_height;

	(void)m_cfg;
	img->tile_ptr = mlx_xpm_file_to_image(vars->mlx, "./textures/background.xpm", &img_width, &img_height);
	img->down_ptr = mlx_xpm_file_to_image(vars->mlx, "./textures/down.xpm", &img_width, &img_height);
	img->wall_ptr = mlx_xpm_file_to_image(vars->mlx, "./textures/wall.xpm", &img_width, &img_height);
	img->exit_ptr = mlx_xpm_file_to_image(vars->mlx, "./textures/up.xpm", &img_width, &img_height);
	img->collect_ptr = mlx_xpm_file_to_image(vars->mlx, "./textures/left.xpm", &img_width, &img_height);
	// img->up_ptr = mlx_xpm_file_to_image(vars->mlx, "./textures/up.xpm", &img_width, &img_height);
	// img->left_ptr = mlx_xpm_file_to_image(vars->mlx, "./textures/left.xpm", &img_width, &img_height);
	// img->right_ptr = mlx_xpm_file_to_image(vars->mlx, "./textures/right.xpm", &img_width, &img_height);
	// img->enemy_ptr = mlx_xpm_file_to_image(vars->mlx, "./textures/down.xpm", &img_width, &img_height);
}

void	img_push(t_vars *vars, t_img *img, t_map *m_cfg)
{
	size_t	x;	
	size_t	y;
	void	*img_tmp;

	y = (size_t)(-1);
	while (++y < m_cfg->y)
	{
		x = (size_t)(-1);
		while (++x < m_cfg->x)
		{
			if (m_cfg->map[y][x] == '1')
				img_tmp = img->wall_ptr;
			else if (m_cfg->map[y][x] == '0')
				img_tmp = img->tile_ptr;
			else if (m_cfg->map[y][x] == 'E')
				img_tmp = img->exit_ptr;
			else if (m_cfg->map[y][x] == 'C')
				img_tmp = img->collect_ptr;
			else if (m_cfg->map[y][x] == 'P')
				img_tmp = img->down_ptr;
			else
				img_tmp	= img->down_ptr;
			mlx_put_image_to_window(vars->mlx, vars->win, img_tmp, WIDTH * x, HEIGHT * y);
		}
	}
}
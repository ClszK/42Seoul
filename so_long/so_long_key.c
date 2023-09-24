/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:49:00 by jeholee           #+#    #+#             */
/*   Updated: 2023/09/24 13:20:20 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_move_up(t_game *game);

// void process_and_put_image(void *mlx, void *win, void *img, int x_offset, int y_offset, t_map *m_cfg)
// void process_and_put_image(t_game *game)
// {
//     int bits_per_pixel;
// 	int line_length;
// 	int	endian;

// 	t_img	*img;
// 	t_map	*m_cfg;

// 	img = game->img;
// 	m_cfg = game->m_cfg;
//     char *img_data = mlx_get_data_addr(img->test, &bits_per_pixel, &line_length, &endian);
// 	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img->tile_ptr, WIDTH * m_cfg->pos_x, HEIGHT * m_cfg->pos_y);
// 	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img->tile_ptr, WIDTH * m_cfg->pos_x, HEIGHT * (m_cfg->pos_y - 1));
// 	for (int y = 0; y < 64; y++)
// 	{
// 		for (int x = 0; x < 64; x++)
// 		{
// 			int pixel_pos = (y * line_length + x * (bits_per_pixel / 8));
// 			unsigned int pixel_data = *(unsigned int *)(img_data + pixel_pos);

// 			// "None"에 해당하는 픽셀을 무시합니다. 여기서는 0x00000000이 "None"으로 가정합니다.
// 			if (pixel_data != 0x00000000)
// 				mlx_pixel_put(game->mlx_ptr, game->win_ptr, x + WIDTH *  m_cfg->pos_x, y + HEIGHT * m_cfg->pos_y - 1 , pixel_data);
// 		}
// 	}
// }

int	key_hook(int keycode, t_game *game)
{
	t_img	*img;
	t_map	*m_cfg;

	img = game->img;
	m_cfg = game->m_cfg;
	ft_printf("x : %d y: %d\n", m_cfg->pos_x, m_cfg->pos_y);
	if (game->key_flag.rock == 0)
	{
		if (keycode == KEY_ESC)
		{
			mlx_destroy_window(game->mlx_ptr, game->win_ptr);
			exit(0); // 종료 테스트 이이잉
		}
		else if (keycode == KEY_W && m_cfg->map[m_cfg->pos_y - 1][m_cfg->pos_x] != '1')
		{
			// mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img->tile_ptr, WIDTH * m_cfg->pos_x, HEIGHT * m_cfg->pos_y);
			// mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img->up_ptr, WIDTH * m_cfg->pos_x, HEIGHT * (m_cfg->pos_y - 1));

			// int width, height;

			// void *img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/test2.xpm", &width, &height);

			// process_and_put_image(game);
			// process_and_put_image(game->mlx_ptr, game->win_ptr, img_ptr, WIDTH * m_cfg->pos_x, HEIGHT * m_cfg->pos_y - 64);

			game->key_flag.w_flag = 1;
			game->key_flag.rock = 1;
		}
		else if (keycode == KEY_A && m_cfg->map[m_cfg->pos_y][m_cfg->pos_x - 1] != '1')
		{

		}
		else if (keycode == KEY_S && m_cfg->map[m_cfg->pos_y + 1][m_cfg->pos_x] != '1')
		{
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img->tile_ptr, WIDTH * m_cfg->pos_x, HEIGHT * m_cfg->pos_y);
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img->down_ptr, WIDTH * m_cfg->pos_x, HEIGHT * (m_cfg->pos_y + 1));
			m_cfg->pos_y++;	
		}
		else if (keycode == KEY_D && m_cfg->map[m_cfg->pos_y][m_cfg->pos_x + 1] != '1')
		{

		}
	}
	return (0);
}


void	key_move_up(t_game *game)
{
	(void)game;
}
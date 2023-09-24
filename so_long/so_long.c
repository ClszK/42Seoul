/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:42:28 by jeholee           #+#    #+#             */
/*   Updated: 2023/09/24 14:23:07 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void process_and_put_image(t_game *game)
{
	t_imgdata	i_cfg;
	t_img	*img;
	t_map	*m_cfg;

	img = game->img;
	m_cfg = game->m_cfg;
    i_cfg.img_data = mlx_get_data_addr(img->test, &i_cfg.bpp, &i_cfg.line, &i_cfg.endian);
	i_cfg.x = -1;
	i_cfg.y = -1;
	while (++i_cfg.y < HEIGHT)
	{
		while (++i_cfg.x < WIDTH)
		{
			i_cfg.pixel_pos = (i_cfg.y * i_cfg.line + i_cfg.x * (i_cfg.bpp / 8));
			i_cfg.pixel_data = *(unsigned int *)(i_cfg.img_data + i_cfg.pixel_pos);
			if (i_cfg.pixel_data != 0x00000000)
				mlx_pixel_put(game->mlx_ptr, game->win_ptr, i_cfg.x + WIDTH * m_cfg->pos_x, i_cfg.y + HEIGHT * m_cfg->pos_y - game->key_flag.pos_cnt , i_cfg.pixel_data);
		}
		i_cfg.x = 0;
	}
	game->key_flag.pos_cnt += 4;
}

t_game	*node_game_generate();

int	test(t_game *game)
{
	t_key	key_flag;
	t_map	*m_cfg;
	t_img	*img;

	key_flag = game->key_flag;
	m_cfg = game->m_cfg;
	img = game->img;
	if (key_flag.w_flag == 1)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img->tile_ptr, WIDTH * m_cfg->pos_x, HEIGHT * m_cfg->pos_y);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img->tile_ptr, WIDTH * m_cfg->pos_x, HEIGHT * (m_cfg->pos_y - 1));
		process_and_put_image(game);
	}
	if (game->key_flag.pos_cnt == 64)
	{
		game->key_flag.pos_cnt = 0;
		game->key_flag.w_flag = 0;
		game->key_flag.rock = 0;
		m_cfg->pos_y--;
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_game	*game;
	
	if (argc != 2)
		error_msg(NULL, "No argument");
	
	game = node_game_generate();

	game->m_cfg = map_generate(argv[1]);
	map_validation_check(game->m_cfg);

	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, WIDTH * game->m_cfg->x, HEIGHT * game->m_cfg->y, "hello World!");

	img_generate(game);

	// for (size_t i = 0 ; i < m_cfg->y; i++)
	// 	ft_printf("%s", m_cfg->map[i]);
	// mlx_put_image_to_window(vars->mlx, vars->win, img->img_ptr, 48, 48);
	mlx_key_hook(game->win_ptr, key_hook, game);
	mlx_loop_hook(game->mlx_ptr,test,game);
	mlx_loop(game->mlx_ptr); // loop를 돌면서 event를 기다리고, 생성한 윈도우를 Rendering한다.

	return 0;
}

t_game	*node_game_generate()
{
	t_game *node;

	node = (t_game*)malloc(sizeof(t_game));
	if (node == NULL)
		error_msg(NULL, NULL);
	node->img = NULL;
	node->m_cfg = NULL;
	node->mlx_ptr = NULL;
	node->win_ptr = NULL;
	node->key_flag.w_flag = 0;
	node->key_flag.a_flag = 0;
	node->key_flag.s_flag = 0;
	node->key_flag.d_flag = 0;
	node->key_flag.pos_cnt = 0;
	node->key_flag.rock = 0;
	return (node);
}
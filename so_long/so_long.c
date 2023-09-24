/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh <ljh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:42:28 by jeholee           #+#    #+#             */
/*   Updated: 2023/09/24 00:05:28 by ljh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*node_game_generate();

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
	return (node);
}
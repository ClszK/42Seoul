/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:10:39 by ljh               #+#    #+#             */
/*   Updated: 2023/10/05 17:48:01 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "../so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error_msg(NULL, "No argument");
	game_generate(&game);
	game.print = BONUS;
	game.m_cfg = map_generate(argv[1]);
	map_validation_check(game.m_cfg);
	game.mlx_ptr = mlx_init();
	game.win_ptr = mlx_new_window(game.mlx_ptr, WIDTH * game.m_cfg->x, \
									HEIGHT * game.m_cfg->y, "hello World!");
	enemy_generate(&game, 0, 0);
	img_generate(&game);
	bonus_move_print(&game);
	mlx_key_hook(game.win_ptr, key_hook, &game);
	mlx_hook(game.win_ptr, KEY_EXIT, 0, close_program, &game);
	mlx_loop_hook(game.mlx_ptr, loop_hook, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}

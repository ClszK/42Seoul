/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:42:28 by jeholee           #+#    #+#             */
/*   Updated: 2023/10/08 13:16:55 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	errno = ERRNO_OK;
	if (argc != 2)
		error_msg(NULL, "No argument");
	game_generate(&game);
	game.m_cfg = map_generate(argv[1]);
	map_validation_check(game.m_cfg);
	game.mlx_ptr = mlx_init();
	game.win_ptr = mlx_new_window(game.mlx_ptr, WIDTH * game.m_cfg->x, \
									HEIGHT * game.m_cfg->y, "so_long");
	img_generate(&game);
	if (ft_printf("Current move : 0\n") < 0)
		error_msg(game.m_cfg, NULL);
	mlx_key_hook(game.win_ptr, key_hook, &game);
	mlx_hook(game.win_ptr, KEY_EXIT, 0, close_program, &game);
	mlx_loop_hook(game.mlx_ptr, loop_hook, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}

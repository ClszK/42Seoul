/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh <ljh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:42:28 by jeholee           #+#    #+#             */
/*   Updated: 2023/09/26 12:38:24 by ljh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_leak(void)
{
	system("leaks so_long");
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

	mlx_key_hook(game->win_ptr, key_hook, game);
	mlx_hook(game->win_ptr, KEY_EXIT, 0, close_program, game);
	mlx_loop_hook(game->mlx_ptr,loop_hook,game);
	mlx_loop(game->mlx_ptr); // loop를 돌면서 event를 기다리고, 생성한 윈도우를 Rendering한다.

	return (0);
}

int	loop_hook(t_game *game)
{
	t_key	*key_flag;
	t_map	*m_cfg;
	int		state;

	key_flag = &game->key_flag;
	m_cfg = game->m_cfg;
	if (key_flag->rock == 1)
	{
		if (key_flag->pos_cnt < 24 || key_flag->pos_cnt > 48)
			state = MOVE_1;
		else
			state = MOVE_2;
		splite_move(game, state);
		if (m_cfg->map[m_cfg->pos_y][m_cfg->pos_x] == 'E')
		{
			ft_printf("!!Game Complete!!\n");
			atexit(check_leak);
			exit(1);
		}
	}
	return (0);
}

void	splite_move(t_game *game, int state)
{
	t_map	*m_cfg;
	t_key	*key_flag;

	m_cfg = game->m_cfg;
	key_flag = &game->key_flag;
	character_move(game, key_flag->flag, state);
	if (key_flag->pos_cnt == 60)
	{
		if (m_cfg->map[m_cfg->pos_y + next_y(key_flag->flag)][m_cfg->pos_x + next_x(key_flag->flag)] == 'C')
		{
			m_cfg->map[m_cfg->pos_y + next_y(key_flag->flag)][m_cfg->pos_x + next_x(key_flag->flag)] = '0';
			m_cfg->c_cnt--;
		}
		character_move(game, key_flag->flag, STOP);
		key_flag->pos_cnt = 0;
		m_cfg->pos_x += next_x(key_flag->flag);
		m_cfg->pos_y += next_y(key_flag->flag);
		ft_printf("Current x : %d  y : %d\n", m_cfg->pos_x, m_cfg->pos_y);
		key_flag->rock = 0;
	}
}
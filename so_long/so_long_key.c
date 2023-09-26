/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh <ljh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:49:00 by jeholee           #+#    #+#             */
/*   Updated: 2023/09/26 16:50:14 by ljh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_game *game)
{
	if (game->key_flag.rock == 0 && is_key(keycode))
	{
		game->key_flag.rock = 1;
		if (keycode == KEY_ESC)
		{
			mlx_destroy_window(game->mlx_ptr, game->win_ptr);
			atexit(check_leak);
			exit(0); // 종료 테스트 이이잉
		}
		else if(move_valid(keycode, game) > 0)
			return (0);
		else
			game->key_flag.rock = 0;
	}
	return (0);
}

int	is_key(int keycode)
{
	if (keycode == KEY_ESC ||keycode == KEY_A || keycode == KEY_D ||keycode == KEY_S || keycode == KEY_W)
		return (1);
	else
		return (0);
}

int	key_to_flag(int keycode)
{
	if (keycode == KEY_A)
		return (LEFT);
	else if (keycode == KEY_D)
		return (RIGHT);
	else if (keycode == KEY_S)
		return (DOWN);
	else if (keycode == KEY_W)
		return (UP);
	else
		return (-1);
}

int	move_valid(int keycode, t_game *game)
{
	size_t	x;
	size_t	y;
	t_map	*m_cfg;
	int		flag;

	m_cfg = game->m_cfg;
	flag = key_to_flag(keycode);
	if (flag < 0)
		return (-1);
	x = m_cfg->pos_x + next_x(flag);
	y = m_cfg->pos_y + next_y(flag);
	if (m_cfg->map[y][x] == '1' || \
	(m_cfg->map[y][x] == 'E' && m_cfg->c_cnt != 0 ))
		return (0);
	else
	{
		game->key_flag.flag = flag;
		return (1);
	}
}
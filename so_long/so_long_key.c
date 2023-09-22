/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:49:00 by jeholee           #+#    #+#             */
/*   Updated: 2023/09/22 18:15:55 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_move_up(t_vars *vars);

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0); // 종료 테스트 이이잉
	}
	else if (keycode == KEY_W)
	{
		v
	}
	else if (keycode == KEY_A)
	{

	}
	else if (keycode == KEY_S)
	{

	}
	else if (keycode == KEY_D)
	{

	}

	return (0);
}


void	key_move_up(t_vars *vars)
{

}
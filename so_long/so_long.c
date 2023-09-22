/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:42:28 by jeholee           #+#    #+#             */
/*   Updated: 2023/09/22 19:04:02 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int main(int argc, char **argv)
{
	t_vars	*vars;
	t_img	*img;
	t_map	*m_cfg;
	
	if (argc != 2)
		error_msg(NULL, "No argument");
	
	if (img == NULL || vars == NULL)
		error_msg(NULL, NULL);

	m_cfg = map_generate(argv[1]);
	map_validation_check(m_cfg);
	
	m_cfg->vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIDTH * m_cfg->x, HEIGHT * m_cfg->y, "hello World!");

	img_create(vars, img, m_cfg);
	// for (size_t i = 0 ; i < m_cfg->y; i++)
	// 	ft_printf("%s", m_cfg->map[i]);
	// mlx_put_image_to_window(vars->mlx, vars->win, img->img_ptr, 48, 48);
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_loop(vars->mlx); // loop를 돌면서 event를 기다리고, 생성한 윈도우를 Rendering한다.

	return 0;
}

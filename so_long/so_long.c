/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:42:28 by jeholee           #+#    #+#             */
/*   Updated: 2023/09/20 19:55:27 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	if (keycode == KEY_D)
	{

	}
	return (0);
}

int main(int argc, char **argv)
{
	t_vars	*vars;
	t_data	*img;
	int		img_width;
	int		img_height;
	void	*img2;

	t_map	*map;


	if (argc != 2)
		return (-1);
	
	img	= (t_data*)malloc(sizeof(t_data));
	vars = (t_vars*)malloc(sizeof(t_vars));
	if (img == NULL || vars == NULL)
		return (-1);
	map = map_gnl(argv[1]);
	
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 500, 500, "hello World!");
	img->img_ptr = mlx_xpm_file_to_image(vars->mlx, "./textures/wall.xpm", &img_width, &img_height);
	img2 = mlx_xpm_file_to_image(vars->mlx, "./textures/background.xpm", &img_width, &img_height);
	
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_put_image_to_window(vars->mlx, vars->win, img2, 0, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, img->img_ptr, 48, 48);
	mlx_loop(vars->mlx); // loop를 돌면서 event를 기다리고, 생성한 윈도우를 Rendering한다.

	return 0;
}
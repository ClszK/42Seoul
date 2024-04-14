/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:54:01 by jeholee           #+#    #+#             */
/*   Updated: 2024/04/14 23:36:13 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <stdio.h>

t_color	ray_color(const t_ray *r)
{
	t_vec3	unit_direction;
	double	t;
	t_color	color1;
	t_color	color2;

	unit_direction = vec3_unit_vec(&r->dir);
	t = 0.5 * (unit_direction.y + 1.0);
	color_init(&color1, 1.0, 1.0, 1.0);
	color1 = vec3_mul_scal(&color1, 1.0 - t);
	color_init(&color2, 0.5, 0.7, 1.0);
	color2 = vec3_mul_scal(&color2, t);
	return vec3_add(&color1, &color2);
}

int main()
{
	t_vars vars;
	t_data image;
	t_color color;

	double	aspect_ratio;
	int		image_width;

	int		image_height;

	double	focal_length;
	double	viewport_height;
	double	viewport_width;
	t_point3	camera_center;

	t_vec3	viewport_u;
	t_vec3	viewport_v;

	t_vec3	pixel_delta_u;
	t_vec3	pixel_delta_v;

	t_vec3	viewport_upper_left;
	t_vec3	pixel00_loc;

	// Image
	aspect_ratio  = 16.0 / 9.0;
	image_width = 400;

	// Calculate the image height, and ensure that it's at least 1.
	image_height = (int)(image_width / aspect_ratio);
	if (image_height < 1)
		image_height = 1;

	// Camera
	focal_length = 1.0;
	viewport_height = 2.0;
	viewport_width = viewport_height * ((double)(image_width) / image_height);
	vec3_init(&camera_center, 0, 0, 0);

	vec3_init(&viewport_u, viewport_width, 0, 0);
	vec3_init(&viewport_v, 0, -viewport_height, 0);

	pixel_delta_u = vec3_div_scal(&viewport_u, (double)image_width);
	pixel_delta_v = vec3_div_scal(&viewport_v, (double)image_height);

	t_vec3	tmp;
	t_vec3	viewport_u_div_2;
	t_vec3	viewport_v_div_2;

	vec3_init(&tmp, 0, 0, focal_length);
	viewport_upper_left = vec3_sub(&camera_center, &tmp);
	viewport_u_div_2 = vec3_div_scal(&viewport_u, 2);
	viewport_v_div_2 = vec3_div_scal(&viewport_v, 2);
	viewport_upper_left = vec3_sub(&viewport_upper_left, &viewport_u_div_2);
	viewport_upper_left = vec3_sub(&viewport_upper_left, &viewport_v_div_2);
	
	t_vec3	delta_add;
	t_vec3	delta_mul_2;

	delta_add = vec3_add(&pixel_delta_u, &pixel_delta_v);
	delta_mul_2 = vec3_mul_scal(&delta_add, 0.5);
	pixel00_loc = vec3_add(&viewport_upper_left, &delta_mul_2);

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 500, "Hellow World!");
	image.img = mlx_new_image(vars.mlx, 500, 500); // 이미지 객체 생성
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian); // 이미지 주소 할당

	t_vec3	pixel_center;
	t_vec3	pixel_delta_u_mul;
	t_vec3	pixel_delta_v_mul;
	t_vec3	ray_direction;
	t_ray	ray;

	for (int i = 0 ; i < image_height; i++)
	{
		for (int j = 0 ; j < image_width; j++)
		{
			pixel_delta_u_mul = vec3_mul_scal(&pixel_delta_u, i);
			pixel_delta_v_mul = vec3_mul_scal(&pixel_delta_v, j);
			pixel_center = pixel00_loc;
			pixel_center = vec3_add(&pixel00_loc, &pixel_delta_u_mul);
			pixel_center = vec3_add(&pixel00_loc, &pixel_delta_v_mul);
			ray_direction = vec3_sub(&pixel_center, &camera_center);
			ray_init(&ray, &camera_center, &ray_direction);

			color = ray_color(&ray);
			my_mlx_pixel_put(&image, i, j, rgb_to_int(0, &color)); 
		}	
		printf("%f \n", color.y);
	}
	mlx_put_image_to_window(vars.mlx, vars.win, image.img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars); // esc key press event
	mlx_loop(vars.mlx);
	return (0);
}
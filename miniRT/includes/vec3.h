/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:03:25 by jeholee           #+#    #+#             */
/*   Updated: 2024/04/14 22:33:19 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

// (x, y, c)
typedef struct s_vec3{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef t_vec3 t_point3;

void	vec3_init(t_vec3 *vec3, double x, double y, double z);
double	vec3_length(const t_vec3 *vec);
t_vec3	vec3_unit_vec(const t_vec3 *v);

t_vec3	vec3_add(const t_vec3 *a, const t_vec3 *b);
t_vec3	vec3_sub(const t_vec3 *a, const t_vec3 *b);
t_vec3	vec3_mul(const t_vec3 *a, const t_vec3 *b);
t_vec3	vec3_div(const t_vec3 *a, const t_vec3 *b);

t_vec3	vec3_mul_scal(const t_vec3 *vec, const double t);
t_vec3	vec3_div_scal(const t_vec3 *vec, const double t);
double	vec3_dot(const t_vec3 *u, const t_vec3 *v);
t_vec3	vec3_cross(const t_vec3 *u, const t_vec3 *v);

#endif
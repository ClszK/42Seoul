/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:23:53 by jeholee           #+#    #+#             */
/*   Updated: 2024/04/14 22:33:54 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	vec3_init(t_vec3 *vec3, double x, double y, double z)
{
	vec3->x = x;
	vec3->y = y;
	vec3->z = z;
}

double	vec3_length(const t_vec3 *vec)
{
	return (sqrt(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z));
}

t_vec3	vec3_unit_vec(const t_vec3 *v)
{
	return vec3_div_scal(v, vec3_length(v));
}

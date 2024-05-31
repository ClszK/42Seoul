/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 22:21:16 by jeholee           #+#    #+#             */
/*   Updated: 2024/04/14 22:23:52 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

void	color_init(t_color *col, double x, double y, double z)
{
	col->x = x;
	col->y = y;
	col->z = z;
}

int	rgb_to_int(const int t, const t_color *color)
{
	return (t << 24 | \
			(int)(255.999 * color->x) << 16 | \
			(int)(255.999 * color->y) << 8 | \
			(int)(255.999 * color->z));
}
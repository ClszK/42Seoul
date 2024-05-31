/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 22:16:35 by jeholee           #+#    #+#             */
/*   Updated: 2024/04/14 22:23:59 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "vec3.h"

typedef t_vec3 t_color;

void	color_init(t_color *col, double x, double y, double z);
int		rgb_to_int(const int t, const t_color *color);

#endif
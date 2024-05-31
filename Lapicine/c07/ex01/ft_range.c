/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 05:37:57 by jeholee           #+#    #+#             */
/*   Updated: 2023/02/27 22:36:44 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*r_range;
	int	len;
	int	i;

	len = max - min;
	i = -1;
	r_range = (int *)malloc(sizeof(int) * len);
	if (min >= max)
		return (0);
	while (++i < len)
		r_range[i] = min + i;
	return (r_range);
}

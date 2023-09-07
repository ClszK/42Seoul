/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 05:44:47 by jeholee           #+#    #+#             */
/*   Updated: 2023/02/28 03:08:04 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	unsigned int	r_len;
	unsigned int	i;

	if (min >= max)
		return (0);
	i = 0;
	r_len = (unsigned int)(max - min);
	*(range) = (int *)malloc(sizeof(int) * r_len);
	if (*(range) == NULL)
		return (-1);
	while (i < r_len)
		*(*(range) + (i++)) = min++;
	return (r_len);
}

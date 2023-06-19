/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 00:43:37 by jeholee           #+#    #+#             */
/*   Updated: 2023/03/30 01:04:45 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_atoi(const char **s)
{
	size_t	r_num;
	const char	*str;

	r_num = 0;
	str = *s;

	if (*(str) == '.')
		str++;
	while (*(str) >= '0' && *(str) <= '9')
	{
		r_num = r_num * 10 + (*(str) - '0');
		str++;
	}
	*(s) = --str;
	return (r_num);
}

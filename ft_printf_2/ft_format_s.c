/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 08:06:21 by jeholee           #+#    #+#             */
/*   Updated: 2023/07/24 08:11:21 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int	ft_format_s(va_list ap)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)va_arg(ap, char *);
	while (*(str + i))
		i++;
	if (write(1, str, i) < 0)
		return (-1);
	return (i);
}

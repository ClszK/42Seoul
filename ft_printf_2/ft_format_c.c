/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 07:01:47 by jeholee           #+#    #+#             */
/*   Updated: 2023/07/24 07:08:35 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int	ft_format_c(va_list ap)
{
	char	c;

	c = (char)va_arg(ap, int);
	if (write(1, &c, 1) < 0)
		return (-1);
	return (1);
}

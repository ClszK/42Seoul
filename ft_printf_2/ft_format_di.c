/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh <ljh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:22:46 by jeholee           #+#    #+#             */
/*   Updated: 2023/07/28 03:27:27 by ljh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int	ft_format_di(va_list ap)
{
	ssize_t	di_dec;
	char	*int_table;

	int_table = "0123456789";
	di_dec = (ssize_t)va_arg(ap, int);
	if (di_dec < 0)
	{
		if (write(1, "-", 1) < 0)
			return (-1);
		di_dec *= -1;
	}
	return (ft_base_print(di_dec, int_table, 10));
}
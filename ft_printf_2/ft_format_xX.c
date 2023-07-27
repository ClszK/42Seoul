/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_xX.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh <ljh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 03:54:57 by ljh               #+#    #+#             */
/*   Updated: 2023/07/28 04:00:14 by ljh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int ft_format_xX(va_list ap, int xX)
{
	char 	*xX_table;
	ssize_t xX_hex;

	if (xX == 0)
		xX_table = "0123456789abcdef";
	else
		xX_table = "0123456789ABCDEF";
	xX_hex = (ssize_t)va_arg(ap, int);
	return (ft_base_print(xX_hex, xX_table, 16));
}
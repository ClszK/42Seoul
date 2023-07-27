/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh <ljh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 03:26:08 by ljh               #+#    #+#             */
/*   Updated: 2023/07/28 04:01:56 by ljh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int ft_format_u(va_list ap)
{
	char	*int_table;
	size_t	u_dec;

	int_table = "0123456789";
	u_dec = (size_t)va_arg(ap, int);
	return (ft_base_print((size_t)u_dec, int_table, 10));
}
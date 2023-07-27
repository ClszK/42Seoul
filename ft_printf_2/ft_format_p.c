/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh <ljh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 08:13:22 by jeholee           #+#    #+#             */
/*   Updated: 2023/07/28 03:20:02 by ljh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int	ft_format_p(va_list ap)
{
	size_t	ptr_dec;
	char	*hex_table;

	ptr_dec = (size_t)va_arg(ap, void *);
	hex_table = "0123456789abcdef";
	if (write(1, "0x", 2) < 0)
		return (-1);
	return (ft_base_print(ptr_dec, hex_table, 16) + 2);
}

int	ft_base_print(size_t ptr_dec, char *hex_table, int base)
{
	int	len;

	if (ptr_dec == 0)
		return (0);
	len = ft_base_print(ptr_dec / base, hex_table, base);
	if (len >= 0 && write(1, &hex_table[ptr_dec % base], 1) >= 0)
		return (1 + len);
	else
		return (-1);
}
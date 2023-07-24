/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 08:13:22 by jeholee           #+#    #+#             */
/*   Updated: 2023/07/24 10:30:19 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int	ft_format_p(va_list ap, int base)
{
	int		len;
	size_t	ptr_dec;
	char	*hex_table;

	ptr_dec = (size_t)va_arg(ap, void *);
	hex_table = "0123456789abcdef";
	len = ft_base_print(ptr_dec, hex_table, base);
	return (len);
}

int	ft_base_print(size_t ptr_dec, char *hex_table, int base)
{
	int	len;

	if (ptr_dec == 0)
	{
		if (base == 16)
			return (write(1, "0x", 2));
		return (0);
	}
	len = ft_base_print(ptr_dec / base, hex_table, base);
	if (len > 0)
	{
		if (write(1, &hex_table[ptr_dec % base], 1) < 0)
			return (-1);
		return (1 + len);
	}
	else
		return (-1);
}
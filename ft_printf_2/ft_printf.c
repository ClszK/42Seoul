/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh <ljh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 06:47:56 by jeholee           #+#    #+#             */
/*   Updated: 2023/07/28 04:05:15 by ljh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		rsize;
	int		len;

	rsize = 0;
	va_start(ap, format);
	while (*(format))
	{
		if (*(format) == '%')
		{
			len = ft_format(++format, ap);
			if (va_end_error(ap, (ssize_t)len) == -1)
				return (-1);
			rsize += len;
			format++;
			continue ;
		}
		if (va_end_error(ap, write(1, format++, 1)) == -1)
			return (-1);
		rsize++;
	}
	va_end(ap);
	return (rsize);
}

int	va_end_error(va_list ap, ssize_t wsize)
{
	if (wsize < 0)
	{
		va_end(ap);
		return (-1);
	}
	return (1);
}

int	ft_format(const char *format, va_list ap)
{
	int		len;

	len = 0;
	if (*(format) == 'c')
		len = ft_format_c(ap);
	else if (*(format) == 's')
		len = ft_format_s(ap);
	else if (*(format) == 'p')
		len = ft_format_p(ap);
	else if (*(format) == 'd' || *(format) == 'i')
		len = ft_format_di(ap);
	else if (*(format) == 'u')
		len = ft_format_u(ap);
	else if (*(format) == 'x')
		len = ft_format_xX(ap, 0);
	else if (*(format) == 'X')
		len = ft_format_xX(ap, 1);
	else if (*(format) == '%')
	{
		if (write(1, format, 1) < 0)
			return (-1);
		len++;
	}
	else
		return (-1);
	return (len);
}
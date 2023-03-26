/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 21:53:18 by jeholee           #+#    #+#             */
/*   Updated: 2023/03/27 00:19:15 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int	norm_va_end(int ret, va_list ap)
{
	if (ret < 0)
	{
		va_end(ap);
		return (-1);
	}
	return (1);
}

void	flag_table(char *s)
{
	char	*format_flag;

	format_flag = "csppdiuxX%0123456789-.# +";
	(void)ft_memst(s, 0, 128);
	while (*format_flag)
		s[(int)*(format_flag)] = 1;
}

int	ft_format(const char *format, int *len, va_list ap)
{
	if (*(format) == 'c')
		return (ft_print_c(len, ap));
	else if (*(format) == 's')
		return (ft_print_s(len, ap));
	else if (*(format) == 'p')
		return (ft_print_p(len, ap));
	else if (*(format) == 'd' || *(format) == 'i')
		return (ft_print_d_i(len, ap));
	else if (*(format) == 'u')
		return (ft_print_u(len, ap));
	else if (*(format) == 'x')
		return (ft_print_low_x(len, ap));
	else if (*(format) == 'X')
		return (ft_print_up_x(len, ap));
	else if (*(format) == '%')
	{
		if (write(1, "%", 1) < 0)
			return (-1);
		++(*len);
	}
	else
		return (-1);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;
	char	ascii_table[128];

	len = 0;
	va_start(ap, format);
	while (*(format))
	{
		if (*(format) != '%')
		{
			++len;
			if (norm_va_end(write(1, format, 1), ap) < 0)
				return (-1);
		}
		else
		{
			if (norm_va_end(ft_format(++format, &len, ap), ap) < 0)
				return (-1);
		}
		++format;
	}
	va_end(ap);
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 21:53:18 by jeholee           #+#    #+#             */
/*   Updated: 2023/03/30 01:10:29 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include "./includes/libft.h"

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

	format_flag = "0#-+ .cspdiuxX%0123456789";
	(void)ft_memset(s, 0, 128);
	while (*format_flag)
		s[(int)*(format_flag++)] = 1;
}

void	flag_set(const char **format, char *table, size_t *flag)
{
	while (table[(int)**format])
	{
		if (**format == '0')
			flag[ZERO] = 1;
		else if (**format == '#')
			flag[SHARP] = 1;
		else if (**format == '-')
			flag[MINUS] = 1;
		else if (**format == '+')
			flag[PLUS] = 1;
		else if (**format == ' ')
			flag[SPACE] = 1;
		else if (ft_isdigit(**format))
			flag[WIDTH] = ft_atoi(format);
		else if (**format == '.')
		{
			flag[POINT] = 1;
			flag[PERCISION] = ft_atoi(format);
		}
		else if (ft_isalpha(**format))
			return ;
		++*format;
	}
}

const char	*flag_wid_per(const char *format, char *table, int *len, va_list ap)
{
	size_t	flag[8];

	ft_bzero(flag, 8 * sizeof(size_t));
	flag_set(&format, table, flag);
	ft_format(format, len, ap, flag);

	return (format);
}

int	ft_format(const char *format, int *len, va_list ap, size_t *flag)
{
	if (*(format) == 'c')
		return (ft_print_char(len, ap, flag));
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
	else
	{
		if (write(1, format, 1) < 0)
			return (-1);
		++(*len);
	}

	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;
	char	table[128];

	len = 0;
	va_start(ap, format);
	flag_table(table);
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
			format = flag_wid_per(++format, table, &len, ap);
		}
		++format;
	}
	va_end(ap);
	return (len);
}

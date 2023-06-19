/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 04:07:33 by jeholee           #+#    #+#             */
/*   Updated: 2023/03/30 01:12:55 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define ZERO		0
# define SHARP		1
# define MINUS		2
# define PLUS		3
# define SPACE		4
# define WIDTH		5
# define PERCISION	6
# define POINT		7

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_format(const char *format, int *len, va_list ap, size_t *flag);
int		ft_print_char(int *len, va_list ap, size_t *flag);
int		ft_print_s(int *len, va_list ap);
int		ft_print_p(int *len, va_list ap);
int		ft_print_d_i(int *len, va_list ap);
int		ft_print_u(int *len, va_list ap);
int		ft_print_low_x(int *len, va_list ap);
int		ft_print_up_x(int *len, va_list ap);
int		ft_putnbr_base(int nb, char *base, int *len);

int		addr_print(void *addr, int *len);

#endif
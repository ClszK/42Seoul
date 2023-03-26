/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 04:07:33 by jeholee           #+#    #+#             */
/*   Updated: 2023/03/26 23:08:36 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_format(const char *format, int *len, va_list ap);
int		ft_print_c(int *len, va_list ap);
int		ft_print_s(int *len, va_list ap);
int		ft_print_p(int *len, va_list ap);
int		ft_print_d_i(int *len, va_list ap);
int		ft_print_u(int *len, va_list ap);
int		ft_print_low_x(int *len, va_list ap);
int		ft_print_up_x(int *len, va_list ap);
int		ft_putnbr_base(int nb, char *base, int *len);

int		addr_print(void *addr, int *len);

#endif
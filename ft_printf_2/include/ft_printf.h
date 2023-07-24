/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 06:27:23 by jeholee           #+#    #+#             */
/*   Updated: 2023/07/24 10:29:29 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_format(const char *format, va_list ap);
int	va_end_error(va_list ap, ssize_t wsize);

int	ft_format_c(va_list ap);
int	ft_format_s(va_list ap);
int	ft_format_p(va_list ap, int base);
int	ft_format_di(va_list ap);
int	ft_format_u(va_list ap);
int	ft_format_xX(va_list ap);

int	ft_base_print(size_t ptr_dec, char *hex_table, int base);

#endif
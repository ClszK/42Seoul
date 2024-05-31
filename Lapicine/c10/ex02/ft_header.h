/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 03:56:19 by jeholee           #+#    #+#             */
/*   Updated: 2023/03/02 12:39:24 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEADER_H
# define FT_HEADER_H

# include <sys/errno.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <libgen.h>
# include <stdlib.h>

void	ft_putstr(char *str);
void	ft_putchar(char c);
int		ft_strlen(char *str);
int		ft_n_print(int fd, int n);
void	ft_error_print(char **argv, int i);
void	ft_error_illegal_option(char **argv);
char	*ft_whitespace(char *str);
int		ft_atoi(char *str);
int		ft_str_is_numeric(char *str);

#endif 
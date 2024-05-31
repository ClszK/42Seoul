/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 03:56:19 by jeholee           #+#    #+#             */
/*   Updated: 2023/03/02 10:11:10 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEADER_H
# define FT_HEADER_H

# include <sys/errno.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <libgen.h>

void	ft_putstr(char *str);
void	ft_putchar(char c);
int		ft_strlen(char *str);
int		ft_print_file(int fd);
void	ft_error_print(char **argv, int i);

#endif 
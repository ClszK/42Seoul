/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 01:33:27 by jeholee           #+#    #+#             */
/*   Updated: 2023/03/02 05:14:37 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <fcntl.h>
# include <unistd.h>

void	ft_putstr(char *str);
void	ft_putchar(char c);
int		ft_strlen(char *str);
void	ft_print_file(int fd);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:40:14 by jeholee           #+#    #+#             */
/*   Updated: 2023/03/02 06:00:04 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

void	ft_putstr(char *str)
{
	while (*(str))
		write(1, str++, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str++))
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_print_file(int fd)
{
	char	c;
	int		r_read;

	r_read = read(fd, &c, 1);
	if (r_read < 0)
		return (-1);
	while (r_read > 0)
	{	
		ft_putchar(c);
		r_read = read(fd, &c, 1);
	}
	return (0);
}

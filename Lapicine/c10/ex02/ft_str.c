/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:40:14 by jeholee           #+#    #+#             */
/*   Updated: 2023/03/02 09:39:00 by jeholee          ###   ########.fr       */
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

int	ft_n_print(int fd, int n)
{
	char	*buf;
	int		r_read;

	buf = (char *)malloc(sizeof(char) * n);
	r_read = read(fd, buf, n);
	if (r_read < 0)
		return (-1);
	while (r_read > 0)
	{	
		r_read = read(fd, buf, n);
	}
	ft_putstr(buf);
	return (0);
}

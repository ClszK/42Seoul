/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <dlwpgns0@student.42seoul.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 01:20:48 by jeholee           #+#    #+#             */
/*   Updated: 2023/02/17 04:14:41 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	*hex_table;
	int		stack[11];
	int		top;

	hex_table = "0123456789";
	top = -1;
	if (nb == 0)
		write(1, "0", 1);
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	while (nb)
	{
		stack[++top] = (unsigned int)nb % 10;
		nb = (unsigned int)nb / 10;
	}
	while (top > -1)
		write(1, &hex_table[stack[top--]], 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:40:14 by jeholee           #+#    #+#             */
/*   Updated: 2023/03/02 12:21:44 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*(str))
		write(1, str++, 1);
}

void	recur(long long n)
{
	char	ch;

	ch = '0';
	if (n < 10)
	{
		ch += n;
		write(1, &ch, 1);
	}
	else
	{
		recur(n / 10);
		ch += n % 10;
		write(1, &ch, 1);
	}
}

void	ft_putnbr(int nb)
{
	long long	n;

	n = nb;
	if (nb < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	recur(n);
}

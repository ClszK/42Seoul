/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:26:29 by jeholee           #+#    #+#             */
/*   Updated: 2023/02/09 11:19:03 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

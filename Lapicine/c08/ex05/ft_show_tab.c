/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:06:30 by jeholee           #+#    #+#             */
/*   Updated: 2023/02/28 23:28:00 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
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

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par->str)
	{
		ft_putstr(par->str);
		write(1, "\n", 1);
		ft_putnbr(par->size);
		write(1, "\n", 1);
		ft_putstr(par->copy);
		write(1, "\n", 1);
		par++;
	}
}

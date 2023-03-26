/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 04:45:12 by jeholee           #+#    #+#             */
/*   Updated: 2023/02/20 06:27:20 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str++))
		i++;
	return (i);
}

int	is_base(char *base)
{
	int		base_len;
	char	*base_j;

	base_len = 0;
	while (*(base))
	{
		if (*(base) == '-' || *(base) == '+')
			return (0);
		base_j = base + 1;
		while (*(base_j))
			if (*(base) == *(base_j++))
				return (0);
		base++;
		base_len++;
	}
	if (base_len <= 1)
		return (0);
	return (1);
}

int	num_sign(int nb)
{	
	if (nb < 0)
	{
		write(1, "-", 1);
		return (-1);
	}
	return (1);
}

void	ft_putnbr_base(int nb, char *base)
{
	int	base_len;
	int	stack[33];
	int	top;
	int	sign;

	base_len = ft_strlen(base);
	top = -1;
	if (!is_base(base))
		return ;
	sign = num_sign(nb);
	nb *= sign;
	if (nb == 0)
		write(1, &base[0], 1);
	while (nb)
	{
		stack[++top] = (int)((unsigned int)nb % base_len);
		nb = (int)((unsigned int)nb / base_len);
	}
	while (top > -1)
		write(1, &base[stack[top--]], 1);
}

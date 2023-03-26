/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 00:55:06 by jeholee           #+#    #+#             */
/*   Updated: 2023/02/28 03:08:30 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_whitespace(char str);
int	ft_strlen(char *str);

int	is_base(char *base)
{
	int		base_len;
	char	*base_j;

	base_len = 0;
	while (*(base))
	{
		if (*(base) == '-' || *(base) == '+'
			|| ft_is_whitespace(*(base)))
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

int	find_index(char *base, char ch)
{
	int	index;

	index = 0;
	while (*(base + index))
	{
		if (*(base + index) == ch)
			return (index);
		index++;
	}
	return (-1);
}

int	ft_atoi_base(char *nbr, char *base_from, int base_len)
{
	int	sign;
	int	r_num;
	int	f_index;

	sign = 1;
	r_num = 0;
	while (ft_is_whitespace(*(nbr)))
		nbr++;
	while (*(nbr) == '-' || *(nbr) == '+')
		if (*(nbr++) == '-')
			sign *= -1;
	while (*(nbr))
	{
		f_index = find_index(base_from, *(nbr++));
		if (f_index == -1)
			break ;
		r_num = r_num * base_len + f_index;
	}
	return (r_num * sign);
}

char	*ft_putnbr_base(int nb_i, char *base_to, int base_len, int sign)
{
	int		stack[33];
	int		top;
	char	*nbr;

	top = -1;
	if (nb_i == 0)
		stack[++top] = 0;
	if (nb_i < 0)
	{
		nb_i *= -1;
		sign = -1;
	}
	while (nb_i)
	{
		stack[++top] = (int)((unsigned int)nb_i % base_len);
		nb_i = (int)((unsigned int)nb_i / base_len);
	}
	nbr = (char *)malloc(sizeof(char) * (top + 3));
	if (sign == -1)
		*(nbr + (nb_i++)) = '-';
	while (top > -1)
		*(nbr + (nb_i++)) = base_to[stack[top--]];
	*(nbr + nb_i) = '\0';
	return (nbr);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		r_nbr;
	char	*str;

	if (!is_base(base_from) || !is_base(base_to))
		return (NULL);
	r_nbr = ft_atoi_base(nbr, base_from, ft_strlen(base_from));
	str = ft_putnbr_base(r_nbr, base_to, ft_strlen(base_to), 1);
	return (str);
}

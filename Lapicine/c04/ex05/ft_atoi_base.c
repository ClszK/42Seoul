/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 22:56:24 by jeholee           #+#    #+#             */
/*   Updated: 2023/02/21 16:57:31 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str++))
		i++;
	return (i);
}

int	ft_is_whitespace(char str)
{
	if ((str >= 9 && str <= 13) || str == 32)
		return (1);
	return (0);
}

int	is_base(char *base)
{
	int		base_len;
	char	*base_j;

	base_len = 0;
	while (*(base))
	{
		if (*(base) == '-' || *(base) == '+' || ft_is_whitespace(*(base)))
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

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	r_num;
	int	base_len;
	int	f_index;

	sign = 1;
	r_num = 0;
	if (!is_base(base))
		return (0);
	base_len = ft_strlen(base);
	while (ft_is_whitespace(*(str)))
		str++;
	while (*(str) == '-' || *(str) == '+')
		if (*(str++) == '-')
			sign *= -1;
	while (*(str))
	{
		f_index = find_index(base, *(str++));
		if (f_index == -1)
			break ;
		r_num = r_num * base_len + f_index;
	}
	return (r_num * sign);
}

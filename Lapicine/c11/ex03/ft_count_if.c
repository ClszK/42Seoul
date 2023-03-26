/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 21:03:59 by jeholee           #+#    #+#             */
/*   Updated: 2023/03/02 07:33:22 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (i < length)
	{
		if (f(tab[i++]))
			cnt++;
	}
	return (cnt);
}

/*#include <stdio.h>

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

int main()
{
	char *a[4];

	a[0] = "01234+";
	a[1] = "01-";
	a[2] = "123";
	a[3] = "1234";
	printf("%d", ft_count_if(a, 4, &is_base));
	return 0;
}*/
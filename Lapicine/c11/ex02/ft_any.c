/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:38:53 by jeholee           #+#    #+#             */
/*   Updated: 2023/03/02 07:33:04 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f)(char *))
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (f(tab[i++]))
			return (1);
	}
	return (0);
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
	a[3] = 0;
	printf("%d", ft_any(a, &is_base));
	return 0;
}*/
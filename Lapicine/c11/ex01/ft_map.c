/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:32:51 by jeholee           #+#    #+#             */
/*   Updated: 2023/03/02 07:32:16 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*r_tab;

	i = -1;
	if (length <= 0)
		return (0);
	r_tab = (int *)malloc(sizeof(int) * length);
	while (++i < length)
		r_tab[i] = f(tab[i]);
	return (r_tab);
}

/*int test(int a)
{
	return a * a;
}

#include <stdio.h>

int main()
{
	int a[5] = {1,2,3,4,5};
	int *b;
	b = ft_map(a, 5, &test);
	for (int i= 0 ; i< 5; i++)
		printf("%d ", b[i]);
	return 0;
}*/

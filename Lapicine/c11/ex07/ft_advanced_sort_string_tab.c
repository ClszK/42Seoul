/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 01:06:03 by jeholee           #+#    #+#             */
/*   Updated: 2023/03/02 11:12:05 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
		i++;
	while ((--i) > 0)
	{
		j = 0;
		while (j < i)
		{
			if (cmp(tab[j], tab[j + 1]) > 0)
				ft_swap(&tab[j], &tab[j + 1]);
			j++;
		}
	}
}

/*#include <stdio.h>

int	main(int argc, char *argv[])
{
	int	i;

	i = argc - 1;
	argv[argc] = 0;
	ft_advanced_sort_string_tab(argv, &ft_strcmp);
	for(i = 0; argv[i] ; i++)
		printf("%s\n", argv[i]);
	return (0);
}
*/
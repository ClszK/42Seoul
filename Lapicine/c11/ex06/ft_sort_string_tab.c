/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 22:51:18 by jeholee           #+#    #+#             */
/*   Updated: 2023/03/02 07:35:02 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*(s1) || *(s2))
	{
		if (*(s1) != *(s2))
			return (*(s1) - *(s2));
		s1++;
		s2++;
	}
	return (0);
}

void	ft_sort_string_tab(char **tab)
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
			if (ft_strcmp(tab[j], tab[j + 1]) > 0)
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
	ft_sort_string_tab(argv);
	for(i = 0; argv[i] ; i++)
		printf("%s\n", argv[i]);
	return (0);
}
*/
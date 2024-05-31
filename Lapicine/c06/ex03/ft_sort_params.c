/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:57:17 by jeholee           #+#    #+#             */
/*   Updated: 2023/02/22 05:34:31 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_print_str(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		while (*(argv[i]))
			write(1, (argv[i]++), 1);
		write(1, "\n", 1);
		i++;
	}
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

void	ft_sort_params(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 2;
	while (i < argc)
	{
		j = i;
		while (j >= 2)
		{
			if (ft_strcmp(argv[j - 1], argv[j]) > 0)
				ft_swap(&argv[j - 1], &argv[j]);
			j--;
		}
		i++;
	}
	ft_print_str(argc, argv);
}

int	main(int argc, char *argv[])
{
	int	i;

	i = argc - 1;
	ft_sort_params(argc, argv);
	return (0);
}

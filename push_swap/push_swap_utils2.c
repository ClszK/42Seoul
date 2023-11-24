/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:02:53 by jeholee           #+#    #+#             */
/*   Updated: 2023/11/02 01:06:41 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_print(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	split_free(char **str_split)
{
	int	i;

	i = 0;
	while (str_split[++i])
		free(str_split[i]);
	free(str_split);
}

void	empty_argv(int argc, char *argv[])
{
	int	i;
	int	j;
	int	flag;

	i = 1;
	while (i < argc)
	{
		j = 0;
		flag = 0;
		while (argv[i][j])
		{
			if (argv[i][j] != ' ')
				flag = 1;
			j++;
		}
		if (flag == 0)
			error_print();
		i++;
	}
}

char	*join_argv(int argc, char *argv[])
{
	char	*tmp;
	char	*str;
	int		i;

	i = 1;
	str = first_argv_dup(argv);
	if (str == NULL)
		return (NULL);
	while (i < argc - 1)
	{
		tmp = str;
		str = ft_strjoin(str, " ");
		free(tmp);
		if (str == NULL)
			return (NULL);
		tmp = str;
		str = ft_strjoin(str, argv[i + 1]);
		free(tmp);
		if (str == NULL)
			return (NULL);
		i++;
	}
	return (str);
}

void	cmp_pos(int i, int *j, int *k, char **str_split)
{
	*k = 0;
	*j = 0;
	if ((str_split[i][*k] == '+' || str_split[i][*k] == '-') && \
		str_split[i][*k + 1] == '0')
	{
		*j += 1;
		*k += 1;
	}
	while (str_split[i][*k + 1])
	{
		if (str_split[i][*k] == '0')
			*k += 1;
		else
			break ;
	}
	if (str_split[i][0] == '+')
		*k += 1;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 17:50:47 by ljh               #+#    #+#             */
/*   Updated: 2023/11/02 01:58:20 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strcat(char *dest, char *src);
void	is_asend_dupli(int *num_arr, int size);

int	validation_check(char **str_split, int *num_arr)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	i = 0;
	while (str_split[i])
	{
		num_arr[i] = ft_atoi(str_split[i]);
		str = ft_itoa(num_arr[i]);
		if (str == NULL)
		{
			split_free(str_split);
			return (-1);
		}
		cmp_pos(i, &j, &k, str_split);
		if (ft_strcmp(str, str_split[i]) && \
			ft_strcmp(str + j, str_split[i] + k))
		{
			error_print();
		}
		free(str);
		i++;
	}
	return (1);
}

int	*split_in_num_arr(char *str, int *size)
{
	int		i;
	char	**str_split;
	int		*num_arr;

	i = 0;
	str_split = ft_split(str, ' ');
	free(str);
	if (str_split == NULL)
		return (NULL);
	while (str_split[i])
		i++;
	*size = i;
	num_arr = (int *)malloc(sizeof(int) * (i));
	if (num_arr == NULL)
		exit(1);
	if (validation_check(str_split, num_arr) < 0)
		exit(1);
	i = -1;
	while (str_split[++i])
		free(str_split[i]);
	free(str_split);
	return (num_arr);
}

void	sort_stack(t_stackset *stack, int *num_arr, int size)
{
	int	i;

	i = size;
	while (i--)
	{
		if (!ft_push(&stack->a, num_arr[i]))
			exit(1);
	}
	ft_sort_int_tab(num_arr, size);
	stack->max = num_arr[size - 1];
	if (ft_size(&stack->a) <= 3)
	{
		hard_coding(stack);
		return ;
	}
	else
		partition(stack, size - 1, size - 1, num_arr);
	i = 0;
	while (i <= size)
	{
		greedy(stack);
		i++;
	}
	last_sort(&stack->a, num_arr[size - 1]);
}

int	main(int argc, char *argv[])
{
	t_stackset	stack;
	int			*num_arr;
	int			size;

	if (argc < 2)
		return (-1);
	empty_argv(argc, argv);
	num_arr = split_in_num_arr(join_argv(argc, argv), &size);
	if (num_arr == NULL)
		exit(1);
	is_asend_dupli(num_arr, size);
	ft_stackset_init(&stack);
	sort_stack(&stack, num_arr, size);
	free(num_arr);
	dlst_del_all(stack.a.head, free);
	dlst_del_all(stack.b.head, free);
	return (0);
}

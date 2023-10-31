/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh <ljh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 17:50:47 by ljh               #+#    #+#             */
/*   Updated: 2023/10/31 15:46:13 by ljh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_leak(void)
{
	system("leaks --list push_swap");
}

char	*ft_strcat(char *dest, char *src);
void	is_asend_dupli(int *num_arr, int size);

void	error_print(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	empty_argv(int argc, char *argv[])
{
	int	i;
	int	j;
	int	flag;

	i = 1;
	flag = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] != ' ')
				flag = 1;
			j++;
		}
		i++;
	}
	if (flag == 0)
	{
		error_print();
	}
}

char	*first_argv_dup(char *argv[])
{
	char	*str;

	str = ft_strdup(argv[1]);
	if (str == NULL)
		return (NULL);
	if (ft_strcmp(str, "") == 0)
		error_print();
	return (str);
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

int	validation_check(char **str_split, int *num_arr)
{
	char	*str;
	int		i;

	i = 0;
	while (str_split[i])
	{
		num_arr[i] = ft_atoi(str_split[i]);
		str = ft_itoa(num_arr[i]);
		if (str == NULL)
		{
			i = 0;
			while (str_split[++i])
				free(str_split[i]);
			free(str_split);
			return (-1);
		}
		if (ft_strcmp(str, str_split[i]))
			error_print();
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
		return (NULL);
	if (validation_check(str_split, num_arr) < 0)
		return (NULL);
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
	while(i <= size)
	{
		greedy(stack);
		i++;
	}
	last_sort(&stack->a, num_arr[size - 1]);
}

int main(int argc, char *argv[])
{
	t_stackset	stack;
	int			*num_arr;
	char		*str;
	int			size;

	if (argc < 2)
        return (-1);
	empty_argv(argc, argv);
	str = join_argv(argc, argv);
	num_arr = split_in_num_arr(str, &size);
	is_asend_dupli(num_arr, size);
	ft_stackset_init(&stack);
	sort_stack(&stack, num_arr, size);
	exit(0);
    return (0);
}

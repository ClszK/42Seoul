/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:20:02 by ljh               #+#    #+#             */
/*   Updated: 2023/11/01 21:39:21 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = size;
	while ((--i) > 0)
	{
		j = 0;
		while (j < i)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
	}
}

void	sort_two(t_stackset *stack)
{
	if (*(int *)stack->a.top->elem > *(int *)stack->a.top->prev->elem)
		ft_swap(&stack->a, 'a');
}

void	sort_three(t_stack *a)
{
	t_node	*node;
	int		max;

	max = -2147483648;
	node = a->top;
	while (node != a->head)
	{
		if (max < *(int *)node->elem)
			max = *(int *)node->elem;
		node = node->prev;
	}
	if (max == *(int *)a->top->elem)
		ft_rotate(a, 'a');
	else if (max == *(int *)a->top->prev->elem)
		ft_rev_rotate(a, 'a');
	if (*(int *)a->top->elem > *(int *)a->top->prev->elem)
		ft_swap(a, 'a');
}

void	last_sort(t_stack *a, int max)
{
	t_node	*node;
	int		cnt;

	node = a->top;
	cnt = 0;
	while (node->elem)
	{
		if (*(int *)node->elem == max)
			break ;
		cnt++;
		node = node->prev;
	}
	if (cnt + 1 < ft_size(a) - cnt)
	{
		cnt++;
		while (cnt--)
			ft_rotate(a, 'a');
	}
	else
	{
		cnt = ft_size(a) - cnt - 1;
		while (cnt--)
			ft_rev_rotate(a, 'a');
	}
}

void	hard_coding(t_stackset *stack)
{
	if (ft_size(&stack->a) == 1)
		return ;
	if (ft_size(&stack->a) == 2)
		sort_two(stack);
	else if (ft_size(&stack->a) == 3)
		sort_three(&stack->a);
}

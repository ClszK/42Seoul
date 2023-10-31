/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh <ljh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:22:43 by ljh               #+#    #+#             */
/*   Updated: 2023/10/29 17:30:06 by ljh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	greedy(t_stackset *stack)
{
	t_node		*node;
	t_cmd		min_cmd;
	int			pos;

	command_init(&min_cmd);
	node = stack->b.top;
	pos = 0;
	while (node->elem)
	{
		min_command(stack, node, &min_cmd, pos);
		pos++;
		if (min_cmd.total == 1)
			break ;
		node = node->prev;
	}
	command_excute(&stack->a, &stack->b, &min_cmd);
}

void	partition(t_stackset *stack, int size, int end, int *num_arr)
{
	while (size-- > 0 && ft_size(&stack->a) > 3)
	{
		if (*(int *)stack->a.top->elem <= num_arr[end / 3 * 2])
		{
			ft_push_other(&stack->a, &stack->b, 'b');
			if (ft_size(&stack->b) > 1 &&
				*(int *)stack->b.top->elem < num_arr[end / 3])
			{
				if (*(int *)stack->a.top->elem <= num_arr[end / 3] || 
					*(int *)stack->a.top->elem <= num_arr[end / 3 * 2])
					ft_rotate(&stack->b, 'b');
				else
				{
					size--;
					ft_rr(&stack->a, &stack->b);
				}
			}
		}
		else
			ft_rotate(&stack->a, 'a');
	}
	remain_push(stack, num_arr, end);
}

void	remain_push(t_stackset *stack, int *num_arr, int end)
{
	t_stack	*a;
	t_stack *b;

	a = &stack->a;
	b = &stack->b;
	while (ft_size(a) > 3)
		{
			if (*(int *)a->top->elem == num_arr[end] ||
				*(int *)a->top->elem == num_arr[end - 1] ||
				*(int *)a->top->elem == num_arr[end - 2])
				ft_rotate(a, 'a');
			else
				ft_push_other(a, b,'b');
		}
	hard_coding(stack);
}
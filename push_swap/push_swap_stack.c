/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh <ljh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:12:22 by ljh               #+#    #+#             */
/*   Updated: 2023/10/29 17:17:02 by ljh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stackset_init(t_stackset *stack)
{
	if (ft_stack_init(&stack->a) < 0 || ft_stack_init(&stack->b) < 0)
		exit(1);
}

int	ft_stack_init(t_stack *stack)
{
	if (dlst_init(&stack->head, &stack->tail) < 0)
		return (-1);
	stack->top = stack->head;
	return (1);
}

int	ft_push(t_stack *stack, int num)
{
	void	*elem;

	elem = ft_elem_generate(num);
	if (elem == NULL)
		return (-1);
	if (dlst_add_last(stack->tail, elem) < 0)
		return (-1);
	stack->top = stack->top->next;
	return (1);
}

int ft_pop(t_stack *stack)
{
	int	num;

	num = ft_peek(stack);
	stack->top = stack->top->prev;
	dlst_del_last(stack->tail, free);
	return (num);
}

int	ft_size(t_stack *stack)
{
	t_node	*node;
	int		size;

	size = 0;
	node = stack->head->next;
	while (node->next)
	{
		size++;
		node = node->next;
	}
	return (size);
}
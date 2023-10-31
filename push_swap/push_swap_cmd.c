/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh <ljh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:17:37 by ljh               #+#    #+#             */
/*   Updated: 2023/10/29 17:30:10 by ljh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_swap(t_stack *stack, char a_or_b)
{
	void	*tmp;
	t_node	*last_node;

	if (ft_size(stack) < 2)
		return ;
	last_node = stack->tail->prev;
	tmp = last_node->elem;
	last_node->elem = last_node->prev->elem;
	last_node->prev->elem = tmp;
	if (a_or_b == 'a')
		ft_printf("sa\n");
	else if (a_or_b == 'b')
		ft_printf("sb\n");
}

void    ft_rotate(t_stack *stack, char a_or_b)
{
	t_node	*node;
	t_node	*head;
	t_node	*tail;

	if (ft_size(stack) <= 1)
		return ;
	head = stack->head;
	tail = stack->tail;
	node = tail->prev;
	node->prev->next = tail;
	tail->prev = node->prev;
	node->next = head->next;
	head->next->prev = node;
	node->prev = head;
	head->next = node;
	stack->top = stack->tail->prev;
	if (a_or_b == 'a')
		ft_printf("ra\n");
	else if (a_or_b == 'b')
		ft_printf("rb\n");
}

void	ft_rev_rotate(t_stack *stack, char a_or_b)
{
	t_node	*node;
	t_node	*head;
	t_node	*tail;

	if (ft_size(stack) <= 1)
		return ;
	head = stack->head;
	tail = stack->tail;
	node = head->next;
	head->next = node->next;
	node->next->prev = head;
	tail->prev->next = node;
	node->prev = tail->prev;
	tail->prev = node;
	node->next = tail;
	stack->top = stack->tail->prev;
	if (a_or_b == 'a')
		ft_printf("rra\n");
	else if (a_or_b == 'b')
		ft_printf("rrb\n");
}

int	ft_push_other(t_stack *src, t_stack *des, char a_or_b)
{
	int	num;

	if (ft_size(src) == 0)
		return (0);
	num = ft_pop(src);
	if (ft_push(des, num) < 0)
		return (-1);
	if (a_or_b == 'a')
		ft_printf("pa\n");
	else if (a_or_b == 'b')
		ft_printf("pb\n");
	return (1);
}

void	ft_ss(t_stack *a, t_stack *b)
{
	ft_swap(a, '1');
	ft_swap(b, '1');
	ft_printf("ss\n");
}
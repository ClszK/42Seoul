/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh <ljh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:15:01 by ljh               #+#    #+#             */
/*   Updated: 2023/10/29 17:17:00 by ljh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_peek(t_stack *stack)
{
	return (*(int *)(stack->top->elem));
}

int ft_is_empty(t_stack *stack)
{
	if (ft_size(stack) == 0)
		return (1);
	return (0);
}

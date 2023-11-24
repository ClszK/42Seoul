/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cmd2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh <ljh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:18:41 by ljh               #+#    #+#             */
/*   Updated: 2023/10/29 17:30:09 by ljh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rr(t_stack *a, t_stack *b)
{
	ft_rotate(a, '1');
	ft_rotate(b, '1');
	ft_printf("rr\n");
}

void	ft_rrr(t_stack *a, t_stack *b)
{
	ft_rev_rotate(a, '1');
	ft_rev_rotate(b, '1');
	ft_printf("rrr\n");
}

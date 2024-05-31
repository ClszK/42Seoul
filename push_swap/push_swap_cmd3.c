/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cmd3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:24:00 by ljh               #+#    #+#             */
/*   Updated: 2023/11/01 21:38:47 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	command_total(t_cmd *cmd)
{
	cmd->total = 0;
	while (cmd->ra && cmd->rb)
	{
		cmd->ra--;
		cmd->rb--;
		cmd->rr++;
	}
	while (cmd->rra && cmd->rrb)
	{
		cmd->rra--;
		cmd->rrb--;
		cmd->rrr++;
	}
	cmd->total += cmd->pa;
	cmd->total += cmd->pb;
	cmd->total += cmd->ra;
	cmd->total += cmd->rb;
	cmd->total += cmd->rr;
	cmd->total += cmd->rra;
	cmd->total += cmd->rrb;
	cmd->total += cmd->rrr;
}

void	command_init(t_cmd *cmd)
{
	cmd->pa = 0;
	cmd->pb = 0;
	cmd->ra = 0;
	cmd->rb = 0;
	cmd->rr = 0;
	cmd->rra = 0;
	cmd->rrb = 0;
	cmd->rrr = 0;
	cmd->total = 2147483647;
}

void	command_excute(t_stack *a, t_stack *b, t_cmd *cmd)
{
	int	flag;

	flag = 0;
	if (cmd->rra > 1)
		flag = 1;
	while (cmd->rr--)
		ft_rr(a, b);
	while (cmd->rrr--)
		ft_rrr(a, b);
	while (cmd->rb--)
		ft_rotate(b, 'b');
	while (cmd->rrb--)
		ft_rev_rotate(b, 'b');
	while (cmd->ra--)
		ft_rotate(a, 'a');
	while (cmd->rra--)
		ft_rev_rotate(a, 'a');
	ft_push_other(b, a, 'a');
	if (flag == 1)
		ft_rotate(a, 'a');
}

void	find_pos(t_stack *a, int max, int val, int *pos)
{
	t_node	*cmp_node;
	t_node	*a_node;

	a_node = a->top;
	while (a_node->elem)
	{
		if (*(int *)a_node->elem > val)
		{
			if (a_node->next->elem == NULL)
				cmp_node = a->head->next;
			else
				cmp_node = a_node->next;
			if (*(int *)cmp_node->elem < val || \
				*(int *)cmp_node->elem == max)
				break ;
		}
		*pos += 1;
		a_node = a_node->prev;
	}
}

void	min_command(t_stackset *stack, t_node *b_node, t_cmd *min_cmd, int pos)
{
	t_node		*a_node;
	t_cmd		cmd;
	int			val;

	command_init(&cmd);
	a_node = stack->a.top;
	val = *(int *)b_node->elem;
	if (pos < ft_size(&stack->b) - pos + 1)
		cmd.rb = pos;
	else
		cmd.rrb = ft_size(&stack->b) - pos;
	cmd.pa += 1;
	pos = 0;
	find_pos(&stack->a, stack->max, val, &pos);
	if (pos < ft_size(&stack->a) - pos)
		cmd.ra = pos;
	else
		cmd.rra = ft_size(&stack->a) - pos;
	command_total(&cmd);
	if (cmd.total < min_cmd->total)
		*min_cmd = cmd;
}

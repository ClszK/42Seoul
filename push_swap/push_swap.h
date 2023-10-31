/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh <ljh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 17:37:55 by ljh               #+#    #+#             */
/*   Updated: 2023/10/31 12:25:38 by ljh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "double_lst.h"
# include "stdio.h"

typedef struct s_stack
{
    t_node  *head;
    t_node  *tail;
    t_node  *top;
}   t_stack;

typedef struct s_stackset
{
    t_stack a;
    t_stack b;
    int     max;
}   t_stackset;

typedef struct s_cmd
{
    int pa;
    int pb;
    int ra;
    int rb;
    int rr;
    int rra;
    int rrb;
    int rrr;
    int total;
}   t_cmd;


void	error_print(void);
void	ft_stackset_init(t_stackset *stack);
void	ft_sort_int_tab(int *tab, int size);
int		ft_stack_init(t_stack *stack);
int		ft_push(t_stack *stack, int num);
int 	ft_pop(t_stack *stack);
int     ft_isnum(char *str);
int     ft_peek(t_stack *stack);
int		ft_size(t_stack *stack);
int     ft_is_empty(t_stack *stack);
void    ft_swap(t_stack *stack, char a_or_b);
void    *ft_elem_generate(int num);
int		ft_push(t_stack *stack, int num);
void    ft_rotate(t_stack *stack, char a_or_b);
void	ft_rev_rotate(t_stack *stack, char a_or_b);
void	ft_rr(t_stack *a, t_stack *b);
void    ft_rrr(t_stack *a, t_stack *b);
int		ft_push_other(t_stack *src, t_stack *des, char a_or_b);
void	command_init(t_cmd *cmd);
void	command_total(t_cmd *cmd);
void	greedy(t_stackset *stack);
void	partition(t_stackset *stack, int size, int end, int *num_arr);
void	command_excute(t_stack *a, t_stack *b, t_cmd *cmd);
void	sort_two(t_stackset *stack);
void	sort_three(t_stack *a);
void	last_sort(t_stack *a, int max);
void	hard_coding(t_stackset *stack);
void	remain_push(t_stackset *stack, int *num_arr, int end);
void	min_command(t_stackset *stack, t_node *b_node, t_cmd *min_cmd, int pos);

#endif

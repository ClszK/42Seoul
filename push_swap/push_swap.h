/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh <ljh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 17:37:55 by ljh               #+#    #+#             */
/*   Updated: 2023/10/16 03:19:23 by ljh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "double_lst.h"

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
    int     sort_cnt;
}   t_stackset;


typedef struct s_pivot
{
    int *sort_arr;
    int start;
    int end;
}   t_pivot;

#endif

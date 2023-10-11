/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh <ljh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 17:37:55 by ljh               #+#    #+#             */
/*   Updated: 2023/10/10 22:18:23 by ljh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "double_lst.h"

typedef struct s_stack
{
    t_dlst  *head;
    t_dlst  *tail;
    t_dlst  *top;
}   t_stack;

#endif

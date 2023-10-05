/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_lst.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh <ljh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 23:59:03 by ljh               #+#    #+#             */
/*   Updated: 2023/10/04 11:12:02 by ljh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLE_LST_H
# define DOUBLE_LST_H

# include "libft/libft.h"
# include <stdlib.h>

typedef struct s_dlst
{
    struct s_dlst   *next;
    struct s_dlst   *prev;
    void            *elem;
}   t_dlst;

t_dlst  *dlst_node_generate(void *element);
int	    dlst_init(t_dlst **head, t_dlst **tail);
int     dlst_add_last(t_dlst *tail, void *element);
void	dlst_del_last(t_dlst *tail, void (*del)(void*));
void	*dlst_last_elem(t_dlst *tail);
void	dlst_print(t_dlst *head, void (*print)(void*));
void    dlst_rev_print(t_dlst *tail, void (*print)(void*));
void	dlst_del_all(t_dlst *head, void (*del)(void*));

#endif
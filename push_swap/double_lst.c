/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh <ljh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 23:57:30 by ljh               #+#    #+#             */
/*   Updated: 2023/10/12 17:47:34 by ljh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_lst.h"

t_node  *dlst_node_generate(void *element)
{
	t_node  *node;
	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->elem = element;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

int	dlst_init(t_node **head, t_node **tail)
{
	*head = dlst_node_generate(NULL);
	*tail = dlst_node_generate(NULL);
	if (*head == NULL || *tail == NULL)
		return (-1);
	(*head)->next = *tail;
	(*tail)->prev = *head;
	return (1);
}

int dlst_add_last(t_node *tail, void *element)
{
	t_node  *node;

	node = dlst_node_generate(element);
	tail->prev->next = node;
	node->prev = tail->prev;
	node->next = tail;
	tail->prev = node;
	return (1);
}

void	dlst_del_last(t_node *tail, void (*del)(void*))
{
	// t_dlst	*del_node;
	// t_dlst	*del_node_prev;

	// del_node = tail->prev;
	// del_node_prev = del_node->prev;
	// del(del_node->elem);
	// free(del_node);
	// del_node_prev->next = tail;
	// tail->prev = del_node_prev;
	t_node	*del_node_prev;

	del_node_prev = tail->prev->prev;
	del(del_node_prev->next);
	del_node_prev->next = tail;
	tail->prev = del_node_prev;
}

void	dlst_del_all(t_node *head, void (*del)(void*))
{
	t_node	*node;
	t_node	*next;

	node = head;
	while (node)
	{
		del(node->elem);
		next = node->next;
		free(node);
		node = next;
	}
}

void	*dlst_last_elem(t_node *tail)
{
	return (tail->prev->elem);
}


void	dlst_print(t_node *head, void (*print)(void*))
{
	t_node	*node;

	node = head->next;
	while (node->next)
	{
		print(node->elem);
		node = node->next;
	}
}

void    dlst_rev_print(t_node *tail, void (*print)(void*))
{
	t_node	*node;

	node = tail->prev;
	while (node->prev)
	{
		print(node->elem);
		node = node->prev;
	}
}
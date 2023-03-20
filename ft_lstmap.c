/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:35:52 by jeholee           #+#    #+#             */
/*   Updated: 2023/03/20 23:05:03 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*node;

	head = NULL;
	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	while (lst)
	{
		node = ft_lstnew(f(lst->content));
		if (node == NULL)
		{	
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, ft_lstnew(f(lst->content)));
		lst = lst->next;
	}
	return (head);
}

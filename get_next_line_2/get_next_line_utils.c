/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:05:35 by stack             #+#    #+#             */
/*   Updated: 2023/06/27 18:09:36 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"	// 에러 제거

t_list	*ft_lstnew(char *content)
{
	t_list	*node;
	ssize_t	i;
	ssize_t	lnpos;

	i = -1;
	lnpos = -1;
	node = (t_list *)malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	while (content[++i])
		if (content[i] == '\n' && lnpos == -1)
			lnpos = i + 1;
	node->content = ft_strncat((char *)malloc(i + 1), content, i + 1, 1);
	if (node->content == NULL)
	{
		free(node);
		return (NULL);
	}
	node->len = i;
	node->lnpos = lnpos;
	node->next = NULL;
	return (node);
}

int	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	node = *lst;
	if (new == NULL)
		return (-1);
	if (*lst == NULL)
	{
		*lst = new;
		return (1);
	}
	while (node->next)
		node = node->next;
	new->len += node->len;
	node->next = new;
	return (1);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*node;

	if (lst == NULL)
		return ;
	while (*(lst))
	{
		node = (*(lst))->next;
		free((*(lst))->content);
		(*(lst))->content = NULL;
		free(*(lst));
		*(lst) = node;
	}
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

char	*ft_strncat(char *dest, const char *src, ssize_t nb, int flag)
{
	char	*r_dest;

	if (dest == NULL)
		return (NULL);
	r_dest = dest;
	if (flag == 1)
		*(dest) = '\0';
	while (*(dest))
		dest++;
	while (*(src) && (nb--) > 0)
		*(dest++) = *(src++);
	*(dest) = '\0';
	return (r_dest);
}
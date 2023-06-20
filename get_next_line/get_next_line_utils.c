/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:05:35 by stack             #+#    #+#             */
/*   Updated: 2023/06/20 19:42:32 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"	// 에러 제거

t_list	*ft_lstnew(char *content)
{
	t_list	*node;
	ssize_t	i;

	i = 0;
	node = (t_list *)malloc(sizeof(t_list));
	if (node == NULL || content == NULL)
		return (NULL);
	node->content = content;
	while (node->content[i])
		i++;
	node->len = 0;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	node = *lst;
	if (lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (node->next)
		node = node->next;
	node->next = new;
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

char	*ft_strndup(const char *src, ssize_t n)
{
	char	*r_dst;
	char	*dst;

	dst = (char *)malloc(sizeof(char) * (n + 1));
	if (dst == NULL || src == NULL)
		return (NULL);
	r_dst = dst;
	while ((n--) > 0)
		*(dst++) = *(src++);
	*(dst) = '\0';
	return (r_dst);
}

char	*ft_strncat(char *dest, const char *src, ssize_t nb)
{
	char	*r_dest;

	if (dest == NULL)
		return (NULL);
	r_dest = dest;
	while (*(dest))
		dest++;
	while (*(src) && (nb--) > 0)
		*(dest++) = *(src++);
	return (r_dest);
}

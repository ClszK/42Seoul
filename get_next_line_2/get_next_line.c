/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:11:33 by jeholee           #+#    #+#             */
/*   Updated: 2023/07/07 21:31:33 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"	// 에러 제거

char	*get_next_line(int fd)
{
	static t_list	*tmp;
	char			*rline;
	char			*buffer;
	ssize_t			readsize;

	rline = NULL;
	buffer = NULL;
	if (!(BUFFER_SIZE < 0 || BUFFER_SIZE > 4294967295))
		buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	ft_lstclear(&tmp, buffer);
	readsize = 1;
	while (buffer != NULL)
	{
		if (readsize == 0 || (tmp != NULL && (ft_lstlast(tmp))->lnpos != -1))
		{
			rline = ft_lstcat(&tmp);
			break ;
		}
		readsize = read(fd, (char *)buffer, BUFFER_SIZE);
		if (read_line(&tmp, buffer, readsize) < 0)
			break ;
	}
	ft_lstclear(&tmp, rline);
	free(buffer);
	return (rline);
}

int	read_line(t_list **tmp, char *buffer, ssize_t readsize)
{
	if (readsize < 0)
	{
		ft_lstclear(tmp, NULL);
		return (-1);
	}
	if (readsize == 0)
		return (1);
	buffer[readsize] = '\0';
	if (ft_lstadd_back(tmp, ft_lstnew(buffer)) == -1)
	{
		ft_lstclear(tmp, NULL);
		return (-1);
	}
	return (1);
}

char	*ft_lstcat(t_list **tmp)
{
	char	*str;
	t_list	*node;
	size_t	nlen;

	if (*tmp == NULL || (*tmp)->len == 0)
		return (NULL);
	node = ft_lstlast(*tmp);
	nlen = node->totallen;
	if (node->lnpos != -1)
		nlen = nlen - node->len + node->lnpos;
	str = (char *)malloc(sizeof(char) * (nlen + 1));
	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	node = (*tmp);
	while (node->next != NULL)
	{
		(void)ft_strncat(str, node->content, node->len, 0);
		node = node->next;
	}
	str = ft_lstcat_2(tmp, node, str);
	return (str);
}

char	*ft_lstcat_2(t_list **tmp, t_list *node, char *str)
{
	size_t	nlen;
	char	*stmp;

	if (node->lnpos != -1 && node->content[node->lnpos] != '\0')
	{
		nlen = node->len - node->lnpos + 1;
		(void)ft_strncat(str, node->content, node->lnpos, 0);
		stmp = ft_strncat(malloc(nlen), node->content + node->lnpos, nlen, 1);
		ft_lstclear(tmp, NULL);
		if (stmp == NULL || ft_lstadd_back(tmp, ft_lstnew(stmp)) == -1)
		{
			free(str);
			str = NULL;
		}
		free(stmp);
	}
	else
	{
		(void)ft_strncat(str, node->content, node->len, 0);
		ft_lstclear(tmp, NULL);
	}
	return (str);
}

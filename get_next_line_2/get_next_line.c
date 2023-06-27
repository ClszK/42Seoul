/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:11:33 by jeholee           #+#    #+#             */
/*   Updated: 2023/06/27 19:03:54 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"	// 에러 제거
#include <stdio.h>

char	*ft_lstcat(t_list **tmp);
int		read_line(t_list **tmp, char *buffer, ssize_t readsize);

char	*get_next_line(int fd)
{
	static t_list	*tmp;
	char			*rline;
	char			*buffer;
	ssize_t			readsize;

	rline = NULL;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
	{
		ft_lstclear(&tmp);
		return (NULL);
	}
	readsize = 1;
	while (1)
	{
		if (readsize == 0 || (tmp != NULL && (ft_lstlast(tmp))->lnpos != -1))
		{
			rline = ft_lstcat(&tmp);
			if (rline == NULL)
				ft_lstclear(&tmp);
			break ;
		}
		readsize = read(fd, (char *)buffer, BUFFER_SIZE);
		if (read_line(&tmp, buffer, readsize) < 0)
			break ;
	}
	free(buffer);
	return (rline);
}

int	read_line(t_list **tmp, char *buffer, ssize_t readsize)
{
	if (readsize < 0)
	{
		ft_lstclear(tmp);
		return (-1);
	}
	if (readsize == 0)
		return (1);
	buffer[readsize] = '\0';
	if (ft_lstadd_back(tmp, ft_lstnew(buffer)) == -1)
	{
		ft_lstclear(tmp);
		return (-1);
	}
	return (1);
}

char	*ft_lstcat(t_list **tmp)
{
	char	*str;
	char	*stmp;
	t_list	*node;
	ssize_t	nlen;

	node = *tmp;
	if (*tmp == NULL || node->len == 0)
		return (NULL);
	str = (char *)malloc(sizeof(char) * ((ft_lstlast(node))->len + 1));
	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	nlen = 0;
	while (node->next != NULL)
	{
		(void)ft_strncat(str, node->content, node->len, 0);
		nlen += node->len;
		node = node->next;
	}
	if (node->lnpos != -1 && node->content[node->lnpos] != '\0')
	{
		nlen = node->len - nlen - node->lnpos + 1;
		(void)ft_strncat(str, node->content, node->lnpos, 0);
		stmp = ft_strncat((char *)malloc(nlen), \
		node->content + node->lnpos, BUFFER_SIZE, 1);
		ft_lstclear(tmp);
		if (stmp == NULL || ft_lstadd_back(tmp, ft_lstnew(stmp)) == -1)
		{
			free(stmp);
			free(str);
			return (NULL);
		}
		free(stmp);
	}
	else
	{
		(void)ft_strncat(str, node->content, node->len, 0);
		ft_lstclear(tmp);	
	}
	return (str);
}

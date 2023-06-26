/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:11:33 by jeholee           #+#    #+#             */
/*   Updated: 2023/06/26 22:57:07 by jeholee          ###   ########.fr       */
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

	readsize = 1;
	rline = NULL;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	while (readsize)
	{
		if (tmp != NULL)
		{
			if ((ft_lstlast(tmp))->lnpos != -1 || readsize == 0)
			{
				rline = ft_lstcat(&tmp);
				break ;
			}
		}
		readsize = read(fd, (char *)buffer, BUFFER_SIZE);
		buffer[BUFFER_SIZE] = '\0';
		if (read_line(&tmp, buffer, readsize) < 0)
			return (NULL);
	}
	return (rline);
}

int	read_line(t_list **tmp, char *buffer, ssize_t readsize)
{
	if (readsize < 0)
	{
		ft_lstclear(tmp);
		return (-1);
	}
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

	node = *tmp;
	str = (char *)malloc(sizeof(char) * (ft_lstlast(node)->len + 1));
	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	while (node->next != NULL)
	{
		(void)ft_strncat(str, node->content, node->len);
		node = node->next;
	}
	(void)ft_strncat(str, node->content, node->lnpos);
	stmp = ft_strncat((char *)malloc(BUFFER_SIZE + 1), \
	node->content + node->lnpos + 1, BUFFER_SIZE);
	ft_lstclear(tmp);
	if (ft_lstadd_back(tmp, ft_lstnew(stmp)) == -1)
		return (NULL);
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:11:33 by jeholee           #+#    #+#             */
/*   Updated: 2023/07/07 22:31:32 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"	// 에러 제거

char	*get_next_line(int fd)
{
	static t_list	*tmp[OPEN_MAX];
	char			*rline;
	char			*buffer;
	ssize_t			rsize;

	rline = NULL;
	buffer = NULL;
	if (!(BUFFER_SIZE <= 0 || fd >= OPEN_MAX || fd < 0))
		buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	ft_lstclear(tmp, buffer, fd);
	rsize = 1;
	while (buffer != NULL && fd >= 0)
	{
		if (rsize == 0 || (tmp[fd] != NULL && (lstlast(tmp[fd]))->lnpos != -1))
		{
			rline = ft_lstcat(&tmp[fd]);
			ft_lstclear(&tmp[fd], rline, 0);
			break ;
		}
		rsize = read(fd, (char *)buffer, BUFFER_SIZE);
		if (read_line(&tmp[fd], buffer, rsize) < 0)
			break ;
	}
	free(buffer);
	return (rline);
}

int	read_line(t_list **tmp, char *buffer, ssize_t readsize)
{
	if (readsize < 0)
	{
		ft_lstclear(tmp, NULL, 0);
		return (-1);
	}
	if (readsize == 0)
		return (1);
	buffer[readsize] = '\0';
	if (ft_lstadd_back(tmp, ft_lstnew(buffer)) == -1)
	{
		ft_lstclear(tmp, NULL, 0);
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
	node = lstlast(*tmp);
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
		ft_lstclear(tmp, NULL, 0);
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
		ft_lstclear(tmp, NULL, 0);
	}
	return (str);
}

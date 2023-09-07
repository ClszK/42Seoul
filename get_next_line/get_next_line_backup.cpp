/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:00:46 by stack             #+#    #+#             */
/*   Updated: 2023/06/20 16:35:47 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" // 에러 제거

#include <stdio.h>

ssize_t	find_ln_pos(char *buff, ssize_t bsize);
char	*rline_cal(char *buff, t_list **line, ssize_t len);
char	*justify_ln(char *buff, t_list **line, ssize_t *rlen, ssize_t size);

char *get_next_line(int fd)
{
	char		*buff;
	t_list		*line;
	static char	*btmp;
	ssize_t		rsize;
	ssize_t		rlen;
	ssize_t		lnpos;
	ssize_t		btmp_size;

	rsize = 1;

	rlen = 0;
	btmp_size = 0;

	line = NULL;
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (buff == NULL)
		return (NULL);
	while (true)
	{
		if (btmp != NULL && *btmp != '\0')
		{
			if (find_ln_pos(btmp, btmp_size) != ft_strlen(btmp))
			{
				return (justify_ln(btmp, &line, &rlen, ft_strlen(btmp)));
			}
			else
				(void)justify_ln(btmp, &line, &rlen, ft_strlen(btmp));
			btmp = NULL;
		}
		rsize = read(fd, (char *)buff, (size_t)BUFFER_SIZE);
		if (rsize == R_ERROR) // error
			return (NULL);
		if (rsize == 0)
		{
			return (rline_cal(buff, &line, rlen));
		}
		if (find_ln_pos(buff, BUFFER_SIZE) != BUFFER_SIZE)
			return (justify_ln(buff, &line, &rlen, BUFFER_SIZE));
		else
			(void)justify_ln(buff, &line, &rlen, BUFFER_SIZE);
	}
}

ssize_t	find_ln_pos(char *buff, ssize_t bsize)
{
	ssize_t	i;

	i = 0;
	if (*(buff) == '\0')
		return (i);
	while (*(buff + i) != '\n' && i != bsize - 1)
		i++;
	return (i + 1);
}

char	*rline_cal(char *buff, t_list **line, ssize_t len)
{
	char	*rline;
	t_list	*node;
	size_t	buff_len;

	if (*line == NULL)
		return (buff);
	node = *line;
	buff_len = ft_strlen(buff) + 1;
	rline = (char *)malloc(len + buff_len);
	if (rline == NULL)
		return (NULL);
	while (node != NULL)
	{
		(void)ft_strncat(rline, node->content, ft_strlen(node->content));
		node = node->next;
	}
	ft_strncat(rline, buff, ft_strlen(buff));
	ft_lstclear(line);
	return (rline);
}

char	*justify_ln(char *buff, t_list **line, ssize_t *rlen, ssize_t size)
{
	ssize_t	lnpos;
	char	*btmp;
	char	*tmp;

	lnpos = find_ln_pos(buff, size);
	if (lnpos != size)
	{
		btmp = ft_strndup(buff + lnpos, BUFFER_SIZE - lnpos + 1);
		tmp = ft_strndup(buff, lnpos);
		return (rline_cal(tmp, line, *rlen));
	}
	else
		tmp = ft_strndup(buff, lnpos);
	*rlen += ft_strlen(tmp);
	ft_lstadd_back(line, ft_lstnew(tmp));
	return (NULL);
}

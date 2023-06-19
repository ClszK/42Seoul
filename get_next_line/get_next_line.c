/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:00:46 by stack             #+#    #+#             */
/*   Updated: 2023/06/19 19:41:36 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"	// 에러 제거

#include <stdio.h>

ssize_t	find_ln_pos(char *buff, ssize_t bsize);

char	*get_next_line(int fd)
{
	char		*buff;
	char		*tmp;
	t_list		*line;
	static char	*btmp;
	ssize_t		rsize;
	ssize_t		lnpos;
	ssize_t		btmp_size;

	ssize_t		final_size;
	t_list		*good;
	char		*rline;

	rsize = 1;

	final_size = 0;
	btmp_size = 0;

	line = NULL;
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (buff == NULL)
		return (NULL);
	while (true)
	{
		if (btmp != NULL && *btmp != '\0')
		{
			btmp_size = ft_strlen(btmp);
			lnpos = find_ln_pos(btmp, btmp_size);
			if (lnpos != btmp_size)
			{
				write(1, "test\n", 5);
				return (NULL);
			}	
			ft_lstadd_back(&line, ft_lstnew(btmp));
			btmp = NULL;
		}
		rsize = read(fd, (char *)buff, (size_t)BUFFER_SIZE);
		if (rsize == R_ERROR)		//error
			return (NULL);
		if (rsize == 0)
		{
			if (line == NULL)
				return (buff);
			good = line;
			while (good != NULL)
			{
				final_size += ft_strlen(line->content);
				good = good->next;
			}
			rline = (char *)malloc(sizeof(char) * (final_size + 1));
			if (rline == NULL)
				return (NULL);
			good = line;
			while (good != NULL)
			{
				(void)ft_strncat(rline, good->content, ft_strlen(good->content));
				good = good->next;
			}
			ft_strncat(rline, buff, ft_strlen(buff));
			ft_lstclear(&line);
			return (rline);
		}
		lnpos = find_ln_pos(buff, BUFFER_SIZE);
		if (lnpos != BUFFER_SIZE)
		{
			btmp = ft_strndup(buff + lnpos, BUFFER_SIZE - lnpos + 1);
			tmp = ft_strndup(buff, lnpos);
			if (line == NULL)
				return (tmp);
			good = line;
			while (good != NULL)
			{
				final_size += ft_strlen(line->content);
				good = good->next;
			}
			rline = (char *)malloc(sizeof(char) * (final_size + 1));
			if (rline == NULL)
				return (NULL);
			good = line;
			while (good != NULL)
			{
				(void)ft_strncat(rline, good->content, ft_strlen(good->content));
				good = good->next;
			}
			ft_strncat(rline, tmp, ft_strlen(tmp));
			ft_lstclear(&line);
			final_size = 0;
			return (rline);
		}
		else
			tmp = ft_strndup(buff, lnpos);
		ft_lstadd_back(&line, ft_lstnew(tmp));
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
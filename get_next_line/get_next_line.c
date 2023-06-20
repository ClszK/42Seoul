/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:00:20 by jeholee           #+#    #+#             */
/*   Updated: 2023/06/20 19:48:25 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" // 에러 제거

ssize_t	find_ln_pos(char *buff, ssize_t bsize);
int		line_in_ln(char *buff, t_list **tmp, ssize_t bsize, char **rline);
char	*ln_ret(t_list **tmp, char *buff, ssize_t lnpos);

char	*get_next_line(int fd)
{
	static t_list	*tmp;
	char			*buff;
	ssize_t			rsize;
	int				inln;

	tmp = NULL;
	while (true)
	{
		if (tmp != NULL)
		{
			inln = line_in_ln((ft_lstlast(tmp))->content, \
			&tmp, ft_lstlast(tmp)->content, &buff);
			if (inln < 0)
			{
				if (buff != NULL)
					free(buff);
				return (NULL);
			}
			if (inln == 1)
		}
		rsize = read(fd, (char *)buff, BUFFER_SIZE);
		if (rsize < 0)
			continue; //error
		if (rsize == 0)
		{
			// 파일의 끝
		}
	}
	return (NULL);
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

int	line_in_ln(char *buff, t_list **tmp, ssize_t bsize, char **rline)
{
	ssize_t	lnpos;
	ssize_t	len;
	t_list	*node;

	lnpos = find_ln_pos(buff, bsize);
	if (lnpos == bsize)
	{
		node = ft_lstnew(buff);
		if (node == NULL)
			return (NULL);
		ft_lstadd_back(tmp, node);
		return (0);
	}
	*rline = ln_ret(tmp, buff, lnpos);
	if (*rline == NULL)
		return (-1);
	len = bsize - lnpos;
	node = ft_lstnew(ft_strncat((char *)malloc(len), buff + lnpos, len));
	if (node == NULL)
		return (-1);
	ft_lstadd_back(tmp, node);
	return (1);
}

char	*ln_ret(t_list **tmp, char *buff, ssize_t lnpos)
{
	ssize_t	len;
	t_list	*node;
	char	*rline;

	len = 0;
	node = *tmp;
	while (node != NULL)
	{
		len += node->len;
		node = node->next;
	}
	node = *tmp;
	rline = (char *)malloc(sizeof(char) * (len + 1));
	if (rline == NULL)
		return (NULL);
	while (node != NULL)
	{
		(void)ft_strncat(rline, node->content, node->len);
		node = node->next;
	}
	(void)ft_strncat(rline, buff, lnpos);
	ft_lstclear(tmp);
	return (rline);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:00:20 by jeholee           #+#    #+#             */
/*   Updated: 2023/06/22 22:46:57 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" // 에러 제거

ssize_t	find_ln_pos(char *buff, ssize_t bsize);
int		line_in_ln(t_list *node, t_list **tmp, char **rline);
char	*ln_ret(t_list **tmp, ssize_t lnpos);
void	free_all(t_list **node, char **buff);
char	*ft_substr(char const *s, ssize_t start, ssize_t len);

char	*get_next_line(int fd)
{
	static t_list	*tmp;
	char			*buff;
	ssize_t			rsize;
	int				inln;

	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	while (true)
	{
		if (tmp != NULL)
		{
			inln = find_ln_pos(tmp->content, tmp->len);
			if (inln > 0)
				return (ln_ret(tmp, inln));
		}
		inln = line_in_ln(ft_lstlast(tmp), &tmp, &buff);
		if (inln < 0 || rsize < 0)
		{
			free(buff);
			ft_lstclear(&tmp);
			return (NULL);
		}
		else if (inln == 1)
			return (buff);
		rsize = read(fd, (char *)buff, BUFFER_SIZE);
	}
}

ssize_t	find_ln_pos(char *buff, ssize_t bsize)
{
	ssize_t	i;

	i = 0;
	if (*(buff) == '\0')
		return (i);
	while (i != bsize && *(buff + i) != '\n')
		i++;
	if (i == bsize)
		return (-1);
	return (i + 1);
}

int	line_in_ln(t_list **tmp, char **rline, ssize_t rsize)
{
	ssize_t	lnpos;
	ssize_t	size;

	if (*rline == NULL)
		return (-1);
	lnpos = find_ln_pos(*rline, rsize);
	if (lnpos < 0)
	{
		if (ft_lstadd_back(tmp, ft_lstnew(*rline)) < 0)
			return (-1);
		return (0);
	}
	*rline = ln_ret(tmp, lnpos);
	if (*rline == NULL)
		return (-1);
	size = BUFFER_SIZE - lnpos;
	if (size != 0 && ft_lstadd_back(tmp, ft_lstnew(\
	ft_strncat((char *)malloc(size), node->content + lnpos, size))) < -1)
		return (-1);
	return (1);
}

// int	line_in_ln(char *str, t_list **tmp, char **rline)
// {
// 	ssize_t	lnpos;
// 	ssize_t	size;

// 	if (*rline == NULL)
// 		return (-1);
	
// }

char	*ln_ret(t_list **tmp, ssize_t lnpos)
{
	ssize_t	len;
	t_list	*node;
	char	*rline;

	len = 0;
	node = *tmp;
	while (node->next != NULL)
	{
		len += node->len;
		node = node->next;
	}
	node = *tmp;
	rline = (char *)malloc(sizeof(char) * (len + lnpos + 1));
	if (rline == NULL)
		return (NULL);
	while (node->next != NULL)
	{
		(void)ft_strncat(rline, node->content, node->len);
		node = node->next;
	}
	return (rline);
}

// void	free_all(t_list **node, char **buff)
// {
// 	ft_lstclear(node);
// 	*node = NULL;
// 	free(*buff);
// 	*buff = NULL;
// }

char	*ft_substr(char const *s, ssize_t start, ssize_t len)
{
	char			*substr;
	unsigned int	sublen;
	unsigned int	pos;

	sublen = start;
	pos = 0;
	if (s == NULL)
		return (NULL);
	while (s[sublen] && (len--) > 0)
		sublen++;
	sublen -= start;
	substr = (char *)malloc(sizeof(char) * (sublen + 1));
	if (substr == NULL)
		return (NULL);
	while ((sublen--) > 0)
	{
		substr[pos] = s[pos + start];
		pos++;
	}
	substr[pos] = '\0';
	return (substr);
}

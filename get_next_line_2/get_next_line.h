/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 13:57:57 by stack             #+#    #+#             */
/*   Updated: 2023/06/26 20:40:25 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# define R_ERROR -1

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*content;
	ssize_t			len;
	ssize_t			lnpos;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);

t_list	*ft_lstnew(char *content);
int		ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
t_list	*ft_lstlast(t_list *lst);
char	*ft_strncat(char *dest, const char *src, ssize_t nb, int flag);

#endif
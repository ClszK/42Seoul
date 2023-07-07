/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 13:57:57 by stack             #+#    #+#             */
/*   Updated: 2023/07/07 23:04:14 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# if BUFFER_SIZE > 4294967295
#  undef BUFFER_SIZE
#  define BUFFER_SIZE -1
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 49152
# endif

# if OPEN_MAX <= 0
#  undef OPEN_MAX
#  define OPEN_MAX 49152
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*content;
	ssize_t			len;
	ssize_t			lnpos;
	ssize_t			totallen;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
char	*ft_lstcat(t_list **tmp);
int		read_line(t_list **tmp, char *buffer, ssize_t readsize);
char	*ft_lstcat_2(t_list **tmp, t_list *node, char *str);

t_list	*ft_lstnew(char *content);
int		ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, char *str, int fd);
t_list	*lstlast(t_list *lst);
char	*ft_strncat(char *dest, const char *src, ssize_t nb, int flag);

#endif
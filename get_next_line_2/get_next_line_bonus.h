/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 13:57:57 by stack             #+#    #+#             */
/*   Updated: 2023/07/10 18:50:21 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# if BUFFER_SIZE > 4294967295
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# elif BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 49152
# endif

# if OPEN_MAX <= 0
#  undef OPEN_MAX
#  define OPEN_MAX 0
# elif OPEN_MAX >= 2147483647
#  undef OPEN_MAX
#  define OPEN_MAX 0
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*content;
	long long		len;
	long long		lnpos;
	size_t			totallen;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
char	*gnl_lstcat(t_list **tmp);
int		read_line(t_list **tmp, char *buffer, ssize_t readsize);
char	*gnl_lstcat_2(t_list **tmp, t_list *node, char *str);

t_list	*gnl_lstnew(char *content);
int		gnl_lstadd_back(t_list **lst, t_list *new);
void	gnl_lstclear(t_list **lst, char *str, int fd);
t_list	*gnl_lstlast(t_list *lst);
char	*gnl_strncat(char *dest, const char *src, ssize_t nb, int flag);

#endif
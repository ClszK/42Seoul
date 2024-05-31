/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   good.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:02:33 by jeholee           #+#    #+#             */
/*   Updated: 2023/02/26 14:03:31 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_numset t_numset;

int             ft_strlen(char *str);
char            *ft_strcpy(char *dest, char *src);
char            *ft_strdup(char *src);
char	        *ft_whitespace(char *str);
int	            ft_strcmp(char *s1, char *s2);
int	            ft_atoi(char *str);

t_numset        *init(void);
t_numset        *get_num_node(char *str, int len, int val);
void	        numset_insert_sort_dec(t_numset *head, t_numset *new_node);
void	        numset_insert_sort_asc(t_numset *head, t_numset *new_node);
int             numset_add(char *str, int len, int val, t_numset *head);
int	            is_under_correct(int n);
int	            is_num_digits(char *str);
int	            dict_parsing_arr(t_numset *head, char **t_under, int num_len);

long long int   countline(void);
char            *store_line(int fd1, int fd2);
char            **split_line(char *str);

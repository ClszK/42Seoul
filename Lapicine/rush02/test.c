/* ************************************************************************** */
/*	*/
/*	:::	  ::::::::   */
/*   main.c	 :+:	  :+:	:+:   */
/*	+:+ +:+	 +:+	 */
/*   By: jeholee <jeholee@student.42.fr>	+#+  +:+	   +#+	*/
/*	+#+#+#+#+#+   +#+	   */
/*   Created: 2023/02/26 02:23:02 by jeholee	   #+#	#+#	 */
/*   Updated: 2023/02/26 18:20:16 by jeholee	  ###   ########.fr	   */
/*	*/
/* ************************************************************************** */

#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>

typedef struct s_numset	t_numset;

int				ft_strlen(char *str);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strdup(char *src);
char			*ft_whitespace(char *str);
int				ft_strcmp(char *s1, char *s2);
int				ft_atoi(char *str);
t_numset		*init(char ***map_three_less);
t_numset		*get_num_node(char *str, int len, int val);
int				numset_add(char *str, int len, int val, t_numset *head);
long long int	countline(char *filename);
char			*store_line(int fd1, int fd2);
char			**split_line(char *str);
int				numset_insert_sort_dec(t_numset *head, t_numset *new_node);
int				is_under_correct(int n);
int				is_num_digits(char *str);
int				dict_parsing_arr(t_numset *head, char **t_under, char *file, int *fd);
void			print_set(int num, char **map);
void			ft_putstr(char *str);

struct s_numset
{
	char		*str;
	int			len;
	int			val;
	t_numset	*next;
};

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char	*r_dest;

	r_dest = dest;
	while (*(src) && n > 0)
	{	
		*(dest++) = *(src++);
		n--;
	}
	*(dest) = '\0';
	return (r_dest);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*(s1) || *(s2))
	{
		if (*(s1) != *(s2))
			return (*(s1) - *(s2));
		s1++;
		s2++;
	}
	return (0);
}

char	*ft_strcpy(char *dest, char *src)
{
	char	*r_dest;

	r_dest = dest;
	while (*(src))
		*(dest++) = *(src++);
	*(dest) = '\0';
	return (r_dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*tmp;
	int		len;
	int		i;

	len = ft_strlen(src);
	tmp = (char *)malloc(len + 1);
	i = 0;
	while (i < len)
	{
	tmp[i] = src[i];
	i++;
	}
	tmp[len] = '\0';
	return (tmp);
}

char	*ft_whitespace(char *str)
{
	while ((*(str) >= 8 && *(str) <= 13) || *(str) == 32)
		str++;
	return (str);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	r_num;

	sign = 1;
	r_num = 0;
	str = ft_whitespace(str);
	while (*(str) == '-' || *(str) == '+')
		if (*(str++) == '-')
			sign *= -1;
	while (*(str) >= '0' && *(str) <= '9')
	{
		r_num = r_num * 10 + (*(str) - '0');
		str++;
	}
	return (r_num * sign);
}

t_numset	*get_num_node(char *str, int len, int val)
{
	t_numset	*node;

	node = (t_numset *)malloc(sizeof(t_numset));
	if (node == 0)
		return (0);
	node->len = len;
	node->str = str;
	node->val = val;
	node->next = 0;
	return (node);
}

t_numset	*init(char ***map_three_less)
{
	t_numset	*node;
	int			i;

	i = 0;
	*map_three_less = (char **)malloc(sizeof(char *) * 101);
	node = get_num_node(0, 0, 0);
	node->next = get_num_node(0, 0, 0);
	while (i < 101)
		*(*(map_three_less) + (i++)) = 0;
	return (node);
}

int	numset_add(char *str, int len, int val, t_numset *head)
{
	t_numset	*node;

	node = head->next;
	while (node->next)
	node = node->next;
	node->next = get_num_node(str, len, val);
	if (node->next == 0)
		return (0);
	return (1);
}

int	numset_insert_sort_dec(t_numset *head, t_numset *new_node)
{
	t_numset	*temp_node;
	t_numset	*node;

	node = head;
	while (node->next)
	{
		if (node->next->len < new_node->len)
		{
			temp_node = node->next;
			node->next = new_node;
			new_node->next = temp_node;
			return (1);
		}
        else if (node->next->len == new_node->len)
            return (0);
        node = node->next;
	}
	node->next = new_node;
    return (1);
}


long long int	countline(char *filename)
{
	int				fd;
	int				len;
	char			tmp;
	long long int	line;

	line = 0;
	len = 0;
	tmp = 'a';
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	while (read(fd, &tmp, 1) > 0)
	{
		if (tmp == '\n')
		{
			if (len != 0)
				line++;
			len = 0;
		}
		else
		len++;
	}
	close(fd);
	return (line);
}

char	*store_line(int fd1, int fd2)
{
	unsigned long long	len;
	char				tmp;
	char				*arr;

	len = 0;
	tmp = 'a';
	while (tmp != '\n')
	{
		read(fd1, &tmp, 1);
		len++;
	}
	if (len == 1)
	{
		read(fd2, &tmp, 1);
		return (store_line(fd1, fd2));
	}
	arr = (char *)malloc(sizeof(char) * (len + 1));
	read(fd2, arr, len);
	arr[len - 1] = '\0';
	return (arr);
}

int	is_under_correct(int n)
{
	if ((n >= 0 && n <= 20)
		|| (n % 10 == 0 && (n / 10 >= 3 && n / 10 <= 10)))
		return (1);
	return (0);
}

int	is_num_digits(char *str)
{
	if (*(str++) != '1')
		return (0);
	while (*(str))
		if (*(str++) != '0')
			return (0);
	return (1);
}

void	print_node(t_numset *head, char **map)
{
	t_numset	*node;

	node = head->next;
	while (node)
	{
		if (node->val != -1 )
		{
			print_set(node->val, map);
			ft_putstr(node->str);
		}
		printf("str : %10s\t val : %5d\tlen : %5d ->\n", node->str, node->val, node->len);
		node = node->next;
	}
}

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	dict_parsing_arr(t_numset *head, char **t_under, char *file, int *fd)
{
	long long		line;
	int				num_len;
	char			**str;

	line = countline(file);
	while (line-- > 0)
	{
		str = split_line(store_line(fd[0], fd[1]));
		if (ft_str_is_numeric(str[0]) == 0)
			return (0);
		num_len = ft_strlen(str[0]);
		if (num_len <= 3 && is_under_correct(ft_atoi(str[0])))
		{
			if (t_under[ft_atoi(str[0])] != 0)
				return (0);
			t_under[ft_atoi(str[0])] = ft_strdup(str[1]);
		}
		else if (num_len >= 4 && is_num_digits(str[0]))
			if (!numset_insert_sort_dec(head, get_num_node(str[1], ft_strlen(str[0]) - 1, -1)))
				return (0);
	}
	return (1);
}

char	**split_line(char *str)
{
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	tmp = (char **)malloc(sizeof(char *) * 2);
	str = ft_whitespace(str);
	while (str[i] != ':')
		i++;
	j = 1;
	while (str[i - j] == ' ')
		j++;
	str[i - j + 1] = '\0';
	tmp[0] = ft_strdup(str);
	str += (i + 1);
	while (*str == ' ')
		str++;
	i = 0;
	while (str[i] != '\0')
		i++;
	tmp[1] = ft_strdup(str);
	return (tmp);
}

void	ft_putstr(char *str)
{
	static int	is_first = 0;

	if (is_first++)
		write(1, " ", 1);
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	print_set(int num, char **map)
{
	if (num / 100)
	{
		ft_putstr(map[num / 100]);
		ft_putstr(map[100]);
		if (num % 100 == 0)
			return ;
		num %= 100;
	}
	if (num / 10 > 1)
	{
		ft_putstr(map[num - num % 10]);
		if (num % 10)
			ft_putstr(map[num % 10]);
	}
	else
		ft_putstr(map[num]);
}


int     num_split(t_numset *head, char *str)
{
    int         len;
    t_numset    *node;
	char		num[4];
	int			mod_len;

    len = ft_strlen(str);
    node = head->next;
    while (node->next && *(str))
    {
		if (len - 3 <= node->len)
		{
			if (len % 3 != 0 && len / 3 == node->len / 3)
				mod_len = len % 3;
			node->val = ft_atoi(ft_strncpy(num, str, mod_len));
			str += 3;
			len -= 3;
		}
		node = node->next;
    }
	node->val = ft_atoi(ft_strncpy(num, str, 3));
	node->str = "";
	if (node->next && *(str))
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_numset	*head;
	char		**map_three_less;
	char		*file;
	int			fd[2];

	file = "numbers.dict";
	if (argc == 3)
		file = argv[1];
	fd[0] = open(file, O_RDONLY);
	if (ft_str_is_numeric(argv[argc - 1]) == 0 || argc > 3 || fd[0] == -1)
	{
		write(1, "Error\n", 7);
		return (-1);
	}
	close(fd[0]);
	head = init(&map_three_less);
	fd[0] = open(file, O_RDONLY);
	fd[1] = open(file, O_RDONLY);
	if (dict_parsing_arr(head, map_three_less, file, fd) == 0)
	{
		write(1, "Dict Error\n", 12);
		return (-1);
	}
	close(fd[0]);
	close(fd[1]);
	if (num_split(head, argv[argc - 1]))
		printf("\ngood!\n\n");
	print_node(head, map_three_less);
	return (0);
}

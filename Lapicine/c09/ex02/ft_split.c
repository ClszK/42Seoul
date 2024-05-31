/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:10:04 by jeholee           #+#    #+#             */
/*   Updated: 2023/03/01 11:10:07 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str++))
		i++;
	return (i);
}

char	*ft_strncpy(char *src, unsigned int n)
{
	char	*r_dest;
	char	*dest;

	if (n == 0)
		return (0);
	dest = (char *)malloc(sizeof(char) * (n + 1));
	r_dest = dest;
	while (*(src) && n > 0)
	{
		*(dest++) = *(src++);
		n--;
	}
	*(dest) = '\0';
	return (r_dest);
}

int	*ft_map_ascii(char *charset)
{
	int	i;
	int	charset_len;
	int	*map;

	i = 0;
	charset_len = ft_strlen(charset);
	map = (int *)malloc(sizeof(int) * 128);
	while (i < 128)
		map[i++] = 0;
	i = 0;
	while (i < charset_len)
		map[(int)charset[i++]] = 1;
	map[0] = 1;
	return (map);
}

int	ft_word_cnt(char *str, char *charset)
{
	int		cnt;
	int		*map;

	cnt = 0;
	map = ft_map_ascii(charset);
	while (*(str))
	{
		if (map[(int)*(str)] == 0)
		{
			cnt++;
			while (map[(int)*(str)] == 0)
				str++;
		}
		else
			str++;
	}
	return (cnt);
}

char	**ft_split(char *str, char *charset)
{
	char	**r_str;
	int		*map;
	int		each_len;
	int		i;

	i = 0;
	r_str = (char **)malloc(sizeof(char *) * (ft_word_cnt(str, charset) + 1));
	if (!r_str)
		return (NULL);
	map = ft_map_ascii(charset);
	while (*(str))
	{
		each_len = 0;
		while (map[(int)*(str + each_len)] == 0)
			each_len++;
		if (each_len != 0)
			r_str[i++] = ft_strncpy(str, each_len);
		if (*(str + each_len) == '\0')
			break ;
		str += each_len + 1;
	}
	r_str[i] = 0;
	return (r_str);
}

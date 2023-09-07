/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 11:37:26 by jeholee           #+#    #+#             */
/*   Updated: 2023/03/02 05:38:47 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str++))
		i++;
	return (i);
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

char	*ft_strdup(char *src)
{
	char	*r_src;
	int		src_len;

	src_len = ft_strlen(src) + 1;
	r_src = malloc(sizeof(char) * src_len);
	return (ft_strcpy(r_src, src));
}

t_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int				i;
	t_stock_str		*r_str;

	i = 0;
	if (ac < 0)
		return (NULL);
	r_str = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	while (i < ac)
	{
		r_str[i].size = ft_strlen(av[i]);
		r_str[i].str = av[i];
		r_str[i].copy = ft_strdup(av[i]);
		i++;
	}
	r_str[i].size = 0;
	r_str[i].str = 0;
	r_str[i].copy = 0;
	return (r_str);
}

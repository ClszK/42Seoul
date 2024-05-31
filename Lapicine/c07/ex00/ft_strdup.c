/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 05:29:51 by jeholee           #+#    #+#             */
/*   Updated: 2023/02/28 03:07:57 by jeholee          ###   ########.fr       */
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

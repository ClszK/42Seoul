/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 00:47:29 by jeholee           #+#    #+#             */
/*   Updated: 2023/09/27 02:10:12 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(char *str);

char	*ft_strcpy(char *dest, const char *src)
{
	char	*r_dest;

	r_dest = dest;
	while (*(src))
		*(dest++) = *(src++);
	*(dest) = '\0';
	return (r_dest);
}

char	*ft_strdup(const char *s1)
{
	char	*r_src;
	int		src_len;

	src_len = ft_strlen((char *)s1) + 1;
	r_src = malloc(sizeof(char) * src_len);
	if (r_src == NULL)
		return (NULL);
	return (ft_strcpy(r_src, (char *)s1));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 23:10:59 by jeholee           #+#    #+#             */
/*   Updated: 2023/03/14 00:04:14 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str++))
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	src_len;
	unsigned int	dest_len;
	unsigned int	dest_cat_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	dest_cat_len = 0;
	while (*(dest) && size > dest_cat_len + 1)
	{
		dest_cat_len++;
		dest++;
	}
	while (*(src) && size > dest_cat_len + 1)
	{	
		*(dest++) = *(src++);
		dest_cat_len++;
	}
	if (dest_len >= size)
		return (src_len + size);
	*(dest) = '\0';
	return (src_len + dest_len);
}

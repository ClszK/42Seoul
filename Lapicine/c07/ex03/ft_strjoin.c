/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:46:39 by jeholee           #+#    #+#             */
/*   Updated: 2023/02/28 18:54:34 by jeholee          ###   ########.fr       */
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

char	*ft_strcpy_ver2(char *dest, char *src, char *sep)
{
	while (*(src))
		*(dest++) = *(src++);
	while (*(sep))
		*(dest++) = *(sep++);
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		m_size;
	char	*m_str;
	char	*r_str;

	i = 0;
	m_size = 0;
	if (size <= 0)
	{
		m_str = (char *)malloc(sizeof(char) * 1);
		*m_str = 0;
		return (m_str);
	}
	while (i < size)
		m_size += ft_strlen(strs[i++]);
	i = m_size + (size - 1) * ft_strlen(sep) + 1;
	m_str = (char *)malloc(sizeof(char) * i);
	r_str = m_str;
	i = 0;
	while (i < size - 1)
		m_str = ft_strcpy_ver2(m_str, strs[i++], sep);
	m_str = ft_strcpy_ver2(m_str, strs[i], "");
	*(m_str) = '\0';
	return (r_str);
}

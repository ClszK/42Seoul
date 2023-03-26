/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 10:04:29 by jeholee           #+#    #+#             */
/*   Updated: 2023/02/13 17:34:37 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	int	cnt;

	cnt = 0;
	while (*(str++))
		cnt++;
	return (cnt);
}

unsigned int	ft_strlcpy(char dest[], char src[], unsigned int size)
{
	unsigned int	len;

	len = ft_strlen(src);
	if (size == 0)
		return (len);
	while (*(src) && (size--) - 1 > 0)
		*(dest++) = *(src++);
	*(dest) = '\0';
	return (len);
}

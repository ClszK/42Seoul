/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <dlwpgns0@student.42seoul.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 22:38:17 by jeholee           #+#    #+#             */
/*   Updated: 2023/02/14 22:44:08 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	char	*r_dest;

	r_dest = dest;
	while (*(dest))
		dest++;
	while (*(src))
		*(dest++) = *(src++);
	*(dest++) = '\0';
	return (r_dest);
}

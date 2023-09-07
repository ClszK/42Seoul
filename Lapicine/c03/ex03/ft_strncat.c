/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <dlwpgns0@student.42seoul.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 22:45:08 by jeholee           #+#    #+#             */
/*   Updated: 2023/02/14 23:02:24 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*r_dest;

	r_dest = dest;
	while (*(dest))
		dest++;
	while (*(src) && (nb--) > 0)
		*(dest++) = *(src++);
	*(dest) = '\0';
	return (r_dest);
}

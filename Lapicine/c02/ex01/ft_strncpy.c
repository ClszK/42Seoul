/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 08:25:29 by jeholee           #+#    #+#             */
/*   Updated: 2023/02/14 15:20:06 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char	*r_dest;

	r_dest = dest;
	while (*(src) && n > 0)
	{	
		*(dest++) = *(src++);
		n--;
	}
	while (n > 0)
	{
		*(dest++) = '\0';
		n--;
	}
	return (r_dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 00:53:17 by jeholee           #+#    #+#             */
/*   Updated: 2023/03/18 17:37:43 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t count, size_t size)
{
	void				*r_colloc;
	size_t				pos;
	size_t				i;

	i = 0;
	pos = 0;
	r_colloc = malloc(count * size);
	if (r_colloc == NULL)
		return (NULL);
	ft_bzero(r_colloc, count * size);
	return (r_colloc);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:25:16 by jeholee           #+#    #+#             */
/*   Updated: 2023/03/20 18:46:29 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*node;

	if (del == NULL || lst == NULL)
		return ;
	while (*(lst))
	{
		node = (*(lst))->next;
		ft_lstdelone(*(lst), del);
		*(lst) = node;
	}
}

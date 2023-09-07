/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:22:58 by jeholee           #+#    #+#             */
/*   Updated: 2023/02/21 22:10:18 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive(int nb, int root)
{
	if (root * root == nb)
		return (root);
	if (root * root > nb || root > 50000)
		return (0);
	return (ft_recursive(nb, root + 1));
}

int	ft_sqrt(int nb)
{
	return (ft_recursive(nb, 1));
}

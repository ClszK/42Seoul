/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 01:01:42 by jeholee           #+#    #+#             */
/*   Updated: 2023/02/21 01:03:13 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	r_nb;

	r_nb = 1;
	if (nb < 0)
		return (0);
	while (nb > 0)
		r_nb *= (nb--);
	return (r_nb);
}

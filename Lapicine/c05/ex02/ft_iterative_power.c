/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 01:16:08 by jeholee           #+#    #+#             */
/*   Updated: 2023/02/21 01:03:09 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	nb_power;

	nb_power = 1;
	if (power < 0)
		return (0);
	while ((power--) > 0)
		nb_power *= nb;
	return (nb_power);
}

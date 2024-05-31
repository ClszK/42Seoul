/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 04:53:06 by jeholee           #+#    #+#             */
/*   Updated: 2023/02/21 20:55:30 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	per;

	per = 2;
	while (per <= nb / per)
	{
		if (nb % per == 0)
			return (0);
		per++;
	}
	return (1);
}

int	ft_next(int nb)
{
	int	i;

	i = nb;
	while (!ft_is_prime(i))
		i++;
	return (i);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 1)
		return (2);
	return (ft_next(nb));
}

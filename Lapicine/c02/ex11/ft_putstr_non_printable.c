/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:41:06 by jeholee           #+#    #+#             */
/*   Updated: 2023/02/14 02:53:27 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_non_printable(unsigned char str)
{
	if ((str >= 0 && str <= 31)
		|| (str >= 127))
		return (1);
	return (0);
}

void	ft_putstr_non_printable(char *str)
{
	char	*hex;

	hex = "0123456789abcdef";
	while (*(str))
	{
		if (ft_is_non_printable(*(str)))
		{
			write(1, "\\", 1);
			write(1, &hex[(unsigned char)*(str) / 16], 1);
			write(1, &hex[(unsigned char)*(str) % 16], 1);
			str++;
		}
		else
			write(1, str++, 1);
	}
}

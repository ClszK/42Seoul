/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:45:10 by jeholee           #+#    #+#             */
/*   Updated: 2023/02/20 18:48:49 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*(str))
		write(1, str++, 1);
	write(1, "\n", 1);
}

int	main(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i <= argc - 1)
		ft_putstr(argv[i++]);
	return (0);
}

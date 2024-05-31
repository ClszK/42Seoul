/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:39:15 by jeholee           #+#    #+#             */
/*   Updated: 2023/02/20 18:42:46 by jeholee          ###   ########.fr       */
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
	if (argc != 1)
		return (-1);
	ft_putstr(argv[0]);
	return (0);
}

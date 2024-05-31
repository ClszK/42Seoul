/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 01:24:52 by jeholee           #+#    #+#             */
/*   Updated: 2023/03/02 01:51:50 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	main(int argc, char *argv[])
{
	int	fd;

	if (argc == 1)
	{
		ft_putstr("File name missing.\n");
		return (-1);
	}
	else if (argc >= 3)
	{
		ft_putstr("Too many arguments.\n");
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("Cannot read file.\n");
		return (-1);
	}
	ft_print_file(fd);
	return (0);
}

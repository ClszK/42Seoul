/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 03:55:35 by jeholee           #+#    #+#             */
/*   Updated: 2023/03/02 10:11:50 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int	main(int argc, char *argv[])
{
	int	i;
	int	fd;

	i = 1;
	if (argc == 1)
		ft_print_file(0);
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd < 0)
			ft_error_print(argv, i);
		else
			if (ft_print_file(fd) == -1)
				ft_error_print(argv, i);
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 03:55:35 by jeholee           #+#    #+#             */
/*   Updated: 2023/03/02 12:39:39 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int	main(int argc, char *argv[])
{
	int	i;
	int	fd;

	if (argc == 1)
		ft_n_print(0, 1);
	if (argv[1][0] == '-')
	{
		if (argv[1][1] == 'c')
			return (0);
		else
		{
			ft_error_illegal_option(argv);
			return (0);
		}
	}
	i = 1;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd < 0)
			ft_error_print(argv, i);
		else
			if (ft_n_print(fd, 5) == -1)
				ft_error_print(argv, i);
		i++;
	}
	return (0);
}

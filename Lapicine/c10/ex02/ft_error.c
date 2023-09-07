/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 05:57:30 by jeholee           #+#    #+#             */
/*   Updated: 2023/03/02 12:39:12 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

void	ft_error_print(char **argv, int i)
{
	ft_putstr(basename(argv[0]));
	ft_putstr(": ");
	ft_putstr(argv[i]);
	ft_putstr(": ");
	ft_putstr(strerror(errno));
	ft_putstr("\n");
}

void	ft_error_illegal_option(char **argv)
{
	ft_putstr(basename(argv[0]));
	ft_putstr(": illegal option -- ");
	ft_putchar(argv[1][1]);
	ft_putstr("\nusage: tail [-F | -f | -r]\
[-q] [-b # | -c # | -n #] [file ...]\n");
}
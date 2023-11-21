/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh <ljh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 02:44:13 by ljh               #+#    #+#             */
/*   Updated: 2023/11/20 13:38:42 by ljh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_strerror(char *progname, char *str)
{
	ft_putstr_fd(progname, 2);
	ft_putstr_fd(": ",2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd(": ",2);
	ft_putstr_fd(str, 2);
	ft_putchar_fd('\n', 2);
	ft_printf("%s: %s: %s\n", progname, strerror(errno), str);
}

void	perror_exit(char *progname)
{
	perror(progname);
	exit(EXIT_FAILURE);
}

void	error_exit(char *progname, char *str, char *str2)
{
	ft_putstr_fd(progname, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	if (str2 != NULL)
	{
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd(str2, STDERR_FILENO);
	}
	ft_putchar_fd('\n', STDERR_FILENO);
	exit(EXIT_FAILURE);
}
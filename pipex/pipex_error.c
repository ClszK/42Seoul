/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 02:44:13 by ljh               #+#    #+#             */
/*   Updated: 2023/11/27 10:31:49 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_strerror(char *progname, char *str)
{

	// ft_putstr_fd(ft_strrchr(progname, '/') + 1, STDERR_FILENO);
	ft_putstr_fd(progname, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(strerror(errno), STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
}

void	perror_exit(char *progname)
{
	perror(ft_strrchr(progname, '/') + 1);
	exit(EXIT_FAILURE);
}

void	error_exit(char *progname, char *str, char *str2, int code)
{
	ft_putstr_fd(ft_strrchr(progname, '/') + 1, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	if (str2 != NULL)
	{
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd(str2, STDERR_FILENO);
	}
	ft_putchar_fd('\n', STDERR_FILENO);
	exit(code);
}

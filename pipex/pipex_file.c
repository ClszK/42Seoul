/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh <ljh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 02:54:22 by ljh               #+#    #+#             */
/*   Updated: 2023/11/19 07:10:15 by ljh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int     is_file_access(char *progname, char *filename, int mode)
{
    errno = 0;
    if (access(filename, mode) == 0)
        return (1);
    if (errno != 0)
        print_strerror(progname, filename);
    return (0);
}

int		open_file(char *progname, char *filename, int mode)
{
	int	omode;
	int	rfd;

	if (mode == R_OK)
		omode = O_RDONLY;
	else
		omode = O_WRONLY | O_TRUNC | O_CREAT;
	if (mode != R_OK || is_file_access(progname, filename, mode))
    {
		errno = 0;
		rfd = open(filename, omode);
		if (rfd == -1 && errno != 0)
		{
			print_strerror(progname, filename);
			return (-1);
		}
		return (rfd);
    }
	return (-1);
}

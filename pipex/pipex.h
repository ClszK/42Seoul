/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:24:57 by jeholee           #+#    #+#             */
/*   Updated: 2023/11/14 21:31:41 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
        open, close, read, write,
        malloc, free, perror,
        strerror, access, dup, dup2,
        execve, exit, fork, pipe,
        unlink, wait, waitpid
*/

#ifndef PIPE_H
# define PIPE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include "libft/libft.h"
# include <errno.h>

#endif
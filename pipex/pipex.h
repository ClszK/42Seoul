/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh <ljh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:24:57 by jeholee           #+#    #+#             */
/*   Updated: 2023/11/21 07:38:48 by ljh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
        open, close, read, write,
        malloc, free, perror,
        strerror, access, dup, dup2,
        execve, exit, fork, pipe,
        unlink, wait, waitpid
*/

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <errno.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_pinfo
{
    int     fd[2];
    int     cmd_cnt;
    int     **pfd;
    char    **path;
    pid_t   pid;
}   t_pinfo;

typedef struct s_parse
{
    char	*start;
    char	*end;
	int		size;
}   t_parse;


void	print_strerror(char *progname, char *str);
void	perror_exit(char *progname);
void	error_exit(char *progname, char *str, char *str2);

int		**pipe_create(char *progname, int pipe_cnt);
void	pipe_close(int **pfd, int pipe_cnt, int pos);
void	dup_std_fd(t_pinfo *info, int i);

int     is_file_access(char *progname, char *filename, int mode);
int		open_file(char *progname, char *filename, int mode);

char	**find_path(char *progname, char *envp[]);
char	*path_cmd(char *progname, char *path, char *cmd);

//파일을 찾을 수 없는 경우 등, pipe 쓰기 부분을 닫아줌으로써 pipe 읽기쪽으로 EOF를 보내서 pipe 대기를 풀어버린다.

#endif
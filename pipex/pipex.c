/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 02:54:20 by jeholee           #+#    #+#             */
/*   Updated: 2023/11/14 20:57:58 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_strerror(char *progname, char *str)
{
	ft_printf("%s: %s: %s\n", progname, strerror(errno), str);
}

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
		omode = O_WRONLY;
	if (is_file_access(progname, filename, mode))
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

int	**pipe_create(char *progname, int pipecnt)
{
	int	**pipefd;
	int	i;

	i = 0;
	errno = 0;
	pipefd = (int **)malloc(sizeof(int *) * pipecnt);
	if (pipefd == NULL)
	{
		ft_printf("%s: %s\n", progname, strerror(errno));
		exit(EXIT_FAILURE);
	}
	while (i < pipecnt)
	{
		pipefd[i] = (int *)malloc(sizeof(int) * 2);
		if (pipefd[i] == NULL || pipe(pipefd[i]) < 0)
		{
			ft_printf("%s: %s\n", progname, strerror(errno));
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (pipefd);
}

void	pipe_close(int **pfd, int cmd_cnt)
{
	cmd_cnt--;
	while (cmd_cnt >= 0)
	{
		close(pfd[cmd_cnt][0]);
		close(pfd[cmd_cnt][1]);
		cmd_cnt--;
	}
}

int main(int argc, char *argv[])
{
	int		fd[2];
	pid_t	pid;
	int		i;
	int		**pfd;

    fd[0] = open_file(argv[0], argv[1], R_OK);
    fd[1] = open_file(argv[0], argv[argc - 1], W_OK);
	pfd = pipe_create(argv[0], argc - 3);
	i = 0;
	while (i < argc - 3)
	{
		pid = fork();
		if (pid < 0)
		{
			ft_printf("%s: %s\n", argv[0], strerror(errno));
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
			i++;
		else
		{
			ft_printf("%d\n", i);
			if (i != 0)
				dup2(pfd[i - 1][0], STDIN_FILENO);
			else
			{
				dup2(fd[0], STDIN_FILENO);
				close(fd[0]);
			}
			if (i != argc - 4)
				dup2(pfd[i][1], STDOUT_FILENO);
			else
			{
				dup2(fd[1], STDOUT_FILENO);
				close(fd[1]);
			}
			// pipe_close(pfd, argc - 3);
			ft_printf("%s\n", argv[i + 1]);
			// execve(argv[i + 1], NULL, NULL);
			exit(EXIT_FAILURE);
		}
	}
	while (i < argc - 3)
	{
		wait(NULL);
		i++;
	}
	exit(EXIT_SUCCESS);
    return (0);
}

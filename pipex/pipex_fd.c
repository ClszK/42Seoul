/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 02:52:16 by ljh               #+#    #+#             */
/*   Updated: 2023/11/27 10:16:19 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	**pipe_create(char *progname, int pipe_cnt)
{
	int	**pipefd;
	int	i;

	i = 0;
	errno = 0;
	pipefd = (int **)malloc(sizeof(int *) * pipe_cnt);
	if (pipefd == NULL)
		perror_exit(progname);
	while (i < pipe_cnt)
	{
		pipefd[i] = (int *)malloc(sizeof(int) * 2);
		if (pipefd[i] == NULL || pipe(pipefd[i]) < 0)
			perror_exit(progname);
		i++;
	}
	return (pipefd);
}

void	pipe_close(char *progname, int **pfd, int pipe_cnt, int pos)
{
	int	i;

	i = 0;
	errno = 0;
	while (i < pipe_cnt)
	{
		if (i != pos)
			close(pfd[i][1]);
		if (i != pos - 1)
			close(pfd[i][0]);
		i++;
	}
	if (errno != 0)
		perror(progname);
}

void	dup_std_fd(char *progname, t_pinfo *info, int i)
{
	errno = 0;
	if (i != 0)
	{
		if (dup2(info->pfd[i - 1][0], STDIN_FILENO) < 0)
			exit(EXIT_FAILURE);
	}
	else if (!(info->fd[0] == -1))
	{
		if (dup2(info->fd[0], STDIN_FILENO) < 0)
			exit(EXIT_FAILURE);
	}
	if (i != info->cmd_cnt - 1)
	{
		if (dup2(info->pfd[i][1], STDOUT_FILENO) < 0)
			exit(EXIT_FAILURE);
	}
	else
	{
		if (dup2(info->fd[1], STDOUT_FILENO) < 0)
			exit(EXIT_FAILURE);
	}
	pipe_close(progname, info->pfd, info->cmd_cnt - 1, i);
}

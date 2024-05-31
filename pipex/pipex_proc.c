/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_proc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh <ljh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 23:38:42 by jeholee           #+#    #+#             */
/*   Updated: 2024/01/11 12:31:32 by ljh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pinfo_set(t_pinfo *info, int argc, char *argv[], char *envp[])
{
	info->cmd_cnt = argc - 3;
	info->fd[0] = open_file(argv[0], argv[1], R_OK);
	info->fd[1] = open_file(argv[0], argv[argc - 1], W_OK);
	if (info->fd[1] == -1)
		print_strerror(argv[0], argv[argc -1]);
	info->pfd = pipe_create(argv[0], info->cmd_cnt - 1);
	info->path = find_path(argv[0], envp);
}

void	child_process(t_pinfo *info, int i, char *argv[], char *envp[])
{
	char	*cmdline;
	char	**exec_cmd;
	char	*file;

	dup_std_fd(argv[0], info, i);
	if (i == 0 && info->fd[0] == -1)
		exit(EXIT_FAILURE);
	cmdline = ft_strtrim(argv[i + 2], " ");
	exec_cmd = parse_cmd(argv[0], argv[i + 2]);
	file = cmd_location(argv[0], info->path, cmdline);
	if (file == NULL)
		exit(0);
	errno = 0;
	// execve(file, exec_cmd, envp);
	exit(EXIT_FAILURE);
}

void	wait_child(t_pinfo *info)
{
	int	status;
	int	i;

	i = -1;
	while (++i < info->cmd_cnt)
	{
		info->pid = wait(&status);
		if (info->last_pid == info->pid)
			info->last_status = status;
	}
}

void	all_close(t_pinfo *info)
{
	int	i;

	i = -1;
	if (info->fd[0] != -1)
		close(info->fd[0]);
	if (info->fd[1] != -1)
		close(info->fd[1]);
	while (info->path[++i])
		free(info->path[i]);
	free(info->path);
	i = -1;
	while (++i < info->cmd_cnt - 1)
	{
		close(info->pfd[i][0]);
		close(info->pfd[i][1]);
		free(info->pfd[i]);
	}
	free(info->pfd);
}

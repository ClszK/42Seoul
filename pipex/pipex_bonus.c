/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 04:12:19 by jeholee           #+#    #+#             */
/*   Updated: 2023/11/29 21:47:27 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*heredoc_process(t_pinfo *info, int argc, char *argv[], char *envp[])
{
	if (ft_strcmp(argv[1], "here_doc") == 0)
		return (pinfo_set_bonus(info, argc, argv, envp));
	pinfo_set(info, argc, argv, envp);
	return (NULL);
}

void	all_close_bonus(t_pinfo *info, char *tmp_name)
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
	if (tmp_name != NULL)
	{
		unlink(tmp_name);
		free(tmp_name);
	}
}

void	check_leak(void)
{
	char	*test = "leaks --list ";
	char	*test2;
	char 	*test3 = ft_itoa(getpid());

	test2 = ft_strjoin(test, test3);
	ft_putstr_fd(test2, 2);
	free(test3);
	system(test2);
	free(test2);	
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pinfo	info;
	char	*tmp_name;
	int		i;

	if (argc < 5)
		return (1);
	tmp_name = heredoc_process(&info, argc, argv, envp);
	i = -1;
	while (++i < info.cmd_cnt)
	{
		errno = 0;
		info.pid = fork();
		atexit(check_leak);
		if (info.pid < 0)
			perror_exit(argv[0]);
		else if (info.pid == 0)
		{
			if (tmp_name != NULL)
				child_process_bonus(&info, i, argv, envp);
			child_process(&info, i, argv, envp);
		}
		info.last_pid = info.pid;
	}
	all_close_bonus(&info, tmp_name);
	wait_child(&info);
	return (((*(int *)&(info.last_status)) >> 8) & 0x000000ff);
}

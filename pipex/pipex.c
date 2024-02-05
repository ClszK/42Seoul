/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh <ljh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 02:54:20 by jeholee           #+#    #+#             */
/*   Updated: 2024/01/11 12:25:07 by ljh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_leak(void)
{
	system("leaks pipex");
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pinfo	info;
	int		i;

	if (argc < 5)
		return (1);
	pinfo_set(&info, argc, argv, envp);
	i = -1;
	while (++i < info.cmd_cnt)
	{
		errno = 0;
		info.pid = fork();
		atexit(check_leak);
		if (info.pid < 0)
			perror_exit(argv[0]);
		else if (info.pid == 0)
			child_process(&info, i, argv, envp);
		info.last_pid = info.pid;
	}
	all_close(&info);
	wait_child(&info);
	return (((*(int *)&(info.last_status)) >> 8) & 0x000000ff);
}

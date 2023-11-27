/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 02:54:20 by jeholee           #+#    #+#             */
/*   Updated: 2023/11/27 10:07:02 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_pinfo	info;
	int		i;

	if (argc != 5)
		return (0);
	pinfo_set(&info, argc, argv, envp);
	i = -1;
	while (++i < info.cmd_cnt)
	{
		errno = 0;
		info.pid = fork();
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

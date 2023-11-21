/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh <ljh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 02:55:27 by ljh               #+#    #+#             */
/*   Updated: 2023/11/20 13:28:22 by ljh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**find_path(char *progname, char *envp[])
{
	int		i;
	char	**path;

	i = 0;
	errno = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH", 4) != NULL)
		{
			path = ft_split(envp[i] + 5, ':');
			if (path == NULL && errno != 0)
				perror_exit(progname);
			return (path);
		}
		i++;
	}
	error_exit(progname, "path not found", NULL);
	return (NULL);
}

char	*path_cmd(char *progname, char *path, char *cmd)
{
	char	*rcmd;
	char	*tmp;

	errno = 0;
	rcmd = ft_strjoin(path, "/");
	if (rcmd == NULL && errno != 0)
		perror_exit(progname);
	tmp = rcmd;
	rcmd = ft_strjoin(rcmd, cmd);
	free(tmp);
	if (rcmd == NULL && errno != 0)
		perror_exit(progname);
	return (rcmd);
}
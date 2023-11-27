/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 02:55:27 by ljh               #+#    #+#             */
/*   Updated: 2023/11/27 10:03:41 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**find_path(char *progname, char *envp[])
{
	int		i;
	char	**path;
	char	*basic_path;

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
	basic_path = "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin";
	path = ft_split(basic_path, ':');
	if (path == NULL && errno != 0)
		perror_exit(progname);
	return (path);
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

char	*collect_path(char *progname, char **path, char *cmd)
{
	int		i;
	char	*cmd_path;

	i = -1;
	while (path[++i] && *cmd)
	{
		cmd_path = path_cmd(progname, path[i], cmd);
		if ((access(cmd_path, X_OK) == 0))
			return (cmd_path);
		if (errno == EACCES)
			break ;
		errno = 0;
		free(cmd_path);
	}
	return (NULL);
}

char	*cmd_location(char *progname, char **path, char *cmdline)
{
	int		i;
	char	*cmd_path;
	char	*cmd;

	i = -1;
	cmd = ft_substr(cmdline, 0, (size_t)(ft_strchr(cmdline, ' ') - cmdline));
	free(cmdline);
	if (cmd == NULL)
		perror_exit(progname);
	cmd_path = NULL;
	(void)escape_process(cmd, ft_strchr(cmd, '\0'));
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
			return (cmd);
	}
	else
		cmd_path = collect_path(progname, path, cmd);
	if (cmd_path)
		return (cmd_path);
	if (errno == EACCES)
		error_exit(progname, cmd, strerror(errno), 126);
	error_exit(progname, cmd, "command not found", 127);
	return (NULL);
}

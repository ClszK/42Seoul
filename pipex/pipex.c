/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh <ljh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 02:54:20 by jeholee           #+#    #+#             */
/*   Updated: 2023/11/21 14:06:56 by ljh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pull_section(char *str)
{
	int i;

	i = 0;
	while (str[i + 1])
	{
		str[i] = str[i + 1];
		i++;
	}
	str[i] = '\0';
}

int	escape_process(char *str, char *end)
{
	int	cnt;

	cnt = 0;
	while (*str && str != end)
	{
		if (*str == '\\')
		{
			pull_section(str);
			cnt++;
		}
		str++;
	}
	return (cnt);
}

void	parse_pos(t_parse *info)
{
	char	c;

	while (*info->start == ' ')
		info->start++;
	if (*info->start == '"' || *info->start == '\'')
	{
		c = *info->start;
		info->end = ft_strchr(++(info->start), c);
		while (*(info->end - 1) == '\\')
			info->end = ft_strchr(++(info->end), c);
	}
	else
		info->end = ft_strchr(info->start, ' ');
	if (info->end == NULL)
		info->end = info->start + ft_strlen(info->start);
	info->size = info->end - info->start;
}

char	**split_size(char *progname, char *cmdline)
{
	int		size;
	char	**rstr;
	t_parse	str;

	str.start = cmdline;
	size = 0;
	while (*str.start)
	{
		parse_pos(&str);
		str.start = str.end + 1;
		size++;
	}
	rstr = (char **)malloc(sizeof(char *) * (size + 1));
	if (rstr == NULL)
		perror(progname);
	return (rstr);
}

char	**parse_cmd(char *progname, char *cmdline)
{
	int		i;
	int		end_mov;
	char	**rstr;
	t_parse	str;

	i = 0;
	str.start = cmdline;
	rstr = split_size(progname, cmdline);
	while (*str.start)
	{
		parse_pos(&str);
		end_mov = escape_process(str.start, str.end);
		str.size -= end_mov;
		str.end -= end_mov;
		rstr[i] = (char *)malloc(sizeof(char) * (str.size + 1));
		if (rstr[i] == NULL)
			perror_exit(progname);
		ft_strlcpy(rstr[i], str.start, str.size + 1);
		str.start = str.end + 1;
		i++;
	}
	rstr[i] = NULL;
	return (rstr);
}

char	**exec_argv(char *progname, char **path, char *cmdline, int i)
{
	char	*cmd_path;
	char	**cmd_av;
	char	*cmd;

	cmd = ft_substr(cmdline, 0, (size_t)(ft_strchr(cmdline, ' ') - cmdline));
	(void)escape_process(cmd, ft_strchr(cmd, '\0'));
	if ((access(cmd, X_OK) == 0))
		return (parse_cmd(progname, cmdline));
	while (path && path[++i])
	{
		cmd_path = path_cmd(progname, path[i], cmd);
		if ((access(cmd_path, X_OK) == 0))
		{
			free(cmd_path);
			cmd_path = path_cmd(progname, path[i], cmdline);
			cmd_av = parse_cmd(progname, cmd_path);
			free(cmd_path);
			return (cmd_av);
		}
		else
			errno = 0;
		free(cmd_path);
	}
	error_exit(progname, "command not found", cmd);
	return (NULL);
}

void	all_close(t_pinfo *info)
{
	int	i;

	i = -1;
	close(info->fd[0]);
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

void	check_leak(void)
{
	system("leaks pipex");
}

int main(int argc, char *argv[], char *envp[])
{
	t_pinfo	info;
	char	**exec_cmd;
	int		i;
	int		status;

	// if (argc != 5)
	// 	return (0);
	info.cmd_cnt = argc - 3;
    info.fd[0] = open_file(argv[0], argv[1], R_OK);
    info.fd[1] = open_file(argv[0], argv[argc - 1], W_OK);
	info.pfd = pipe_create(argv[0], info.cmd_cnt - 1);
	info.path = find_path(argv[0], envp);
	i = 0;
	while (i < info.cmd_cnt)
	{
		errno = 0;
		info.pid = fork();
		if (info.pid < 0)
			perror_exit(argv[0]);
		else if (info.pid == 0)
		{
			dup_std_fd(&info, i);
			if (i == 0 && info.fd[0] == -1)
				exit(EXIT_FAILURE);
			if (argv[i + 2][0] == '.')
				exec_cmd = exec_argv(argv[0], NULL, argv[i + 2], -1);
			else
				exec_cmd = exec_argv(argv[0], info.path, argv[i + 2], -1);
			errno = 0;
			execve(exec_cmd[0], exec_cmd, envp);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	all_close(&info);
	while(info.cmd_cnt--)
		info.pid = wait(&status);
	return (WEXITSTATUS(status));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:01:02 by jeholee           #+#    #+#             */
/*   Updated: 2023/11/29 21:29:04 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	tmpfile_create(char *progname, char **tmp_name)
{
	char	*itoa_str;
	char	*tmp;
	int		i;
	int		fd;

	i = 0;
	tmp = "here_doc_tmp";
	errno = 0;
	while (++i < 2147483647)
	{
		itoa_str = ft_itoa(i);
		*tmp_name = ft_strjoin(tmp, itoa_str);
		if (*tmp_name == NULL)
			exit(EXIT_FAILURE);
		free(itoa_str);
		fd = open(*tmp_name, O_EXCL | O_CREAT | O_RDWR, 0644);
		if (fd != -1)
			return (fd);
		free(*tmp_name);
		if (errno != EEXIST)
			perror_exit(progname);
	}
	return (-1);
}

void	stdin_heredoc(char *progname, char *end_id, int tmp_fd)
{
	char	*readline;
	size_t	len;

	errno = 0;
	len = ft_strlen(end_id);
	while (1)
	{
		ft_printf("> ");
		readline = get_next_line(STDIN_FILENO);
		if (readline == NULL && errno != 0)
			perror_exit(progname);
		if (len == ft_strlen(readline) - 1 && \
			!ft_strncmp(readline, end_id, len))
		{
			free(readline);
			return ;
		}
		write(tmp_fd, readline, ft_strlen(readline));
		free(readline);
	}
}

void	child_process_bonus(t_pinfo *info, int i, char *argv[], char *envp[])
{
	char	*cmdline;
	char	**exec_cmd;
	char	*file;

	dup_std_fd(argv[0], info, i);
	if (i == 0 && info->fd[0] == -1)
		exit(EXIT_FAILURE);
	cmdline = ft_strtrim(argv[i + 3], " ");
	exec_cmd = parse_cmd(argv[0], argv[i + 3]);
	file = cmd_location(argv[0], info->path, cmdline);
	if (file == NULL)
		exit(0);
	errno = 0;
	execve(file, exec_cmd, envp);
	exit(EXIT_FAILURE);
}

char	*pinfo_set_bonus(t_pinfo *info, int argc, char *argv[], char *envp[])
{
	int		tmp_fd;
	char	*tmp_name;

	tmp_fd = tmpfile_create(argv[0], &tmp_name);
	stdin_heredoc(argv[0], argv[2], tmp_fd);
	close(tmp_fd);
	info->cmd_cnt = argc - 4;
	info->fd[0] = open_file(argv[0], tmp_name, R_OK);
	info->fd[1] = open(argv[argc -1], O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (info->fd[1] == -1)
		print_strerror(argv[0], argv[argc -1]);
	info->pfd = pipe_create(argv[0], info->cmd_cnt - 1);
	info->path = find_path(argv[0], envp);
	return (tmp_name);
}

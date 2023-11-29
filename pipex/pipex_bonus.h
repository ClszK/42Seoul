/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:59:07 by jeholee           #+#    #+#             */
/*   Updated: 2023/11/29 19:02:18 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <errno.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_pinfo
{
	int		fd[2];
	int		cmd_cnt;
	int		**pfd;
	char	**path;
	pid_t	pid;
	pid_t	last_pid;
	int		last_status;
}	t_pinfo;

typedef struct s_parse
{
	char	*start;
	char	*end;
	int		size;
}	t_parse;

void	print_strerror(char *progname, char *str);
void	perror_exit(char *progname);
void	error_exit(char *progname, char *str, char *str2, int code);

int		**pipe_create(char *progname, int pipe_cnt);
void	pipe_close(char *progname, int **pfd, int pipe_cnt, int pos);
void	dup_std_fd(char *progname, t_pinfo *info, int i);

int		is_file_access(char *progname, char *filename, int mode);
int		open_file(char *progname, char *filename, int mode);

char	**find_path(char *progname, char *envp[]);
char	*path_cmd(char *progname, char *path, char *cmd);
char	*collect_path(char *progname, char **path, char *cmd);
char	*cmd_location(char *progname, char **path, char *cmdline);

void	pull_section(char *str);
int		escape_process(char *str, char *end);
void	parse_pos(t_parse *info);
char	**split_size(char *progname, char *cmdline);
char	**parse_cmd(char *progname, char *cmdline);

void	pinfo_set(t_pinfo *info, int argc, char *argv[], char *envp[]);
void	child_process(t_pinfo *info, int i, char *argv[], char *envp[]);
void	wait_child(t_pinfo *info);
void	all_close(t_pinfo *info);

char	*pinfo_set_bonus(t_pinfo *info, int argc, char *argv[], char *envp[]);
void	stdin_heredoc(char *progname, char *end_id, int tmp_fd);
void	child_process_bonus(t_pinfo *info, int i, char *argv[], char *envp[]);
char	*pinfo_set_bonus(t_pinfo *info, int argc, char *argv[], char *envp[]);

char	*heredoc_process(t_pinfo *info, int argc, char *argv[], char *envp[]);
void	all_close_bonus(t_pinfo *info, char *tmp_name);

#endif
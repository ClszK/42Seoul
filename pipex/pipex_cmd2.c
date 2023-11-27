/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cmd2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 23:36:45 by jeholee           #+#    #+#             */
/*   Updated: 2023/11/26 23:45:24 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pull_section(char *str)
{
	int	i;

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
	while (*info->start == ' ')
		info->start++;
	if (*info->start == '"')
	{
		info->end = ft_strchr(++(info->start), '"');
		while (info->end && *(info->end - 1) == '\\')
			info->end = ft_strchr(++(info->end), '"');
	}
	else if (*info->start == '\'')
		info->end = ft_strchr(++(info->start), '\'');
	else
		info->end = ft_strchr(info->start, ' ');
	if (info->end == NULL)
		info->end = info->start + ft_strlen(info->start);
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
		str.size = str.end - str.start;
		if (str.size == 0)
			break ;
		str.start = str.end;
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
	char	**rstr;
	t_parse	str;

	i = 0;
	str.start = cmdline;
	rstr = split_size(progname, cmdline);
	while (*str.start)
	{
		parse_pos(&str);
		if (*str.start != '\'')
			str.end -= escape_process(str.start, str.end);
		str.size = str.end - str.start;
		if (str.size == 0)
			break ;
		rstr[i] = (char *)malloc(sizeof(char) * (str.size + 1));
		if (rstr[i] == NULL)
			perror_exit(progname);
		ft_strlcpy(rstr[i], str.start, str.size + 1);
		str.start = str.end;
		i++;
	}
	rstr[i] = NULL;
	return (rstr);
}

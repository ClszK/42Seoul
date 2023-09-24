/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh <ljh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:49:18 by jeholee           #+#    #+#             */
/*   Updated: 2023/09/23 17:53:36 by ljh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_msg(t_map *m_cfg,char *msg)
{
	size_t	y;

	y = (size_t)(-1);
	if (m_cfg != NULL)
	{
		while (++y < m_cfg->y)
			free(m_cfg->map[y]);
		free(m_cfg->map);
		free(m_cfg);
	}
	if (msg == NULL)
		ft_printf("Error\n%s\n", strerror(errno));
	else
		ft_printf("Error\n%s\n", msg);
	exit(1);
}

void	close_fd(t_map *m_cfg, int fd)
{
	close(fd);
	error_msg(m_cfg, NULL);
}

char	*map_empty_check(t_map *m_cfg, int fd)
{
	char	*str;

	str = get_next_line(fd);
	if (str == NULL)
	{
		if (errno != 3)
			close_fd(m_cfg, fd);
		else
			error_msg(m_cfg, "Empty File");
	}
	return (str);
}

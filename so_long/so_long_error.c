/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh <ljh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:49:18 by jeholee           #+#    #+#             */
/*   Updated: 2023/09/26 10:58:10 by ljh              ###   ########.fr       */
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
	atexit(check_leak);
	exit(1);
}

void	close_fd(t_map *m_cfg, int fd)
{
	close(fd);
	error_msg(m_cfg, NULL);
}
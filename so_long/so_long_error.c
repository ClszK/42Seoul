/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:49:18 by jeholee           #+#    #+#             */
/*   Updated: 2023/09/27 06:21:37 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_msg(t_map *m_cfg, char *msg)
{
	size_t	y;

	y = (size_t)(-1);
	if (m_cfg != NULL)
	{
		map_free(m_cfg->map, m_cfg->y);
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

int	close_program(t_game *game)
{
	t_map	*m_cfg;

	m_cfg = game->m_cfg;
	while (m_cfg->y > 0)
	{
		m_cfg->y--;
		free(m_cfg->map[m_cfg->y]);
	}
	free(m_cfg->map);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	exit(0);
	return (0);
}

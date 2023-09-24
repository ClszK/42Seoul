/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh <ljh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:28:28 by jeholee           #+#    #+#             */
/*   Updated: 2023/09/23 18:01:18 by ljh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*map_generate(char *path)
{
	t_map	*m_cfg;

	m_cfg = node_map_generate();
	map_height(m_cfg, path);
	map_read(m_cfg, path);
	// for (size_t i = 0 ; i < m_cfg->y; i++)
	// 	ft_printf("%s", m_cfg->map[i]);
	return (m_cfg);
}

void	map_height(t_map *m_cfg, char *path)
{
	int		fd;
	char	*str;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_msg(m_cfg, NULL);
	str = map_empty_check(m_cfg, fd);
	while (str)
	{
		free(str);
		m_cfg->y++;
		str = get_next_line(fd);
		if (str == NULL && errno != ERRNO_OK)
			close_fd(m_cfg, fd);
	}
	m_cfg->map = (char **)malloc(sizeof(char *) * (m_cfg->y));
	if (m_cfg->map == NULL)
		close_fd(m_cfg, fd);
	if (close(fd) < 0)
		error_msg(m_cfg, NULL);
}

void	map_read(t_map *m_cfg, char *path)
{
	int		fd;
	char	*str;
	size_t	i;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_msg(m_cfg, NULL);
	str = get_next_line(fd);
	if (str == NULL)
		close_fd(m_cfg, fd);
	m_cfg->x = ft_strlen(str) - 1;
	while (str)
	{
		m_cfg->map[i++] = str;
		str = get_next_line(fd);
		if (str == NULL && errno != ERRNO_OK)
		{
			m_cfg->y = --i;
			close_fd(m_cfg, fd);
		}
	}
	if (close(fd) < 0)
		error_msg(m_cfg, NULL);
}

t_map	*node_map_generate()
{
	t_map	*node;
	node = (t_map*)malloc(sizeof(t_map));
	if (node == NULL)
		error_msg(node, NULL);
	node->c_cnt = 0;
	node->e_cnt = 0;
	node->p_cnt = 0;
	node->map = NULL;
	node->x = 0;
	node->y = 0;
	node->pos_x = 0;
	node->pos_y = 0;
	return (node);
}

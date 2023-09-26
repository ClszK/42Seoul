/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:28:28 by jeholee           #+#    #+#             */
/*   Updated: 2023/09/27 04:53:14 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*map_generate(char *path)
{
	t_map	*m_cfg;
	size_t	len;

	len = ft_strlen(path);
	m_cfg = node_map_generate();
	map_height(m_cfg, path);
	if (len < 4 || ft_strcmp(".ber", &path[len - 4]) != 0)
		error_msg(NULL, "No Extention.");
	map_read(m_cfg, path);
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
	if (m_cfg->y >= 20)
		error_msg(NULL, "Invalid Size");
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
			m_cfg->y = i;
			close_fd(m_cfg, fd);
		}
	}
	if (close(fd) < 0)
		error_msg(m_cfg, NULL);
}

void	map_validation_check(t_map *m_cfg)
{
	size_t	y;

	y = 0;
	while (y < m_cfg->y)
	{
		map_rectangle_check(m_cfg, m_cfg->map[y], y);
		map_component_check(m_cfg, m_cfg->map[y], y);
		y++;
	}
	if (m_cfg->c_cnt < 1 || m_cfg->e_cnt != 1 || m_cfg->p_cnt != 1)
		error_msg(m_cfg, "Invalid Component");
	map_path_check(m_cfg);
}

char	*map_empty_check(t_map *m_cfg, int fd)
{
	char	*str;

	str = get_next_line(fd);
	if (str == NULL)
	{
		if (errno != ERRNO_OK)
			close_fd(m_cfg, fd);
		else
			error_msg(m_cfg, "Empty File");
	}
	return (str);
}

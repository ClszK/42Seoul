/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh <ljh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:28:28 by jeholee           #+#    #+#             */
/*   Updated: 2023/09/22 06:57:49 by ljh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*map_generate(char *path);
int		map_height(t_map *m_cfg, char *path);
int		map_read(t_map *m_cfg, char *path);
t_map	*node_map_generate();
int		map_validation_check(t_map *m_cfg);
int		map_component_check(t_map *m_cfg, char *str, size_t y);
int		map_rectangle_check(t_map *m_cfg, char *str, size_t y);
char	**map_path_check(t_map *m_cfg);

t_map	*map_generate(char *path)
{
	t_map	*m_cfg;

	m_cfg = node_map_generate();
	if (m_cfg == NULL)
		return (NULL);

	if (map_height(m_cfg, path) < 0 || map_read(m_cfg, path) < 0)
		return (NULL);

	for(size_t i = 0; i < m_cfg->y; i++)
		ft_printf("%s", m_cfg->map[i]);
	ft_printf("\n\n");
	(void)map_validation_check(m_cfg);
	for(size_t i = 0; i < m_cfg->y; i++)
		ft_printf("%s", m_cfg->map[i]);
	ft_printf("\n\n");
	return (m_cfg);
}

int		map_height(t_map *m_cfg, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	while (get_next_line(fd))
		m_cfg->y++;
	m_cfg->map = (char **)malloc(sizeof(char *) * (m_cfg->y));
	close(fd);
	if (m_cfg->map == NULL)
		return (-1);
	return (1);
}

int		map_read(t_map *m_cfg, char *path)
{
	int		fd;
	char	*str;
	size_t	i;

	i = 0;
	fd = open(path, O_RDONLY);
	str = get_next_line(fd);
	m_cfg->x = ft_strlen(str) - 1;
	if (str == NULL)
		return (-1);
	while (str)
	{
		m_cfg->map[i++] = str;
		str = get_next_line(fd);
	}
	return (1);
}

t_map	*node_map_generate()
{
	t_map	*node;
	node = (t_map*)malloc(sizeof(t_map));
	if (node == NULL)
		return (NULL);
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

int		map_validation_check(t_map *m_cfg)
{
	size_t	y;

	y = 0;
	while (y < m_cfg->y)
	{
		if (\
		map_rectangle_check(m_cfg, m_cfg->map[y], y) < 0 || \
		map_component_check(m_cfg, m_cfg->map[y], y) < 0 )
			return (-1);
		y++;
	}
	map_path_check(m_cfg->map);
	if (m_cfg->c_cnt < 1 || m_cfg->e_cnt != 1 || m_cfg->p_cnt != 1)
	{
		ft_printf("fail components");
		return (-1);
	}
	return (1);
}

int		map_component_check(t_map *m_cfg, char *str, size_t y)
{
	size_t	x;

	x = 0;
	while (x < m_cfg->x)
	{
		if (str[x] == 'C')
			m_cfg->c_cnt++;
		else if(str[x] == 'E')
			m_cfg->e_cnt++;
		else if(str[x] == 'P')
		{
			m_cfg->p_cnt++;
			m_cfg->pos_x = x;
			m_cfg->pos_y = y;
		}
		else if(!(str[x] == '1' || str[x] == '0'))
		{
			ft_printf("fail components");
			return (-1);
		}
		x++;
	}
	return (1);
}

int		map_rectangle_check(t_map *m_cfg, char *str, size_t y)
{
	size_t	x;
	int		fail;

	x = 0;
	fail = 0;
	if (y == 0 || y == m_cfg->y - 1)
	{
		while (x < m_cfg->x)
			if (str[x++] != '1')
				fail = 1;
	}
	else
	{
		while (str[x] && str[x] != '\n')
			x++;
		if (!(str[0] == '1' && str[x - 1] == '1') || x != m_cfg->x)
			fail = 1;
	}
	if (fail == 1)
	{
		ft_printf("fail rectangle");
		return (-1);
	}
	return (1);
}

char	**map_path_check(t_map *m_cfg)
{
	size_t	y;
	char	**map_cpy;

	y = 0;
	map_cpy = (char **)malloc(sizeof(char *) * m_cfg->y);
	if (map_cpy == NULL)
		return (NULL);
	while (y < m_cfg->y)
		map_cpy[y++] = ft_strdup(m_cfg->map[y]);
	map_path_dfs(map_cpy, m_cfg->pos_x, m_cfg->pos_y);
	y = 0;
	while (y < m_cfg->pos_y)
	{
		// ft_str
	}
	return (map_cpy);
}

void	map_path_dfs(char **map, size_t x, size_t y)
{
	if (map[y][x] == '1')
		return ;
	if (map[y][x] == 'E')
	{
		map[y][x] = '1';
		return ;
	}
	map[y][x] = '1';
	map_path_dfs(map, x, y - 1);
	map_path_dfs(map, x, y + 1);
	map_path_dfs(map, x - 1, y);
	map_path_dfs(map, x + 1, y);
}
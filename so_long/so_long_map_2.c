/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:47:47 by jeholee           #+#    #+#             */
/*   Updated: 2023/10/08 12:16:33 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_component_check(t_map *m_cfg, char *str, size_t y)
{
	size_t	x;

	x = 0;
	while (x < m_cfg->x)
	{
		if (str[x] == 'C')
			m_cfg->c_cnt++;
		else if (str[x] == 'E')
			m_cfg->e_cnt++;
		else if (str[x] == 'P')
		{
			m_cfg->p_cnt++;
			m_cfg->pos_x = x;
			m_cfg->pos_y = y;
		}
		else if (!(str[x] == '1' || str[x] == '0'))
			error_msg(m_cfg, "Not Component");
		x++;
	}
}

void	map_rectangle_check(t_map *m_cfg, char *str, size_t y)
{
	size_t	x;

	x = 0;
	if (m_cfg->x >= 36)
		error_msg(m_cfg, "Invalid Size");
	while (str[x] && str[x] != '\n')
	{
		if ((y == 0 || y == m_cfg->y - 1) && str[x] != '1')
			error_msg(m_cfg, "Not Rectangle");
		x++;
	}
	if (!(str[0] == '1' && str[x - 1] == '1') || x != m_cfg->x)
		error_msg(m_cfg, "Not Rectangle");
}

void	map_path_check(t_map *m_cfg)
{
	size_t	y;
	char	**map_cpy;

	y = (size_t)(-1);
	errno = ERRNO_OK;
	map_cpy = (char **)malloc(sizeof(char *) * m_cfg->y);
	if (map_cpy == NULL)
		error_msg(m_cfg, NULL);
	while (++y < m_cfg->y)
	{
		map_cpy[y] = ft_strdup(m_cfg->map[y]);
		if (map_cpy[y] == NULL)
		{
			map_free(map_cpy, y);
			error_msg(m_cfg, NULL);
		}
	}
	map_path_dfs(map_cpy, m_cfg->pos_x, m_cfg->pos_y);
	while (--y > 0)
	{
		if (ft_strchr(map_cpy[y], 'C') || ft_strchr(map_cpy[y], 'P') || \
			ft_strchr(map_cpy[y], 'E'))
			error_msg(m_cfg, "Not Valid Path");
	}
	map_free(map_cpy, m_cfg->y);
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

void	map_free(char **map_cpy, size_t y)
{
	if (map_cpy == NULL)
		return ;
	while (y > 0)
		free(map_cpy[--y]);
	free(map_cpy);
}

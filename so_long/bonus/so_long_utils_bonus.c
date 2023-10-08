/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 05:59:04 by jeholee           #+#    #+#             */
/*   Updated: 2023/10/08 13:29:53 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemy_generate(t_game *game, size_t i, size_t y)
{
	t_map	*m_cfg;
	char	**map_cpy;

	srand((unsigned int)time(NULL));
	m_cfg = game->m_cfg;
	i = 0;
	y = 0;
	while (i < 20)
	{
		map_cpy = map_copy(m_cfg);
		if (map_cpy == NULL)
		{
			i++;
			continue ;
		}
		enemy_path_dfs(map_cpy, m_cfg->pos_x, m_cfg->pos_y);
		if (enemy_path_valid(m_cfg, map_cpy) == 1)
		{
			map_free(map_cpy, m_cfg->y);
			return ;
		}
		map_free(map_cpy, m_cfg->y);
		i++;
	}
	error_msg(m_cfg, "Fail Generate Enemy\n");
}

int	enemy_set(char **map, t_map	m_cfg, int x, int y)
{
	size_t	enemy_cnt;
	size_t	i;

	i = 0;
	if (m_cfg.y > m_cfg.x)
		enemy_cnt = m_cfg.x - 2;
	else
		enemy_cnt = m_cfg.y - 2;
	while (enemy_cnt-- > 0)
	{
		while (i++ < 50)
		{
			x = rand() % (m_cfg.x - 1) + 1;
			y = rand() % (m_cfg.y - 1) + 1;
			if (map[y][x] == '0')
			{
				map[y][x] = 'X';
				break ;
			}
		}
		if (i >= 50)
			return (-1);
		i = 0;
	}
	return (0);
}

char	**map_copy(t_map *m_cfg)
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
			while (y > 0)
				free(map_cpy[--y]);
			free(map_cpy);
			error_msg(m_cfg, NULL);
		}
	}
	if (enemy_set(map_cpy, *m_cfg, 0, 0) < 0)
	{
		map_free(map_cpy, y);
		return (NULL);
	}
	return (map_cpy);
}

void	enemy_path_dfs(char **map, size_t x, size_t y)
{
	if (map[y][x] == '1' || map[y][x] == '2')
		return ;
	if (map[y][x] == 'E')
	{
		map[y][x] = '1';
		return ;
	}
	if (map[y][x] == 'X')
	{
		map[y][x] = '2';
		return ;
	}
	map[y][x] = '1';
	enemy_path_dfs(map, x, y - 1);
	enemy_path_dfs(map, x, y + 1);
	enemy_path_dfs(map, x - 1, y);
	enemy_path_dfs(map, x + 1, y);
}

int	enemy_path_valid(t_map *m_cfg, char **map_cpy)
{
	size_t	y;
	size_t	x;

	y = m_cfg->y - 1;
	while (y > 0)
	{
		if (ft_strchr(map_cpy[y], 'E') || \
			ft_strchr(map_cpy[y], 'P') || \
			ft_strchr(map_cpy[y], 'C'))
			return (-1);
		y--;
	}
	x = 0;
	while (y < m_cfg->y)
	{
		while (x < m_cfg->x)
		{
			if (map_cpy[y][x] == '2' || map_cpy[y][x] == 'X')
				m_cfg->map[y][x] = 'X';
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}

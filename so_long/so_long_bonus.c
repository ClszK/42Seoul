/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh <ljh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:10:39 by ljh               #+#    #+#             */
/*   Updated: 2023/09/26 17:30:54 by ljh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "so_long.h"

char	**map_copy(t_map *m_cfg);
void	map_copy_free(char **map_cpy, size_t y);

void	enemy_set(t_game *game)
{
	t_map	*m_cfg;
	char	**map_cpy;
	size_t	i;
	size_t	y;

	srand((unsigned int)time(NULL));
	m_cfg = game->m_cfg;
	i = 0;
	y = 0;
	map_cpy = NULL;
	while (i < 100)
	{
		map_copy_free(map_cpy, m_cfg->pos_y)
		map_cpy = map_copy()
	}
}

char	**map_copy(t_map *m_cfg)
{
	size_t	y;
	char	**map_cpy;

	y = 0;
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
	return (map_cpy);
}

void	map_copy_free(char **map_cpy, size_t y)
{
	if (map_cpy == NULL)
		return ;
	while (y > 0)
		free(map_cpy[--y]);
	free(map_cpy);
}

int		enemy_path()
{

}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:19:26 by ljh               #+#    #+#             */
/*   Updated: 2023/09/27 06:00:49 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../so_long.h"
# include <time.h>

char	**map_copy(t_map *m_cfg);
void	enemy_generate(t_game *game, size_t i, size_t y);
int		enemy_path_valid(t_map *m_cfg, char **map_cpy);
void	enemy_path_dfs(char **map, size_t x, size_t y);

#endif
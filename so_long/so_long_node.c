/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 20:06:02 by ljh               #+#    #+#             */
/*   Updated: 2023/10/05 18:02:59 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_generate(t_game *game)
{
	game->img = NULL;
	game->m_cfg = NULL;
	game->win_ptr = NULL;
	game->mlx_ptr = NULL;
	game->print = MANDANTORY;
	game->move_cnt = 0;
	game->key_flag.flag = 0;
	game->key_flag.pos_cnt = 0;
	game->key_flag.rock = 0;
}

t_map	*node_map_generate(void)
{
	t_map	*node;

	errno = ERRNO_OK;
	node = (t_map *)malloc(sizeof(t_map));
	if (node == NULL)
		error_msg(NULL, NULL);
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

t_img	*node_img_generate(void)
{
	t_img	*node;

	errno = ERRNO_OK;
	node = (t_img *)malloc(sizeof(t_img));
	if (node == NULL)
		error_msg(NULL, NULL);
	node->tile_ptr = NULL;
	node->down_ptr = NULL;
	node->enemy_ptr = NULL;
	node->wall_ptr = NULL;
	node->exit_ptr = NULL;
	node->collect_ptr = NULL;
	return (node);
}

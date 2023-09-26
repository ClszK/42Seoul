/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh <ljh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 20:06:02 by ljh               #+#    #+#             */
/*   Updated: 2023/09/25 20:08:36 by ljh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*node_game_generate()
{
	t_game *node;

	node = (t_game*)malloc(sizeof(t_game));
	if (node == NULL)
		error_msg(NULL, NULL);
	node->img = NULL;
	node->m_cfg = NULL;
	node->mlx_ptr = NULL;
	node->win_ptr = NULL;
	node->key_flag.flag = 0;
	node->key_flag.pos_cnt = 0;
	node->key_flag.rock = 0;
	return (node);
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

t_img	*node_img_generate()
{
	t_img	*node;

	node = (t_img*)malloc(sizeof(t_img));
	if (node == NULL)
		error_msg(NULL,NULL);	
	node->tile_ptr = NULL;
	node->down_ptr = NULL;
	node->wall_ptr = NULL;
	node->exit_ptr = NULL;
	node->enemy_ptr = NULL;
	node->collect_ptr = NULL;
	return (node);
}

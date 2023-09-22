/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 03:11:25 by jeholee           #+#    #+#             */
/*   Updated: 2023/09/22 18:27:14 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define KEY_W 13 
# define KEY_A 0
# define KEY_S 1 
# define KEY_D 2
# define KEY_ESC 53

# define KEY_PRESS 2
# define KEY_EXIT 17

# define WIDTH 24
# define HEIGHT 24

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include "./libft/libft.h"
# include "./minilibx_opengl_20191021/mlx.h"

typedef struct s_img {
	/* data */
	void	*tile_ptr;
	void	*up_ptr;
	void	*down_ptr;
	void	*left_ptr;
	void	*right_ptr;
	void	*wall_ptr;
	void	*exit_ptr;
	void	*enemy_ptr;
	void	*collect_ptr;
}	t_img;

typedef struct s_vars
{
	/* data */
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_map {
	char	**map;
	size_t	p_cnt;
	size_t	c_cnt;
	size_t	e_cnt;
	size_t	x;
	size_t	y;
	size_t	pos_x;
	size_t	pos_y;
	t_img	*img;
	t_vars	*vars;
}	t_map;


t_map	*map_generate(char *path);
void	map_height(t_map *m_cfg, char *path);
void	map_read(t_map *m_cfg, char *path);
t_map	*node_map_generate();
void	map_validation_check(t_map *m_cfg);

void	map_component_check(t_map *m_cfg, char *str, size_t y);

void	map_rectangle_check(t_map *m_cfg, char *str, size_t y);
void	map_path_check(t_map *m_cfg);
void	map_path_dfs(char **map, size_t x, size_t y);
void	error_msg(t_map *m_cfg, char *msg);
void	close_fd(t_map *m_cfg, int fd);

char	*map_empty_check(t_map *m_cfg, int fd);


int		key_hook(int keycode, t_vars *vars);


void	img_save_ptr(t_vars *vars, t_img *img, t_map *m_cfg);
void	img_push(t_vars *vars, t_img *img, t_map *m_cfg);
void	img_create(t_vars *vars, t_img *img, t_map *m_cfg);


#endif

// open, close, read, write, malloc, free, perror, strerror, exit
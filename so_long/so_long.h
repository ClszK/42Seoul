/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 03:11:25 by jeholee           #+#    #+#             */
/*   Updated: 2023/09/24 13:48:13 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define ERRNO_OK 3

# define KEY_W 13 
# define KEY_A 0
# define KEY_S 1 
# define KEY_D 2
# define KEY_ESC 53

# define KEY_PRESS 2
# define KEY_EXIT 17

# define WIDTH 64
# define HEIGHT 64

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
	void	*test;
}	t_img;

typedef struct s_imgdata {
	char			*img_data;
	int 			bpp;
	int 			line;
	int				endian;
	int				x;
	int				y;
	int 			pixel_pos;
	unsigned int	pixel_data;
}	t_imgdata;

typedef struct s_map {
	char	**map;
	size_t	p_cnt;
	size_t	c_cnt;
	size_t	e_cnt;
	size_t	x;
	size_t	y;
	size_t	pos_x;
	size_t	pos_y;
}	t_map;

typedef struct s_key {
	int	w_flag;
	int	a_flag;
	int	s_flag;
	int	d_flag;
	int pos_cnt;
	int	rock;
}	t_key;

typedef struct s_game {
	t_map	*m_cfg;
	t_img	*img;
	void	*mlx_ptr;
	void	*win_ptr;
	t_key	key_flag;
}	t_game;


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


int		key_hook(int keycode, t_game *vars);

void	img_save_ptr(t_game *game);
void	img_push(t_game *game);
void	img_generate(t_game *game);


#endif

// open, close, read, write, malloc, free, perror, strerror, exit
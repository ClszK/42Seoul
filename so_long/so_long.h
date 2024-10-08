/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh <ljh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 03:11:25 by jeholee           #+#    #+#             */
/*   Updated: 2023/09/26 17:10:00 by ljh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define ERRNO_OK 1

# define KEY_W 13 
# define KEY_A 0
# define KEY_S 1 
# define KEY_D 2
# define KEY_ESC 53

# define KEY_PRESS 2
# define KEY_EXIT 17

# define WIDTH 64
# define HEIGHT 64

# define DOWN 0
# define UP 1
# define LEFT 2
# define RIGHT 3

# define STOP 1
# define MOVE_1 2
# define MOVE_2 3

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include "./libft/libft.h"
# include "./minilibx_opengl_20191021/mlx.h"

typedef struct s_img {
	/* data */
	void			*tile_ptr;
	void			*down_ptr;
	void			*wall_ptr;
	void			*exit_ptr;
	void			*enemy_ptr;
	void			*collect_ptr;
	void			*character;
}	t_img;

typedef struct s_imgdata {
	char			*img_data;
	int 			bpp;
	int 			line;
	int				endian;
	int				x;
	int				x_range;
	int				y;
	int				y_range;
	int 			pixel_pos;
	unsigned int	pixel_data;
}	t_imgdata;

typedef struct s_map {
	char			**map;
	size_t			p_cnt;
	size_t			c_cnt;
	size_t			e_cnt;
	size_t			x;
	size_t			y;
	size_t			pos_x;
	size_t			pos_y;
}	t_map;

typedef struct s_key {
	int	flag;
	int pos_cnt;
	int	rock;
	int	start;
}	t_key;

typedef struct s_game {
	t_map	*m_cfg;
	t_img	*img;
	void	*mlx_ptr;
	void	*win_ptr;
	t_key	key_flag;
}	t_game;

// so_long.c
int		loop_hook(t_game *game);
void	splite_move(t_game *game, int state);

// so_long_node.c
t_game	*node_game_generate();
t_map	*node_map_generate();
t_img	*node_img_generate();

// so_long_map.c
t_map	*map_generate(char *path);
void	map_height(t_map *m_cfg, char *path);
void	map_read(t_map *m_cfg, char *path);
void	map_validation_check(t_map *m_cfg);
char	*map_empty_check(t_map *m_cfg, int fd);

// so_long_map_2.c
void	map_component_check(t_map *m_cfg, char *str, size_t y);
void	map_rectangle_check(t_map *m_cfg, char *str, size_t y);
void	map_path_check(t_map *m_cfg);
void	map_path_dfs(char **map, size_t x, size_t y);


// so_long_error.c
void	error_msg(t_map *m_cfg, char *msg);
void	close_fd(t_map *m_cfg, int fd);

// so_long_key.c
int		key_hook(int keycode, t_game *vars);
int		is_key(int keycode);
int		move_valid(int keycode, t_game *game);

// so_long_img.c
void	img_save_ptr(t_game *game);
void	img_push(t_game *game);
void	img_generate(t_game *game);

// so_long_utils.c
int		next_x(int flag);
int		next_y(int flag);
void	my_pixel_put(t_game *game, t_imgdata i_cfg);
void	character_move(t_game *game, int move, int state);
int		close_program(t_game *game);

void	check_leak(void);

#endif

// open, close, read, write, malloc, free, perror, strerror, exit
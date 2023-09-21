/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh <ljh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 03:11:25 by jeholee           #+#    #+#             */
/*   Updated: 2023/09/21 20:45:53 by ljh              ###   ########.fr       */
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


# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "./libft/libft.h"
# include "./minilibx_opengl_20191021/mlx.h"

typedef struct s_data {
	/* data */
	void	*img_ptr;
	void	*addr_ptr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

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

typedef struct s_vars
{
	/* data */
	void	*mlx;
	void	*win;

}	t_vars;


t_map *map_generate(char *path);

#endif

// open, close, read, write, malloc, free, perror, strerror, exit
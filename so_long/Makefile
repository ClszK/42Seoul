NAME	= 	so_long
SRCS	=	so_long.c\
			so_long_map.c\
			so_long_map_2.c\
			so_long_error.c\
			so_long_img.c\
			so_long_key.c

OBJS	=	$(SRCS:.c=.o)

HEADER 	= ./includes
LIBFT_DIR = ./libft
MLX_DIR = ./minilibx_opengl_20191021
CC	= gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
CLIB = -L$(MLX_DIR) -lmlx -framework OpenGL -framework Appkit

all:	$(NAME)

$(NAME)	: $(OBJS)
	make -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)
	$(CC) $(OBJS) $(CFLAGS) $(CLIB) -L$(LIBFT_DIR) -lft -o $(NAME)

%.o	:	%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

clean:
	make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: 
	make fclean
	make all

.PHONY: all clean fclean re
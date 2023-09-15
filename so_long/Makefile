NAME	= so_long
SRCS	= test.c
OBJS	= $(SRCS:.c=.o)

HEADER 	= ./includes
LIBFT_DIR = ./libft
MLX_DIR = ./minilibx_opengl_20191021
CC	= gcc
CFLAGS = -Wall -Wextra -Werror -g
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
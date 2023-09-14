NAME	= so_long
SRCS	= test.c
OBJS	= $(SRCS:.c=.o)

HEADER 	= .
FT_PRINTF_DIR = ./ft_printf
LIBFT_DIR = ./libft
MLX_DIR = ./minilibx_mms_20200219
CC	= cc
CFLAGS = -Wall -Wextra -Werror -g

all:	$(NAME)

$(NAME)	: $(OBJS)
	make -C $(FT_PRINTF_DIR)
	make -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)
	$(CC) $(OBJS) $(CFLAGS) -L$(FT_PRINTF_DIR) -lftprintf -o $(NAME)

%.o	:	%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

clean:
	make -C $(FT_PRINTF_DIR) clean
	make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: 
	make fclean
	make all

.PHONY: all clean fclean re
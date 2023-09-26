NAME	= 	so_long
SRCS	=	so_long_map.c\
			so_long_map_2.c\
			so_long_error.c\
			so_long_key.c\
			so_long_utils.c\
			so_long_utils_2.c\
			so_long_node.c\
			so_long_img.c

OBJS	=	$(SRCS:.c=.o)

INCS_M	=	so_long.h
INCS_B	=	bonus/so_long_bonus.h

M_SRCS	=	so_long.c\

M_OBJS	= 	$(M_SRCS:.c=.o)

B_SRCS	= 	so_long_bonus.c\
			so_long_utils_bonus.c

B_OBJS	= 	$(addprefix bonus/, $(B_SRCS:.c=.o))

HEADER 	= .
LIBFT_DIR = ./libft
MLX_DIR = ./minilibx_opengl_20191021
CC	= cc
CFLAGS = -Wall -Wextra -Werror -g3
CLIB = -L$(MLX_DIR) -lmlx -framework OpenGL -framework Appkit

ifdef WITH_BONUS
    OBJ_FILES 	=	$(B_OBJS) $(OBJS)
	INCS 		=	$(INCS_B) $(INCS_M) 
else
    OBJ_FILES 	= 	$(M_OBJS) $(OBJS) 
	INCS 		=	$(INCS_M)
endif

all:	$(NAME)

$(NAME)	: $(OBJ_FILES) $(INCS)
	@make -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)
	$(CC) $(OBJ_FILES) $(CFLAGS) $(CLIB) -L$(LIBFT_DIR) -lft -o $(NAME)

%.o	:	%.c $(INCS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean
	rm -rf $(OBJ_FILES) $(B_OBJS)

fclean: clean
	rm -rf $(NAME)
	@cd $(LIBFT_DIR) && make fclean
re: 
	make fclean
	make all

bonus:
	@make WITH_BONUS=1 all

.PHONY: all clean fclean re bonus
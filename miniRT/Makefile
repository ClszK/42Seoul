NAME		= 	miniRT

SRCS_DIR	=	srcs
OBJS_DIR	=	obj
INC_DIR		=	includes	

LIBFT_DIR	=	$(SRCS_DIR)/libft
MLX_DIR		=	$(SRCS_DIR)/minilibx_opengl_20191021

SRCS_MAIN	=	main.c\
				utils.c
SRCS_VEC	= 	vec3_operator.c\
				vec3_operator2.c\
				vec3_utils.c
SRCS_MLX	=	my_mlx_utils.c
SRCS_RAY	=	ray_utils.c
SRCS_COLOR	=	color_utils.c

SRCS		=	$(SRCS_MAIN)\
				$(addprefix vec3/, $(SRCS_VEC))\
				$(addprefix my_mlx/, $(SRCS_MLX))\
				$(addprefix ray/, $(SRCS_RAY))\
				$(addprefix color/, $(SRCS_COLOR))
				
OBJS		=	$(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))\

CC			=	cc
CFLAGS		=	-Werror -Wall -Wextra -g3
CPPFLAGS	=	-I$(LIBFT_DIR) -I$(MLX_DIR) -I$(INC_DIR)
CLIB		=	-L$(MLX_DIR) -lmlx -framework OpenGL -framework Appkit

all:	$(NAME)

$(NAME)	:	$(OBJS) 
	@make -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)
	$(CC) $(OBJS) $(CFLAGS) $(CLIB) -L$(LIBFT_DIR) -lft -o $(NAME)

$(OBJS_DIR) :
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)/vec3
	@mkdir -p $(OBJS_DIR)/my_mlx
	@mkdir -p $(OBJS_DIR)/ray
	@mkdir -p $(OBJS_DIR)/color

$(OBJS_DIR)/%.o	:	$(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)
	@cd $(LIBFT_DIR) && make fclean
re: 
	make fclean
	make all

.PHONY: all clean fclean re 
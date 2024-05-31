NAME	= 	push_swap
SRCS	=	push_swap.c\
			push_swap_cmd.c\
			push_swap_cmd2.c\
			push_swap_cmd3.c\
			push_swap_sort.c\
			push_swap_sort2.c\
			push_swap_stack.c\
			push_swap_stack2.c\
			push_swap_utils.c\
			push_swap_utils2.c\
			double_lst.c

OBJS	=	$(SRCS:.c=.o)

P_HEADER = push_swap.h
D_HEADER = double_lst.h
HEADER = $(P_HEADER) $(D_HEADER)
LIBFT_DIR = ./libft
CC	= cc
CFLAGS = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME)	: $(OBJS) $(HEADER)
	make -C $(LIBFT_DIR)
	$(CC) $(OBJS) $(CFLAGS) -L$(LIBFT_DIR) -lft -o $(NAME)

%.o	:	%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -rf $(NAME)

re: 
	make fclean
	make all

.PHONY: all clean fclean re

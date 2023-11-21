NAME	= 	pipex
SRCS	=	pipex.c\
			pipex_error.c\
			pipex_fd.c\
			pipex_file.c\
			pipex_cmd.c

OBJS	=	$(SRCS:.c=.o)

P_HEADER = pipex.h
HEADER = $(P_HEADER)
LIBFT_DIR = ./libft

CC	= cc
CFLAGS = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME)	: $(OBJS) $(HEADER)
	make -C $(LIBFT_DIR)
	$(CC) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

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

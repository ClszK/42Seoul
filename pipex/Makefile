NAME	= 	pipex
SRCS	=	pipex.c\
			pipex_error.c\
			pipex_fd.c\
			pipex_file.c\
			pipex_cmd.c\
			pipex_cmd2.c\
			pipex_proc.c

OBJS	=	$(SRCS:.c=.o)

P_HEADER = pipex.h
HEADER = $(P_HEADER)
LIBFT_DIR = ./libft

CC	= cc
CFLAGS = -Wall -Wextra -Werror

ifdef WITH_TEST
    TEST_FLAG = -g -fsanitize=address
else
	TEST_FLAG = 
endif

all:	$(NAME)

$(NAME)	: $(OBJS) $(HEADER)
	make -C $(LIBFT_DIR)
	$(CC) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME) $(TEST_FLAG)

%.o	:	%.c
	$(CC) $(CFLAGS) -c $< -o $@  -g

clean:
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -rf $(NAME)

re: 
	make fclean
	make all

test:
	rm -rf $(NAME)
	@make WITH_TEST=1

.PHONY: all clean fclean re

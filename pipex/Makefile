NAME	= 	pipex

SRCS	=	pipex_error.c\
			pipex_fd.c\
			pipex_file.c\
			pipex_cmd.c\
			pipex_cmd2.c\
			pipex_proc.c

OBJS	=	$(SRCS:.c=.o)

M_SRCS	=	pipex.c

M_OBJS	=	$(M_SRCS:.c=.o)

B_SRCS	=	pipex_bonus.c\
			pipex_bonus2.c

B_OBJS	=	$(B_SRCS:.c=.o)

P_HEADER = pipex.h
HEADER = $(P_HEADER)
LIBFT_DIR = ./libft

CC	= cc
CFLAGS = -Wall -Wextra

ifdef BONUS_FLAG
	COM_OBJS	=	$(OBJS) $(B_OBJS)
else
    COM_OBJS	=	$(OBJS) $(M_OBJS)
endif

all:	$(NAME)

$(NAME)	: $(COM_OBJS) $(HEADER)
	make -C $(LIBFT_DIR)
	$(CC) $(COM_OBJS) -L$(LIBFT_DIR) -lft -o $(NAME) $(TEST_FLAG)

%.o	:	%.c
	$(CC) $(CFLAGS) -c $< -o $@ -g

clean:
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJS) $(B_OBJS) $(M_OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -rf $(NAME)

re: 
	make fclean
	make all

bonus:
	@make BONUS_FLAG=1 all

.PHONY: all clean fclean re

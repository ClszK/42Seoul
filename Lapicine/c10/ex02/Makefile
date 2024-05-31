NAME	= ft_tail
SRCS	= ./ft_error.c ./ft_str.c ./main.c

OBJS	= $(SRCS:%.c=%.o)
CC	= gcc
CFLAGS = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME)	:	$(SRCS)
	$(CC) $(CFLAGS) -o $@ $(SRCS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
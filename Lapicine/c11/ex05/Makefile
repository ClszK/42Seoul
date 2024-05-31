NAME	= do-op
SRCS	= ./ft_put.c ./ft_atoi.c ./ft_operator.c ./main.c
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

re: 
	make fclean
	make all
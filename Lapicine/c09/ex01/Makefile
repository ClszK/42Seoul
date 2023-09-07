NAME	= libft.a
SRCS	= ./srcs/ft_putchar.c	./srcs/ft_putstr.c	./srcs/ft_strcmp.c	./srcs/ft_strlen.c	./srcs/ft_swap.c
OBJS	= ./srcs/ft_putchar.o	./srcs/ft_putstr.o	./srcs/ft_strcmp.o	./srcs/ft_strlen.o	./srcs/ft_swap.o
HEADER 	= ./includes
CC	= gcc
CFLAGS = -Wall -Wextra -Werror -c

all:	$(NAME)

$(NAME)	:	$(OBJS)
	ar rc $@ $(OBJS)

%.o	:	%.c
	$(CC) $(CFLAGS) $< -o $@ -I $(HEADER)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: 
	make fclean
	make all
NAME	= libftprintf.a
SRCS	= 	ft_printf.c\
			ft_printf_c_d.c\
			ft_printf_u_x.c\
			ft_printf_addr.c\
			ft_putnbr_base.c
			
OBJS	= $(SRCS:.c=.o)

LIB_NAME := ft
LIB_DIR := ./lib$(LIB_NAME)/
LIBFT := $(LIB_DIR)lib$(LIB_NAME).a

HEADER 	= ./includes/
CC	= gcc
CFLAGS = -Wall -Wextra -Werror
TESTFLAG = $(CFLAGS) -fsanitize=address -g -L . -lftprintf

all:	$(NAME)

$(NAME)	:	$(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	ar rcus $@ $?

%.o	:	%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: 
	make fclean
	make all

test:	re
	$(CC) $(TESTFLAG) test.c

.PHONY: all clean fclean re test
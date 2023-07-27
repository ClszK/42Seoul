NAME	= libftprintf.a
SRCS	= 	ft_printf.c\
			ft_format_s.c\
			ft_format_c.c\
			ft_format_p.c\
			ft_format_di.c\
			ft_format_u.c\
			ft_format_xX.c

OBJS	= $(SRCS:.c=.o)

HEADER 	= ./includes/
CC	= gcc
CFLAGS = -Wall -Wextra -Werror
TESTFLAG = -fsanitize=address -lftprintf -L.

all:	$(NAME)

$(NAME)	:	$(OBJS)
	ar rcs $@ $?
	make clean

%.o	:	%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: 
	make fclean
	make all

test:
	$(CC) $(TESTFLAG) test.c
	./a.out

excute:
	./a.out

.PHONY: all clean fclean re test
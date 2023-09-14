NAME	= libftprintf.a
SRCS	= 	ft_printf.c\
			ft_printf_c_d.c\
			ft_printf_u_x.c\
			ft_printf_addr.c\
			ft_putnbr_base.c\
			ft_printf_utils.c
			
OBJS	= $(SRCS:.c=.o)

HEADER 	= ./includes/
CC	= cc
CFLAGS = -Wall -Wextra -Werror -g

all:	$(NAME)

$(NAME)	: $(OBJS)
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

.PHONY: all clean fclean re test
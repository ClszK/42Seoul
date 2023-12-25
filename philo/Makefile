NAME	= 	philo

SRCS	= 	philo.c\
			info_set.c\
			utils.c\
			new.c

OBJS	=	$(SRCS:.c=.o)

HEADER = philo.h

CC	= cc
CFLAGS = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME)	: $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o	:	%.c
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: 
	make fclean
	make all

.PHONY: all clean fclean re

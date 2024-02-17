NAME	= 	test
SRCS	= 	test.cpp
			
OBJS	=	$(SRCS:.cpp=.o)

CC		=	clang++
CFLAGS 	=	-Wall -Wextra -Werror -std=c++98 -fsanitize=address -g

all:	$(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o	:	%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: 
	make fclean
	make all

.PHONY: all clean fclean re

NAME	= 	phonebook
SRCS	= 	main.cpp\
			Contact.cpp\
			PhoneBook.cpp
			
OBJS	=	$(SRCS:.cpp=.o)

HEADERS	=	Contact.hpp\
			PhoneBook.hpp

CC		=	c++
CFLAGS 	=	-Wall -Wextra -Werror -std=c++98 

all:	$(NAME)

$(NAME)	: $(OBJS) $(HEADERS)
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

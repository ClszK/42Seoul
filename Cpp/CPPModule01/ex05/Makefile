NAME		= 	a.out
SRCS		= 	main.cpp\
				Harl.cpp

OBJS		=	$(SRCS:.cpp=.o)

HEADER		=	Harl.hpp

CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98 

all:	$(NAME)

$(NAME)	: $(OBJS) $(HEADER)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o:	%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: 
	make fclean
	make all

.PHONY: all clean fclean re

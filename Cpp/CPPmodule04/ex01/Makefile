NAME		= 	a.out
SRCS		= 	main.cpp\
				Animal.cpp\
				Cat.cpp\
				Dog.cpp\
				WrongAnimal.cpp\
				WrongCat.cpp\
				Brain.cpp
			
OBJS		=	$(SRCS:.cpp=.o)

HEADERS		=	Animal.hpp\
				Cat.hpp\
				Dog.hpp\
				WrongAnimal.hpp\
				WrongCat.hpp\
				Brain.hpp

CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98 

all:	$(NAME)

$(NAME)	: $(OBJS) $(HEADERS)
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

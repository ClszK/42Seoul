NAME        = a.out
SRCS        = main.cpp\
              Bureaucrat.cpp\
              MyException.cpp\
			  AForm.cpp\
			  ShrubberyCreationForm.cpp\
			  RobotomyRequestForm.cpp\
			  PresidentialPardonForm.cpp\
				Intern.cpp

OBJDIR      = build
OBJS        = $(patsubst %.cpp, $(OBJDIR)/%.o, $(SRCS))
DEPS        = $(patsubst %.cpp, $(OBJDIR)/%.d, $(SRCS))

CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98 -MMD -MP

all:    $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

-include $(DEPS)

$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME) *_shrubbery

re: 
	make fclean
	make all

.PHONY: all clean fclean re

NAME =		Bureaucrat

CC =		clang++

CXXFLAGS =	-fsanitize=address -g3 -Wall -Wextra -Werror

SRC =		main.cpp Bureaucrat.cpp Form.cpp ShrubberyCreationForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp

SRC_PATH =	$(addprefix ./srcs/, $(SRC))

OBJ = 	$(SRC_PATH:.cpp=.o)

INC_PATH = 	./includes

all :		$(NAME)

$(NAME) : $(OBJ)
		$(CC) $(CXXFLAGS) -I $(INC_PATH) -o $@ $(SRC_PATH)

clean :
			rm -f $(OBJ)

fclean :	clean
			rm -f $(NAME)

re :		fclean all

.PHONY :	all clean fclean re

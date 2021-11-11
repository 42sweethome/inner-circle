NAME =		Bureaucrat

CC =		clang++

CXXFLAGS =	-Wall -Wextra -Werror

SRC =		main.cpp Bureaucrat.cpp

OBJ = 		$(SRC:.cpp=.o)

all :		$(NAME)

$(NAME) : $(OBJ)
		 $(CC) $(CXXFLAGS) $(SRC) -o $@

clean :	
			rm -f $(OBJ)

fclean :	clean
			rm -f $(NAME)

re :		fclean all

.PHONY :	all clean fclean re
NAME =		ScavTrap

CC =		clang++

CXXFLAGS =	-std=c++98 -Wall -Wextra -Werror

SRC =		ClapTrap.cpp ScavTrap.cpp main.cpp 

SRC_PATH =	$(addprefix ./srcs/, $(SRC))

SRC_OBJ = 	$(SRC_PATH:.cpp=.o)

OBJ =		$(SRC:.cpp=.o)

INC_PATH = 	./includes

all :		$(NAME)

$(NAME) : $(SRC_OBJ)
		$(CC) $(CXXFLAGS) -I $(INC_PATH) -o $@ $^
		mv $(SRC_OBJ) ./objects/

clean :
			rm -f $(addprefix ./objects/, $(OBJ))

fclean :	clean
			rm -f $(NAME)

re :		fclean all

.PHONY :	all clean fclean re

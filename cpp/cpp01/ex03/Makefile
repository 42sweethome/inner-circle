NAME =		violence

CC =		clang++

CXXFLAGS =	-std=c++98 -Wall -Wextra -Werror

SRC =		main.cpp HumanA.cpp HumanB.cpp Weapon.cpp

SRC_PATH = $(addprefix ./srcs/, $(SRC))

OBJ = 		$(SRC:.cpp=.o)

OBJ_PATH = $(addprefix ./objects/, $(OBJ))

INC_PATH = 	./includes

all :		$(NAME)

$(NAME) : $(OBJ_PATH)
		 $(CC) $(CXXFLAGS) -I $(INC_PATH) -o $@ $^

clean :
			rm -f $(OBJ)

fclean :	clean
			rm -f $(NAME)

re :		fclean all

.PHONY :	all clean fclean re

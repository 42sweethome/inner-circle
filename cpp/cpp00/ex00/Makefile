NAME =		megaphone

CC =		clang++

CFLAGS =	-Wall -Wextra -Werror

SRC =		megaphone.cpp

OBJ = 		$(SRC:.cpp=.o)

all :		$(NAME)

$(NAME) : $(OBJ)
		 $(CC) $(CFLAGS) -o $@ $^

clean :	
			rm -f $(OBJ)

fclean :	clean
			rm -f $(NAME)

re :		fclean all

.PHONY :	all clean fclean re
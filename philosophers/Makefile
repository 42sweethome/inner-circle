PHILO = philo

CC = gcc -fsanitize=address -g3

CFLAGS = -Wall -Wextra -Werror

SRCS = main.c action.c utils.c ft_atoi.c #ft_free.c

OBJS = $(SRCS:.c=.o)

all : $(PHILO)

$(PHILO) : $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $@

clean :
			rm -f $(OBJS)

fclean : clean
			rm -f $(PHILO)

re :	fclean all

.PHONY : all clean fclean re


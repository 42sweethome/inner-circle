PHILO = philo

CC = gcc -fsanitize=address -g3

CFLAGS = -Wall -Wextra -Werror

SRCS = main.c

OBJS = $(SRCS:.c=.o)

LIBFT = ./Libft/

LIBFT_A = $(addprefix $(LIBFT), $(LIBFT_A))

$(PHILO) : $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT) -l$(LIBFT_A)

all : $(PHILO)

clean :

fclean :

re :

.PHONY : all clean fclean re 


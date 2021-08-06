PHILO = philo

CC = gcc #-fsanitize=address -g3

CFLAGS = -Wall -Wextra -Werror

SRCS = main.c action.c utils.c

OBJS = $(SRCS:.c=.o)

LIBFT = ./Libft

LIBFT_A = $(addprefix $(LIBFT)/, libft.a)

all : $(PHILO)

$(PHILO) : $(OBJS) $(LIBFT_A)
			$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT) -lft -o $@

$(LIBFT_A) : 
				make -C $(LIBFT)

clean : 
			rm -f $(OBJS)
			make clean -C $(LIBFT)

fclean : clean
			rm -f $(PHILO)
			make fclean -C $(LIBFT)
			
re :	fclean all

.PHONY : all clean fclean re 


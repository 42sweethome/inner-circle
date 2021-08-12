NAME = minishell

CC = gcc

CFLAGS = -Wall -Wextra -Werror 

READ = -lreadline

SRCS = start.c\
	   ch_space1.c ch_space2.c util.c check.c\

OBJS = $(SRCS:.c=.o)

LIBFT = ./libft

LIBFT_A = $(addprefix $(LIBFT)/, libft.a)

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT_A)
			$(CC) $(CFLAGS) $(READ) $(OBJS) -L$(LIBFT) -lft -o $@

$(LIBFT_A) :
			make -C $(LIBFT)

clean : 
		rm -f $(OBJS)
		make clean -C $(LIBFT)

fclean : clean
		rm -f $(NAME)
		make fclean -C $(LIBFT)

re : fclean all

.PHONY : all clean fclean re

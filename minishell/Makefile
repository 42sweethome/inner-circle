NAME = minishell

CC = gcc

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3 

READ_H = -I /usr/local/Cellar/readline/8.1.1/include #~/.brew/opt/readline/include 

READ_L = -lreadline  -L /usr/local/Cellar/readline/8.1.1/lib #~/.brew/opt/readline/lib 

SRCS = start.c\
	   ch_space1.c ch_space2.c ch_env.c util.c util2.c check.c command1.c pipe.c pipe_set.c\
	   redirection.c redirect_fd.c heredoc.c my_func.c sig_handler.c init.c\
	   mini_process.c get_path.c special_char.c case_of_status.c free.c\
	   export_alloc.c export_add.c export_show.c unset.c cd.c echo.c\

OBJS = $(SRCS:.c=.o)

LIBFT = ./libft

LIBFT_A = $(addprefix $(LIBFT)/, libft.a)

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT_A)
			$(CC) $(CFLAGS) $(OBJS) -o $@ $(READ_L) -L$(LIBFT) -lft

.c.o :
	$(CC) $(CFLAGS) $(READ_H) -c $< -o $@ 

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

NAME = minishell

CC = gcc

CFLAGS = -Wall -Wextra -Werror

READ_H = -I ~/.brew/opt/readline/include

READ_L = -lreadline -L ~/.brew/opt/readline/lib

SRCS =	ft_echo.c ft_my_func.c ft_spliting.c\
		ft_case_of_status.c ft_export_add.c ft_pipe.c ft_start.c\
		ft_cd.c ft_export_alloc.c ft_pipe_set.c ft_term_init.c\
		ft_ch_space2.c ft_export_show.c ft_redirect_fd.c ft_unset.c\
		ft_check.c ft_free.c ft_redirection.c ft_util.c\
		ft_check_env.c ft_get_path.c ft_sig_handler.c ft_util2.c\
		ft_command1.c ft_heredoc.c ft_space_split.c\
		ft_copy_env.c ft_init.c ft_special_char.c\
		ft_count_arg.c ft_mini_process.c ft_split_copy.c\

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

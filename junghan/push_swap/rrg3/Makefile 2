# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/11 15:39:52 by junghan           #+#    #+#              #
#    Updated: 2021/07/07 17:29:27 by junghan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SUFFIXES: .c .o

PUSH_NAME = push_swap

PUSH_SRCS = ft_func_p.c ft_func_r.c ft_sort_a.c ft_func_rr.c \
	   ft_sort_b.c ft_func_s.c ft_sort_st.c ft_check.c ft_quick_sort.c\
	   ft_init.c ft_input_int.c ft_exit_a.c ft_exit_easy.c ft_exit_easy2.c \
	   ft_exit_b.c ft_push_swap.c ft_first_util.c ft_link.c \

PUSH_OBJS = $(PUSH_SRCS:.c=.o)

CHECK_NAME = checker

CHECK_SRCS = ft_checker.c ft_check.c ft_input_int.c ft_func_p.c ft_func_s.c \
			 ft_func_r.c ft_sort_st.c ft_sort_a.c ft_func_rr.c ft_sort_b.c \
			 ft_init.c get_next_line.c get_next_line_utils.c ft_exit_a.c \
			 ft_exit_b.c ft_exit_easy.c ft_link.c ft_first_util.c \
			 ft_quick_sort.c ft_exit_easy2.c \

CHECK_OBJS = $(CHECK_SRCS:.c=.o)

LIBFT = ./libft

LIBFT_LIB = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror 

RM = rm -f

all :
	make -C $(LIBFT)
	make $(PUSH_NAME)

$(PUSH_NAME): $(PUSH_OBJS)
	$(CC) $(CFLAGS) -o $(PUSH_NAME) $(PUSH_OBJS) -L$(LIBFT) -l libft.a

bonus:
	make -C $(LIBFT)
	make $(PUSH_NAME)
	make $(CHECK_NAME)

$(CHECK_NAME): $(CHECK_OBJS)
	$(CC) $(CFLAGS) -o $(CHECK_NAME) $(CHECK_OBJS) -L$(LIBFT) -lft

$(LIBFT_LIB):
	make all -C $(LIBFT)

clean:
	$(RM) $(PUSH_OBJS) $(CHECK_OBJS) $(LIBFT)/$(LIBFT_LIB)
	make clean -C $(LIBFT)

fclean:
	$(RM) $(PUSH_NAME) $(CHECK_NAME) $(PUSH_OBJS) $(CHECK_OBJS) \
		$(LIBFT)/$(LIBFT_LIB)
	make clean -C $(LIBFT)

re: fclean all

.PHONY: libft clean fclean all re bonus

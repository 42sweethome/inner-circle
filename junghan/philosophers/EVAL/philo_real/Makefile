# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/07 17:24:45 by junghan           #+#    #+#              #
#    Updated: 2021/07/09 11:58:28 by junghan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SUFFIXES: .c .o

NAME = philo

SRCS = ft_act.c ft_init.c ft_check.c ft_philo.c \
	   ft_fork_up.c	ft_utill.c ft_dining.c \
	   ft_fork_down.c \

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAFS = -Wall -Wextra -Werror -I. -fsanitize=address

RM = rm -f

all :
	make $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: clean fclean all re

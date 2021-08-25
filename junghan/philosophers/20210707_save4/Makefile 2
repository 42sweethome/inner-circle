# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/07 17:24:45 by junghan           #+#    #+#              #
#    Updated: 2021/07/07 17:38:33 by junghan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SUFFIXES: .c .o

NAME = philo

SRCS = ft_act.c ft_init.c ft_check.c ft_philo.c \
	   ft_manage_fork.c	ft_utill.c ft_dining.c \

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAFS = -Wall -Wextra -Werror -I.

RM = rm -f

all :
	make $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:
	fclean all

.PHONY: clean fclean all re

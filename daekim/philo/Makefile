# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/16 14:31:30 by daekim            #+#    #+#              #
#    Updated: 2021/07/22 09:59:21 by junghan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		philo

SRCS =		main.c philos.c util.c

OBJS =		main.o philos.o util.o

CC =		gcc

CFLAGS =	-Wall -Wextra -Werror

all :		$(NAME)

$(NAME) :	$(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean :
		rm -f $(OBJS)

fclean :	clean
		rm -f $(NAME)

re : 		fclean all

.PHONY :	all clean fclean re

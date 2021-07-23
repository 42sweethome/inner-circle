# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
<<<<<<< HEAD
#    Created: 2021/07/16 14:31:30 by daekim            #+#    #+#              #
#    Updated: 2021/07/22 09:59:21 by junghan          ###   ########.fr        #
=======
#    Created: 2021/07/22 13:36:47 by daekim            #+#    #+#              #
#    Updated: 2021/07/22 13:36:51 by daekim           ###   ########.fr        #
>>>>>>> 0c68d2c9939f79eb87d0bd57ce766c2c11104be1
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

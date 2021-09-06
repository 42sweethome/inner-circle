# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/16 14:31:30 by sonkang           #+#    #+#              #
#    Updated: 2021/07/19 21:16:38 by sonkang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER =		server
CLIENT =		client

SERVER_BONUS =	server_bonus
CLIENT_BONUS =	client_bonus

LIBFT =			libft/libft.a

SRCS_S =		server.c ft_atoi_base.c
SRCS_C =		client.c

SRCS_S_BONUS =	./bonus/server_bonus.c ./bonus/ft_atoi_base_bonus.c
SRCS_C_BONUS =	./bonus/client_bonus.c

OBJS_S =		server.o ft_atoi_base.o
OBJS_C =		client.o

OBJS_S_BONUS =	./bonus/server_bonus.o ./bonus/ft_atoi_base_bonus.o
OBJS_C_BONUS =	./bonus/client_bonus.o

CC =			gcc

CFLAGS =		-Wall -Wextra -Werror



all :			$(SERVER) $(CLIENT)

$(SERVER) :	$(OBJS_S) $(LIBFT)
			cp $(LIBFT) ./
			$(CC) $(CFLAGS) -L./libft -lft -o $(SERVER) $(OBJS_S)

$(CLIENT) : $(OBJS_C) $(LIBFT)
			cp $(LIBFT) ./
			$(CC) $(CFLAGS) -L./libft -lft -o $(CLIENT) $(OBJS_C)

$(LIBFT) :		
			$(MAKE) -C ./libft all


bonus :				$(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER_BONUS) :	$(OBJS_S_BONUS) $(LIBFT)
					cp $(LIBFT) ./
					$(CC) $(CFLAGS) -L./libft -lft -o $(SERVER_BONUS) $(OBJS_S_BONUS)

$(CLIENT_BONUS) :	$(OBJS_C_BONUS) $(LIBFT)
					cp $(LIBFT) ./
					$(CC) $(CFLAGS) -L./libft -lft -o $(CLIENT_BONUS) $(OBJS_C_BONUS)	

clean :
			rm -f $(OBJS_S) $(OBJS_C)
			rm -f $(OBJS_S_BONUS) $(OBJS_C_BONUS)
			$(MAKE) -C ./libft clean

fclean :	clean
			rm -f libft.a
			$(MAKE) -C ./libft fclean
			rm -f $(SERVER) $(CLIENT)
			rm -f $(SERVER_BONUS) $(CLIENT_BONUS)

re : 		fclean all bonus

.PHONY :	all clean fclean re bonus

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doyun <doyun@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/23 10:13:13 by doyun             #+#    #+#              #
#    Updated: 2021/07/26 11:42:39 by sonkang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3 

MLXFLAG = -L./mlx -lmlx -framework OpenGL -framework AppKit


SRCS = GNL/get_next_line.c GNL/get_next_line_utils.c\
	   getmap.c check_valid.c parsing.c image.c operate.c

OBJS = $(SRCS:.c=.o)

LIBFT = ./Libft

LIBFT_A = ./Libft/libft.a

MLX = ./mlx

MLX_LIB = ./mlx/libmlx.dylib

all :	$(NAME)

$(NAME) : $(OBJS) $(LIBFT_A) $(MLX_LIB)
			cp $(MLX_LIB) ./
			$(CC) $(CFLAGS) $(MLXFLAG) -L$(LIBFT) -lft $(OBJS) -o $@

$(LIBFT_A) : 
			make -C $(LIBFT)

$(MLX_LIB) : 
			make -C $(MLX)

clean : 
		rm -f $(OBJS)
		make clean -C $(MLX)
		make clean -C $(LIBFT)

fclean : clean
		rm -f $(NAME)
		rm -f ./libmlx.dylib
		make fclean -C $(LIBFT)

re : fclean all

.PHONY :
		all clean fclean re



# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/10 18:43:50 by sonkang           #+#    #+#              #
#    Updated: 2021/04/18 21:27:11 by sonkang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SUFFIXES: .c .o

NAME = libftprintf.a
SRCS = ft_printf.c \
	   ft_option.c \
	   ft_printf_utils.c \
	   print_diux.c \
	   print_di_utils.c \
	   print_u_utils.c \
	   print_x_utils.c \
	   print_pscper.c \
	   print_scper_utils.c \
	   print_p_utils.c \


OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re

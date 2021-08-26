# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/22 14:50:24 by daekim            #+#    #+#              #
#    Updated: 2021/03/14 23:37:53 by daekim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libftprintf.a

LIBFT =		libft/libft.a

CC =		gcc

CFLAGS =	-Wall -Wextra -Werror

SRCS =		ft_printf.c printf_opt.c \
			put_pcsp.c put_diux.c \
			conv_num.c str_print.c poi_print.c num_print.c \

OBJS =		$(SRCS:.c=.o)

all :		$(NAME)

$(NAME) :	$(OBJS) $(LIBFT)
			cp $(LIBFT) ./$(NAME)
			ar rc $(NAME) $(OBJS) 

$(LIBFT) :		
			$(MAKE) -C ./libft all

clean :
			rm -f $(OBJS)
			$(MAKE) -C ./libft clean

fclean :	clean
			rm -f $(NAME)
			$(MAKE) -C ./libft fclean

re : 		fclean all

.PHONY :	all clean fclean re

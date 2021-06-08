NAME =					push_swap

CC =					gcc -fsanitize=address -g

CFLAGS =				-Wall -Wextra -Werror

AR =					ar rcs

SRCS_NAME =				main.c\
						deque.c\
						sab.c pab.c rab.c rrab.c\
						qsort.c sort_ra.c sort_pb.c sort_rb.c sort_pbra.c\
						utils.c\
						error.c\

SRCS_PATH =				./srcs/

SRCS =					$(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS =					$(SRCS:.c=.o)

INC =					-I.

INC_PATH =				./includes

LIBFT =					./Libft

LIBFT_A =				libft.a

all :
						make all -C $(LIBFT)
						make $(NAME)

$(NAME) : 				$(OBJS)
						$(CC) $(CFLAGS) $(OBJS) -o $@ -L$(LIBFT) -lft

clean :					
						rm -f *.o
						make clean -C $(LIBFT)

fclean :				clean
						rm -f $(NAME) $(OBJS)
						make fclean -C $(LIBFT)

re :
						make fclean all

.PHONY :				all clean fclean re
				
						
						

NAME =					push_swap

CHECK_NAME =			checker

CC =					gcc -fsanitize=address -g

CFLAGS =				-Wall -Wextra -Werror

AR =					ar rcs

SRCS_NAME =				main.c\
						deque.c\
						sab.c pab.c rab.c rrab.c\
						qsort.c sort_ra.c sort_pb.c \
						sort_rrr.c\
						last_sort_case.c sort_case4.c sort_case5.c sort_case6.c\
						rs_case3.c\
						utils.c\
						error.c\
				
SRCS_PATH =				./srcs/

SRCS =					$(addprefix $(SRCS_PATH), $(SRCS_NAME))

CHECK_SRCS_NAME =		checker.c\
						get_next_line.c get_next_line_utils.c\
						c_sab.c c_pab.c c_rab.c c_rrab.c\
						qsort.c utils.c deque.c\

CHECK_SRCS =			$(addprefix $(SRCS_PATH), $(CHECK_SRCS_NAME))

OBJS =					$(SRCS:.c=.o)

CHECK_OBJS =			$(CHECK_SRCS:.c=.o)

INC =					-I.

INC_PATH =				./includes

LIBFT =					./Libft

LIBFT_A =				libft.a

all :
						make all -C $(LIBFT)
						make $(NAME)
						make $(CHECK_NAME)

$(NAME) : 				$(OBJS)
						$(CC) $(CFLAGS) $(OBJS) -o $@ -L$(LIBFT) -lft

$(CHECK_NAME) :			$(CHECK_OBJS)
						$(CC) $(CFLAGS) $(CHECK_OBJS) -o $(CHECK_NAME) -L$(LIBFT) -lft

clean :					
						rm -f *.o
						make clean -C $(LIBFT)

fclean :				clean
						rm -f $(NAME) $(OBJS)
						rm -f $(CHECK_NAME) $(CHECK_OBJS)
						make fclean -C $(LIBFT)

re :
						make fclean all

.PHONY :				all clean fclean re
				
						
						

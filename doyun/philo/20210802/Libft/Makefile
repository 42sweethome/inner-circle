NAME = 					libft.a

CC = 					gcc

CFLAGS =				-Wall -Wextra -Werror

AR =					ar rcs

SRC =					ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
						ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memcpy.c ft_memset.c\
						ft_memmove.c ft_memchr.c ft_memcmp.c ft_tolower.c ft_toupper.c\
						ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c\
						ft_strnstr.c ft_strncmp.c ft_calloc.c ft_strdup.c ft_substr.c\
						ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c\
						ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\


SRC_BONUS =				ft_lstnew.c	ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
						ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c\
						ft_lstmap.c\

OBJS = 					$(SRC:.c=.o)

OBJS_BONUS = 			$(SRC_BONUS:.c=.o)

all : 					$(NAME)

$(NAME) : 				$(OBJS)
						$(AR) $(NAME) $(OBJS)

bonus : 				$(OBJS) $(OBJS_BONUS)
						$(AR) $(NAME) $(OBJS) $(OBJS_BONUS)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
						rm -f $(OBJS) $(OBJS_BONUS)

fclean : 				clean
						rm -f $(NAME)

re : 					fclean all

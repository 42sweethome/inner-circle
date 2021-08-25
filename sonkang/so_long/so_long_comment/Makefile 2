NAME = so_long

BONUS = so_long_bonus

CC = gcc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3 

MLXFLAG = -L./mlx -lmlx -framework OpenGL -framework AppKit


SRCS = GNL/get_next_line.c GNL/get_next_line_utils.c\
	   so_long.c check_valid.c parsing.c image.c operate.c

SRCS_BONUS = GNL/get_next_line.c GNL/get_next_line_utils.c\
			 bonus/so_long_bonus.c bonus/check_valid_bonus.c\
			 bonus/parsing_bonus.c bonus/image_bonus.c\
			 bonus/operate_bonus.c bonus/get_texture_bonus.c\
			 bonus/position_bonus.c bonus/utils_bonus.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

LIBFT = ./Libft

LIBFT_A = ./Libft/libft.a

MLX = ./mlx

MLX_LIB = ./mlx/libmlx.dylib

all :	$(NAME)

bonus : $(BONUS)

$(NAME) : $(OBJS) $(LIBFT_A) $(MLX_LIB)
			cp $(MLX_LIB) ./
			$(CC) $(CFLAGS) $(MLXFLAG) -L$(LIBFT) -lft $(OBJS) -o $@

$(BONUS) : $(OBJS_BONUS) $(LIBFT_A) $(MLX_LIB)
			cp $(MLX_LIB) ./
			$(CC) $(CFLAGS) $(MLXFLAG) -L$(LIBFT) -lft $(OBJS_BONUS) -o $@

$(LIBFT_A) : 
			make -C $(LIBFT)

$(MLX_LIB) : 
			make -C $(MLX)

clean : 
		rm -f $(OBJS) $(OBJS_BONUS)
		make clean -C $(MLX)
		make clean -C $(LIBFT)

fclean : clean
		rm -f $(NAME) $(BONUS)
		rm -f ./libmlx.dylib
		make fclean -C $(LIBFT)

re : fclean all

.PHONY :
		all clean fclean re bonus

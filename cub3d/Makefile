NAME = cub3d

CC = gcc

CFLAGS = -Wall -Wextra -Werror -O3 

MLXFLAG = -L./mlx -lmlx -framework OpenGL -framework AppKit

SRCS = GNL/get_next_line.c GNL/get_next_line_utils.c\
	   cub3d.c check_map_valid.c get_element.c map_config.c utils.c\
	   graphic_init.c button_key.c image_conversion.c image_conversion2.c\
	   get_texture.c get_texture2.c 

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

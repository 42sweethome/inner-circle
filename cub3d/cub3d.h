#ifndef CUB3D_H
# define CUB3D_H

# include "./GNL/get_next_line.h"
# include "./Libft/libft.h"
# include "./mlx/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_map
{
    char    **map;
    int	    row;
    int		player_x;
	int		player_y;
    char    **path;
    int     floor;
    int     ceilling;
}       t_map;



#endif
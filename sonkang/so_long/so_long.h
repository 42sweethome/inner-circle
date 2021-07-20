/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 11:09:25 by doyun             #+#    #+#             */
/*   Updated: 2021/07/19 16:55:56 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./GNL/get_next_line.h"
# include "./Libft/libft.h"
# include <unistd.h>
# include <stdio.h>
#include "./mlx/mlx.h"

typedef struct	s_map
{
	char		**map;
	int			row;
	int			col;
	int			temp_col;
}				t_map;

typedef struct	s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			img_width;
	int			img_height;
}				t_data;

typedef	struct	s_win
{
	void		*mlx;
	void		*mlx_win;
	t_data		img;
}				t_win;

typedef	struct	s_info
{
	t_map		map;
	t_data		data;
	t_win		win;
}				t_info;

int	print_error();
int	check_extention(char *argv);
int	check_map_valid(t_map *map_info);
int	check_parm_valid(t_map *map_info);

#endif

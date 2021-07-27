/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 11:09:25 by doyun             #+#    #+#             */
/*   Updated: 2021/07/27 10:55:54 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../GNL/get_next_line.h"
# include "../Libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include "../mlx/mlx.h"

typedef struct s_map
{
	char		**map;
	int			row;
	int			col;
	int			temp_col;
	int			player_x;
	int			player_y;
	int			way;
	int			v;
	int			v_x;
	int			v_y;
	int			v_d;
	int			collect;
	int			walk;
}				t_map;

typedef struct s_data
{
	void		*img;
	int			*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			img_width;
	int			img_height;
}				t_data;

typedef struct s_win
{
	void		*mlx;
	void		*mlx_win;
	t_data		img;
}				t_win;

typedef struct s_info
{
	t_map		map;
	t_data		fimg;
	t_data		tex[20];
	t_win		win;
}				t_info;

int		print_error(void);
int		check_extention(char *argv);
int		check_map_valid(t_map *map_info);
int		check_parm_valid(t_map *map_info);
int		get_newline(char *argv, t_map *map_info);
char	**map_parser(t_map *map_info, char *argv, int fd);
int		parsing(t_info *info, char *argv);
int		draw(t_info *info, int y, int x, t_data tex);
int		img_conv(t_info *info);
void	ft_exit(t_info *info);
void	move(t_info *info, int x, int y);
int		check_keypress(int key, t_info *info);
int		check_button(void);
void	villain(t_info *info);
void	patrol(t_info *info, int i, int l);

#endif

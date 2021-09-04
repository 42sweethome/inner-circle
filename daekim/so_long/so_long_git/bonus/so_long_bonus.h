/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 11:47:40 by daekim            #+#    #+#             */
/*   Updated: 2021/09/04 11:56:26 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
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
	int			c;
	int			v_x;
	int			v_y;
	int			v_d;
	int			v_f;
	int			collect;
	int			walk;
}				t_map;

typedef struct s_data
{
	void			*img;
	unsigned int	*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				img_width;
	int				img_height;
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
	t_data		tex[17];
	t_win		win;
}				t_info;

void	print_error(int i);
int		check_extention(char *argv);
int		check_map_valid(t_map *m_info);
int		check_comp_valid(t_map *m_info);
int		get_newline(char *argv, t_map *map_info);
char	**map_parser(t_map *map_info, char *argv, int fd);
void	parsing(t_info *info, char *argv);
int		draw(t_info *info, int y, int x, t_data tex);
int		img_conv(t_info *info);
void	ft_exit(t_info *info);
void	message(t_info *info);
void	move(t_info *info, int x, int y);
int		check_keypress(int key, t_info *info);
int		check_button(t_info *info);
void	villain(t_info *info);
void	collectible(t_info *info);
void	patrol(t_info *info, int i, int l);
void	get_texture(t_info *info);
void	get_villian_position(t_map *map, int row, int col);
void	get_player_position(int *count, t_map *map, int row, int col);
void	die(t_info *info);

#endif

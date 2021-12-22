#ifndef GRAPHIC_H
# define GRAPHIC_H

# include "parsing.h"

typedef struct s_graphic
{
	unsigned int	**buffer;
	int				text_num;
	double			obj_x;
	int				img_x;
	double			obj_y;
	int				img_y;
	int				tex_point;

	int				img_width;
	int				img_height;
	int				size_l;
	int				bpp;
}					t_graphic;

typedef struct s_dda
{
	double		camera_x;
	double		raydir_x;
	double		raydir_y;
	int			map_x;
	int			map_y;
	double		sidedist_x;
	double		sidedist_y;
	double		deltadist_x;
	double		deltadist_y;
	double		perp;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
}				t_dda;

typedef struct s_win
{
	int			win_w;
	int			win_h;
	void		*mlx;
	void		*mlx_win;
}				t_win;

typedef struct s_user
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			move_speed;
	double			rot_speed;
}				t_user;

typedef struct s_data
{
	void			*img;
	unsigned int	*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				img_width;
	int				img_height;
}					t_data;

typedef struct s_info
{
	t_map		map;
	t_user		user;
	t_win		win;
	t_data		fimg;
	t_data		tex[5];
	t_dda		dda;
	t_graphic	grap;
}				t_info;

#endif
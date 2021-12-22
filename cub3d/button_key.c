# include "cub3d.h"

int	check_button(t_info *info)
{
	ft_exit(info);
	return (0);
}

void	updown_key(t_info *info, int key)
{
	if (key == 13)
	{
		if (info->map.map[(int)(info->user.pos_y + info->user.dir_y * \
			info->user.move_speed)][(int)info->user.pos_x] == '0')
			info->user.pos_y += info->user.dir_y * info->user.move_speed;
		if (info->map.map[(int)info->user.pos_y][(int)(info->user.pos_x + \
			info->user.dir_x * info->user.move_speed)] == '0')
			info->user.pos_x += info->user.dir_x * info->user.move_speed;
	}
	else if (key == 1)
	{
		if (info->map.map[(int)(info->user.pos_y - info->user.dir_y * \
			info->user.move_speed)][(int)info->user.pos_x] == '0')
			info->user.pos_y -= info->user.dir_y * info->user.move_speed;
		if (info->map.map[(int)info->user.pos_y][(int)(info->user.pos_x - \
			info->user.dir_x * info->user.move_speed)] == '0')
			info->user.pos_x -= info->user.dir_x * info->user.move_speed;
	}
}

void	leftright_key(t_info *info, int key)
{
	if (key == 0)
	{
		if (info->map.map[(int)(info->user.pos_y - info->user.plane_y * \
			info->user.move_speed)][(int)info->user.pos_x] == '0')
			info->user.pos_y -= info->user.plane_y * info->user.move_speed;
		if (info->map.map[(int)info->user.pos_y][(int)(info->user.pos_x - \
			info->user.plane_x * info->user.move_speed)] == '0')
			info->user.pos_x -= info->user.plane_x * info->user.move_speed;
	}
	else if (key == 2)
	{
		if (info->map.map[(int)(info->user.pos_y + info->user.plane_y * \
			info->user.move_speed)][(int)info->user.pos_x] == '0')
			info->user.pos_y += info->user.plane_y * info->user.move_speed;
		if (info->map.map[(int)info->user.pos_y][(int)(info->user.pos_x + \
			info->user.plane_x * info->user.move_speed)] == '0')
			info->user.pos_x += info->user.plane_x * info->user.move_speed;
	}
}

void	angle_key(t_info *info, int key)
{
	int		s;
	double	old;

	s = 1;
	if (key == 123 || key == 124)
	{
		if (key == 123)
			s = -1;
		old = info->user.dir_x;
		info->user.dir_x = info->user.dir_x * cos(info->user.rot_speed * s) \
			- info->user.dir_y * sin(info->user.rot_speed * s);
		info->user.dir_y = old * sin(info->user.rot_speed * s) + \
			info->user.dir_y * cos(info->user.rot_speed * s);
		old = info->user.plane_x;
		info->user.plane_x = info->user.plane_x * cos(info->user.rot_speed * s) \
			- info->user.plane_y * sin(info->user.rot_speed * s);
		info->user.plane_y = old * sin(info->user.rot_speed * s) + \
			info->user.plane_y * cos(info->user.rot_speed * s);
	}
}

int	check_keypress(int key, t_info *info)
{
	updown_key(info, key);
	leftright_key(info, key);
	angle_key(info, key);
	if (key == 53)
		ft_exit(info);
	return (0);
}

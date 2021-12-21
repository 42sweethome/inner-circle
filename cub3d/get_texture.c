#include "cub3d.h"

int get_rgb(t_map *map, char **split)
{
	int     num;
	int     idx;
	int     sum;
	char    **rgb;

	if (ft_strrchr(split[1], ',') != 0 && !*(ft_strrchr(split[1], ',') + 1))
		return (ft_error("RGB have many ','"));
	rgb = ft_split(split[1], ',');
	if (!rgb)
		return (ft_error("Split error"));
	idx = -1;
	sum = 0;
	while (rgb[++idx])
	{
		num = ft_atoi(rgb[idx]);
		if (0 > num || num > 255)
			return (ft_error("Out of RGB range"));
		sum = sum * 256 + num;
	}
	if (idx != 3)
		return (ft_error("Not RGB"));
	if (*(split[0]) == 'F')
		map->floor = sum;
	else if (*(split[0]) == 'C')
		map->ceilling = sum;
	return (0);
}

int	check_ele_fc(t_map *map, char **split)
{
	if (!ft_strncmp(split[0], "F", 2))
		map->wfc[4] += 1;
	else if (!ft_strncmp(split[0], "C", 2))
		map->wfc[5] += 1;
	else
		return (1);
	if (get_rgb(map, split))
		return (ft_error("**get_rgb**"));
	return (0);
}

int get_ele(t_map *map, char **split)
{
	int i;
	
	i = 0;
	if (++i && !ft_strncmp(split[0], "NO", 3))
		map->wfc[0] += 1;
	else if (++i && !ft_strncmp(split[0], "SO", 3))
		map->wfc[1] += 1;
	else if (++i && !ft_strncmp(split[0], "WE", 3))
		map->wfc[2] += 1;
	else if (++i && !ft_strncmp(split[0], "EA", 3))
		map->wfc[3] += 1;
	else
		return (check_ele_fc(map, split));
	if (check_extention(split[1], ".xpm"))
		return (ft_error("Invaild extention(xpm)"));
	map->path[i - 1] = ft_strdup(split[1]);
	return (0);
}



int check_form(t_map *map, char **split)
{
	if (split[0] == 0 || split[1] == 0 || split[2] != 0)
			return (ft_error("Unnecessary information"));
	if (get_ele(map, split))
		return (ft_error("wrong input wfc"));
	
	/*if (i < 4)
	{
		if (!split[0] || !get_ele(i))
			return (ft_error("Invalid element"));
		if(ft_strncmp(split[0], get_ele(i), 3))
			return (ft_error("Invalid element"));
		if (check_extention(split[1], ".xpm"))
			return (ft_error("Invaild extention(xpm)"));
		map->path[i] = ft_strdup(split[1]);
	}
	else
	{
		printf("split %p get_ele %s\n", split[0], get_ele(i));
		if (!split[0] || !get_ele(i))
			return (ft_error("Invalid element"));
		if (ft_strncmp(split[0], get_ele(i), 2))
			return (ft_error("Invalid element"));
		if (get_rgb(map, split[1], i))
			return (ft_error("**get_rgb**"));
	}*/
	return (0);
}

int	check_texture(t_map *map)
{
	int i;

	i = -1;
	while (++i < 6)
	{
		if (map->wfc[i] == 0)
			break;
		if (map->wfc[i] > 1)
			return (ft_error("wfc is over"));
	}
	if (i != 6)
		return (1);
	return (0);
}

int get_path_color(t_map *map, int fd)
{
	char    *buf;
	char    **split;
	int     ret;

	while (check_texture(map))
	{
		map->cnt_wfc++;
		ret = get_next_line(fd, &buf);
		if (ret == -1)
			return (ft_error("GNL error"));
		if (!*buf)
			continue;
		split = ft_split(buf, ' ');
		if (check_form(map, split))
			return(ft_error("**check_form**"));
	}
	return (0);
}

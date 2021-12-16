#include "cub3d.h"

char *get_ele(int i)
{
	if (i == 0)
		return ("NO");
	if (i == 1)
		return ("SO");
	if (i == 2)
		return ("WE");
	if (i == 3)
		return ("EA");
	if (i == 5)
		return ("F");
	if (i == 6)
		return ("C");
	return (0);
}

int get_rgb(t_map *map, char *str, int i)
{
	int     num;
	int     idx;
	int     sum;
	char    **rgb;

	if (ft_strrchr(str, ',') != 0 && !*(ft_strrchr(str, ',') + 1))
		return (ft_error("RGB have many ','"));
	rgb = ft_split(str, ',');
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
	if (i == 5)
		map->floor = sum;
	else if (i == 6)
		map->ceilling = sum;
	return (0);
}

int check_form(t_map *map, char **split, int i)
{
	if (split[0] == 0 || split[1] == 0 || split[2] != 0)
			return (ft_error("Unnecessary information"));
	if (i < 4)
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
	}
	return (0);
}

int get_path_color(t_map *map, int fd)
{
	char    *buf;
	char    **split;
	int     ret;
	int     i;

	i = -1;
	while (++i < 8)
	{
		ret = get_next_line(fd, &buf);
		if (ret == -1)
			return (ft_error("GNL error"));
		if (!*buf)
			continue;
		split = ft_split(buf, ' ');
		if (check_form(map, split, i))
			return(ft_error("**check_form**"));
	}
	return (0);
}

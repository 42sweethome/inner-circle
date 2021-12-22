# include "cub3d.h"

int	rgb_toi(char **rgb)
{
	int		idx;
	int		sum;
	int		num;

	idx = -1;
	sum = 0;
	while (rgb[++idx])
	{
		num = ft_atoi(rgb[idx]);
		if (0 > num || num > 255)
			return (ft_error("Out of RGB range"));
		sum = sum * 256 + num;
	}
	ft_free(rgb);
	if (idx != 3)
		return (ft_error("Not RGB"));
	return (sum);
}

int	get_rgb(t_map *map, char **split)
{
	int		sum;
	char	**rgb;

	if (ft_strrchr(split[1], ',') != 0 && !*(ft_strrchr(split[1], ',') + 1))
		return (ft_error("RGB have many ','"));
	rgb = ft_split(split[1], ',');
	if (!rgb)
		return (ft_error("Split error"));
	sum = rgb_toi(rgb);
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

int	get_ele(t_map *map, char **split)
{
	int		i;
	int		fd;

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
	fd = open(split[1], O_RDONLY);
	if (fd == -1)
		return (ft_error("Open error"));
	close(fd);
	map->path[i - 1] = ft_strdup(split[1]);
	return (0);
}

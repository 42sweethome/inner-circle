#include "cub3d.h"

char	check_element(t_map *map, char c, int idx, int jdx)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (map->direction != 0)
			return (ft_error("player is only one"));
		map->player_x = jdx;
		map->player_y = idx;
		map->direction = map->map[idx][jdx];
		return (0);
	}
	else if (c == '1' || c == ' ' || c == '0')
		return (0);
	return (ft_error("wrong element"));
}

int row_parsing(t_map *map, int fd)
{
	int     ret;
	int     idx;
	int		jdx;

	idx = -1;
	ret = 1;
	while (ret > 0)
		ret = get_next_line(fd, &(map->map[++idx]));
	if (ret == -1)
		return (ft_error("GNL error"));
	idx = -1;
	while (*(map->map[++idx]))
	{
		jdx = -1;
		while (map->map[idx][++jdx])
		{
			if (check_element(map, map->map[idx][jdx], idx, jdx))
				return (ft_error("**check element**"));
		}
	}
	if (map->direction == 0)
	{
		return (ft_error("no where player"));
	}
	return (0);
}

int map_parsing(char *argv, t_map *map)
{
	int     fd;
	int     cnt;
	char    buf;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (ft_error("Open error"));
	printf("%d : \n", map->row);
	map->map = (char **)ft_calloc(map->row + 1, sizeof(char *));
	if (!map->map)
		return (ft_error("Allocate error"));
	cnt = 0;
	while (42)
	{
		if (read(fd, &buf, 1) == -1)
			return (ft_error("Read error"));
		if (buf == '\n')
			cnt++;
		if (cnt == 8)
			break ;
	}
	if (row_parsing(map, fd))
		return (ft_error("**row_parsing**"));
	return (0);
}

int get_newline(t_map *map, int fd)
{
	int ret;
	char buf;

	map->row = 0;
	ret = read(fd, &buf, 1);
	while (ret > 0)
	{
		if (buf == '\n')
			map->row++;
		ret = read(fd, &buf, 1);
	}
	close(fd);
	if (ret == -1)
		return (ft_error("Read error"));
	return (0);
}

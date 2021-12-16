#include "cub3d.h"

int ft_error(char *str)
{
	printf("Error\n%s\n", str);
	return (1);
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

int	check_extention(char *argv, char *str)
{
	int		len;
	int		ret;

	len = ft_strlen(argv);
	if (len >= 5)
		ret = ft_strncmp(&(argv[len - 4]), str, 4);
	else
		return (1);
	if (ret != 0)
		return (1);
	return (0);
}

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

int is_wall(char c)
{
	if (c == '1' || c == ' ')
	{
		return (1);
	}
	return (0);
}

// int	check_wall(t_map *map, int i, int j)
// {
// 	if (i == 0 || j == 0 || i == map->row - 1)
// 	{
// 		if (!is_wall(map->map[i][j]))
// 			return (ft_error("is not wall"));
// 	}
// 	return (0);
// }

int check_wall_from_back(char *str, int gap)
{
	int len;
	int	idx;

	len = ft_strlen(str);
	idx = -1;
	while (++idx < gap)
	{
		if (!is_wall(str[len - idx - 1]))
			return (ft_error("wall have hole"));
	}
	return (0);
}

int check_map_valid(t_map *map)
{
	int i;
	int j;
	int len1;
	int len2;

	i = 0;
	j = 0;
	while (is_wall(map->map[0][j]))
		j++;		
	if (map->map[0][j] != '\0')
		return (ft_error("wall have hole"));
	j = 0;
	while (is_wall(map->map[map->row - 1][j]))
		j++;		
	if (map->map[map->row - 1][j] != '\0')
		return (ft_error("wall have hole"));
	while (is_wall(*(map->map[i])))
	{
		len1 = ft_strlen(map->map[i]);
		if (i == map->row - 1)
			return (0);
		len2 = ft_strlen(map->map[i + 1]);
		if (len1 > len2)
		{
			if(check_wall_from_back(map->map[i], len1 - len2))
				break ;
		}
		if (len1 < len2)
		{
			if (check_wall_from_back(map->map[i + 1], len2 - len1))
				break ;
		}
		i++;
	}
	if (*(map->map[i]) != '\0')
		return (ft_error("wall have hole"));
	return (ft_error("map back is hole"));
}

int get_element(char *argv, t_map *map)
{
	int fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (ft_error("Open error"));
	if (get_path_color(map, fd))
		return (ft_error("**get_path_color**"));
	if (get_newline(map, fd))
		return(ft_error("**get_newline**"));
	if (map_parsing(argv, map))//스페이스 처리 필요
		return (ft_error("**map_parsing**"));
	if (check_map_valid(map))
		return (ft_error("**check_map_valid**"));
	return (0);
}

void    ft_printf(t_map map)
{
	int i = -1;
	while (++i < 4)
	{
		printf("path : %s\n", map.path[i]);
	}
	printf("floor : %d ceilling : %d\n", map.floor, map.ceilling);
	printf("row : %d\n", map.row);
	i = -1;
	while (i++ < map.row)
	{
		printf("%s\n", map.map[i]);
	}
}

int map_init(t_map *map)
{
	map->path = (char **)ft_calloc(5, sizeof(char*));
	if (!map->path)
		return(ft_error("Allocate error"));
	return (0);
}

int parsing(char *argv)
{
	t_map   map;
	
	if (map_init(&map))
		return (1);
	if (check_extention(argv, ".cub"))
		return (ft_error("Invaild extention(cub)"));
	if (get_element(argv, &map))
		return (ft_error("**get_element**"));
	ft_printf(map);
	return (0);
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (parsing(argv[1]))
			return(1);
	}
	else
		return (ft_error("Invalid number of arguments"));
	return (0);
}
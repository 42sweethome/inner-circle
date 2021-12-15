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
    if (buf == '\n')
		map->row++;
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
    if (split[2] != 0)
            return (ft_error("Unnecessary information"));
    if (i < 4)
    {
        if (!split[0] || get_ele(i))
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
        if (!split[0] || get_ele(i))
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

int row_parsing(t_map *map, int fd)
{
    int     ret;
    int     idx;

    idx = -1;
    ret = 1;
	while (ret > 0)
		ret = get_next_line(fd, &(map->map[++idx]));
    if (ret == -1)
        return (ft_error("GNL error"));
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
    close(fd);
    if (map_parsing(argv, map))//스페이스 처리 필요
        return (ft_error("**map_parsing**"));
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
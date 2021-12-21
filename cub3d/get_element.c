#include "cub3d.h"

int path_allocate(t_map *map)
{
	map->path = (char **)ft_calloc(5, sizeof(char*));
	if (!map->path)
		return(ft_error("Allocate error"));
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
	if (map_parsing(argv, map))
		return (ft_error("**map_parsing**"));
	if (check_map_valid(map))
		return (ft_error("**check_map_valid**"));
	return (0);
}

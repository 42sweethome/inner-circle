#include "cub3d.h"

int parsing(char *argv)
{
	t_map   map;

	if (path_allocate(&map))
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

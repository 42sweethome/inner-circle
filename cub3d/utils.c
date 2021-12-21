#include "cub3d.h"

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

int	ft_exit(t_info *info)
{
	mlx_destroy_window(info->win.mlx, info->win.mlx_win);
	mlx_destroy_image(info->win.mlx, info->fimg.img);
	exit(0);
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
	while (++i < map.row)
	{
		printf("%s\n", map.map[i]);
	}
}

void ft_free(char **str)
{
	int i;

	i = -1;
	while (str[++i])
	{
		free(str[i]);
	}
	free(str);
}
int ft_error(char *str)
{
	printf("Error\n%s\n", str);
	exit(0);
}
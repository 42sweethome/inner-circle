#ifndef PARSING_H
# define PARSING_H

typedef struct s_map
{
	char	**map;
	int		row;
	int		player_x;
	int		player_y;
	char	direction;
	char	**path;
	int		wfc[6];
	int		cnt_wfc;
	int		cnt_nl;
	int		floor;
	int		ceilling;
}			t_map;

//get_element.c
int		path_allocate(t_map *map);
int		get_element(char *argv, t_map *map);

//check_map_valid.c
int		check_map_valid(t_map *map);

//map_config.c
int		get_newline(t_map *map, int fd);
int		map_parsing(char *argv, t_map *map);

#endif

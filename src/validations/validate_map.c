#include "cub3d.h"


void	set_map_dimensions(t_map_info *map_info)
{
	int	lines;
	int	max_columns;
	int	columns;

	lines = 0;
	max_columns = 0;
	while (map_info->map[lines])
	{
		columns = ft_strlen(map_info->map[lines]) - 1;
		if (columns > max_columns)
			max_columns = columns;
		lines++;
	}
	map_info->lines = lines;
	map_info->columns = max_columns;
}

void	alloc_map(t_map_info *map_info, char *temp, int fd)
{
	int	map_size;

	map_size = 0;
	temp = get_next_line(fd);
	while (temp)
	{
		map_size++;
		free(temp);
		temp = get_next_line(fd);
	}
	close(fd);
	if (map_size == 0)
		handle_error("Error: no map information found.\n");//
	map_info->map = ft_calloc(sizeof(char *), (map_size + 1));
	if (!map_info->map)
		handle_error("Error: map allocation error.\n");//
}

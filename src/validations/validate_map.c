#include "cub3d.h"


void	exit_map_error(t_data *data, char *error_msg)
{
	ft_dprintf(STDERR_FILENO, "Error: %s\n", error_msg);
	ft_free_data(data);
	exit(EXIT_FAILURE);
}

void	set_map_dimensions(t_data *data)
{
	int	lines;
	int	max_columns;
	int	columns;

	lines = 0;
	max_columns = 0;
	while (data->map[lines])
	{
		columns = ft_strlen(data->map[lines]) - 1;
		if (columns > max_columns)
			max_columns = columns;
		lines++;
	}
	data->map_height = lines;
	data->map_width = max_columns;
}

void	alloc_map(t_data *data, char *temp, int fd)
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
	{
		free(temp);
		exit_map_error(data, "no map information found.");
	}
	data->map = ft_calloc(sizeof(char *), (map_size + 1));
	if (!data->map)
	{
		free(temp);
		exit_map_error(data, "map allocation error.");
	}
}

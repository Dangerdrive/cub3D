#include "cub3d.h"

static void	alloc_map(t_data *data, char *temp, int fd)
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

static void	set_map_dimensions(t_data *data)
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



t_data	*load_map_file(t_data *data, char *map_path)
{
	int			fd;
	char		*temp_line;

	temp_line = NULL;
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		exit_map_error(data, "map file could not be opened");
	parse_textures(data, temp_line, fd);
	ft_load_tex(data);
	alloc_map(data, temp_line, fd);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		exit_map_error(data, "map file could not be opened");
	load_map_content(data, temp_line, fd);
	if (data->map == NULL)
		exit_map_error(data, "no map found.");
	set_map_dimensions(data);
	replace_map_tabs(data);
	validate_map(data);
	return (data);
}

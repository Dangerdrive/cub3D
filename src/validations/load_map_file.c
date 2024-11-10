#include "cub3d.h"

t_data	*get_game(t_data *game)
{
	static t_data	*game_ptr;

	if (game)
		game_ptr = game;
	return (game_ptr);
}

void	handle_map_line(t_bool *is_map, t_bool *map_ended,
		char *temp, int line_count)
{
	t_data		*data;
	static int	i;

	data = get_game(NULL);//init_data
	if (*map_ended)
	{
		free(temp);
		handle_error("Error: map invalid.\n");
	}
	if (line_count >= data->map_info->textures_count)
	{
		data->map_info->map[i] = ft_strdup(temp);
		i++;
		*is_map = true;
	}
}

void	load_map_content(char *temp, int fd)//load map
{
	int		line_count;
	t_bool	is_map;
	t_bool	map_ended;

	line_count = 0;
	is_map = false;
	map_ended = false;
	temp = get_next_line(fd);
	while (temp)
	{
		if (temp[0] == '\n')
		{
			if (is_map && !map_ended)
				map_ended = true;
		}
		else
			handle_map_line(&is_map, &map_ended, temp, line_count);
		line_count++;
		free(temp);
		temp = get_next_line(fd);
	}
	close(fd);
}

t_map_info	*load_map_file(char *map_path)
{
	int			fd;
	char		*temp_line;
	t_map_info	*map;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		exit_usage_error("Error: map file could not be opened\n");
	read_textures_path(map, temp_line, fd);//improve code path
//TODO
	alloc_map(map, temp_line, fd);
	fd = open_file(map_file);//
	load_map_content(temp_line, fd);//
	if (map->map_array == NULL)//
		exit_usage_error("Error: invalid map.\n");//add frees
	// get_max_columns(map);
	// get_max_lines(map);//
	return (map);
}

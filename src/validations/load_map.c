#include "cub3d.h"

static void	handle_map_line(t_data *data, char *temp)
{
	static int	i;

	if (data->map_ended)
	{
		free(temp);
		exit_map_error(data, "invalid map");
	}
	if (data->map_start_line >= data->textures_count)
	{
		data->map[i] = ft_strdup(temp);
		i++;
		data->is_map = true;
	}
}

void	load_map_content(t_data *data, char *temp, int fd)//load map
{
	// int		map_start_line;
	// t_bool	is_map;
	// t_bool	map_ended;

	data->map_start_line = 0;
	data->is_map = false;
	data->map_ended = false;
	temp = get_next_line(fd);
	while (temp)
	{
		if (temp[0] == '\n')
		{
			if (data->is_map && !data->map_ended)
				data->map_ended = true;
		}
		else
			handle_map_line(data, temp);
		data->map_start_line++;
		free(temp);
		temp = get_next_line(fd);
	}
	close(fd);
}

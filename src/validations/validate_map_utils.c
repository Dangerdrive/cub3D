#include "cub3d.h"

void	check_colors(t_data *data, char *line, char *temp)
{
	static int	ceiling;
	static int	floor;

	if (ft_strncmp("F", temp, 1) == 0)
		floor++;
	if (ft_strncmp("C", temp, 1) == 0)
		ceiling++;
	if (ceiling > 1 || floor > 1)
	{
		free(line);
		handle_error("Error: duplicated color.\n");
	}
}

t_bool	starts_with_texture_prefix(char *temp)
{
	return (ft_strncmp("NO", temp, 2) == 0
		|| ft_strncmp("SO", temp, 2) == 0
		|| ft_strncmp("WE", temp, 2) == 0
		|| ft_strncmp("EA", temp, 2) == 0);
}

t_bool	starts_with_color_prefix(char *temp)
{
	return (ft_strncmp("F", temp, 1) == 0
		|| ft_strncmp("C", temp, 1) == 0);
}

t_bool	is_invalid_line(char *temp)
{
	return (temp[0] != '\n' && temp[0] != '\0');
}

t_bool	all_textures_loaded(t_map *map)
{
	return (map->no_path && map->so_path && map->we_path && map->ea_path
		&& map->ceiling_color && map->floor_color);
}

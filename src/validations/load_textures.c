#include "cub3d.h"

void	check_colors(t_map_info *map_info, char *line, char *temp)
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
		handle_error("Error: duplicated color.\n");//
	}
}

void	read_texture(t_map_info *map_info, char *temp, char *line)
{
	if (ft_strncmp("NO", temp, 2) == 0)
		copy_texture_path(&(map_info->no_path), temp, "NO", line);
	else if (ft_strncmp("SO", temp, 2) == 0)
		copy_texture_path(&(map_info->so_path), temp, "SO", line);
	else if (ft_strncmp("WE", temp, 2) == 0)
		copy_texture_path(&(map_info->we_path), temp, "WE", line);
	else if (ft_strncmp("EA", temp, 2) == 0)
		copy_texture_path(&(map_info->ea_path), temp, "EA", line);
}

void	read_color(t_map_info *_info, char *temp, char *line)
{
	if (ft_strncmp("F", temp, 1) == 0)
		check_rgb(&map_info->floor_color, temp, line, 'F');
	else if (ft_strncmp("C", temp, 1) == 0)
		check_rgb(&map_info->ceiling_color, temp, line, 'C');
}

void	process_texture_line(t_map_info *map_info, char *temp, char *line)
{
	if (starts_with_texture_prefix(temp))
		read_texture(map_info, temp, line);
	else if (starts_with_color_prefix(temp))
		read_color(map_info, temp, line);
	else if (is_invalid_line(temp))
	{
		free(line);
		exit_usage_error("Error: map file has invalid line.\n");//
	}
	check_colors(map_info, line, temp);
	map_info->textures_count++;
}

void	read_textures_path(t_map_info *map_info, char *temp_line, int fd)
{
	char	*line;

	temp_line = get_next_line(fd);
	while (temp_line)
	{
		line = temp_line;
		while (ft_isblank(*temp_line))
			temp_line++;
		process_texture_line(map_info, temp_line, line);
		free(line);
		if (all_textures_loaded(map_info))
			break ;
		temp_line = get_next_line(fd);
	}
	if (!temp_line)
		exit_usage_error("Error: map file could not be read.\n");
}

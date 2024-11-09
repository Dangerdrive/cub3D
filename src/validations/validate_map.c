#include "cub3d.h"

copy_texture_path

void	read_texture(t_map *map, char *temp, char *line)
{
	if (ft_strncmp("NO", temp, 2) == 0)
		copy_texture_path(&(map->no_path), temp, "NO", line);
	else if (ft_strncmp("SO", temp, 2) == 0)
		copy_texture_path(&(map->so_path), temp, "SO", line);
	else if (ft_strncmp("WE", temp, 2) == 0)
		copy_texture_path(&(map->we_path), temp, "WE", line);
	else if (ft_strncmp("EA", temp, 2) == 0)
		copy_texture_path(&(map->ea_path), temp, "EA", line);
}

void	read_color(t_map *map, char *temp, char *line)
{
	if (ft_strncmp("F", temp, 1) == 0)
		check_rgb(&map->floor_color, temp, line, 'F');
	else if (ft_strncmp("C", temp, 1) == 0)
		check_rgb(&map->ceiling_color, temp, line, 'C');
}

void	process_texture_line(t_map *map, char *temp, char *line)
{
	if (starts_with_texture_prefix(temp))
		read_texture(map, temp, line);
	else if (starts_with_color_prefix(temp))
		read_color(map, temp, line);
	else if (is_invalid_line(temp))
	{
		free(line);
		exit_usage_error("Error: map file has invalid line.\n");//
	}
	check_colors(map, line, temp);
}

void	read_textures_path(t_map *map, char *temp_line, int fd)
{
	char	*line;

	temp_line = get_next_line(fd);
	while (temp_line)
	{
		line = temp_line;
		while (ft_isblank(*temp_line))
			temp_line++;
		process_texture_line(map, temp_line, line);
		free(line);
		if (all_textures_loaded(map))
			break ;
		temp_line = get_next_line(fd);
	}
	if (!temp_line)
		exit_usage_error("Error: map file could not be read.\n");
}

t_map	*load_map(char *map_path)
{
	int		fd;
	char	*temp_line;
	t_map	*map;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		exit_usage_error("Error: map file could not be opened\n");
	read_textures_path(map, temp_line, fd);
//TODO
	// count_map_size(map, temp, fd);//
	fd = open_file(map_file);//
	// read_and_copy_map_content(temp, fd);//
	if (map->map_array == NULL)//
		exit_usage_error("Error: invalid map.\n");//add frees
	// get_max_columns(map);
	// get_max_lines(map);//
	return (map);
}

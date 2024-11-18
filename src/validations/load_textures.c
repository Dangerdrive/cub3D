#include "cub3d.h"

void	ft_load_tex(t_data *data)
{
	// data->ceil_color = ft_pixel(0, 255, 255, 255);
	// data->floor_color = ft_pixel(127, 63, 0, 255);
	data->no_tex = mlx_load_png(TEX_FOLDER "placeholder_null.png");
	data->tex[0] = mlx_load_png(data->no_path);
	data->tex[1] = mlx_load_png(data->so_path);
	data->tex[2] = mlx_load_png(data->we_path);
	data->tex[3] = mlx_load_png(data->ea_path);
	if (!data->no_tex || !data->tex[0] || !data->tex[1] \
		|| !data->tex[2] || !data->tex[3])
		exit_map_error(data, "loading png file failed.");
	// return (EXIT_SUCCESS);
}

void	read_texture(t_data *map_info, char *temp, char *line)
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

void	read_color(t_data *_info, char *temp, char *line)
{
	if (ft_strncmp("F", temp, 1) == 0)
		check_rgb(&map_info->floor_color, temp, line, 'F');
	else if (ft_strncmp("C", temp, 1) == 0)
		check_rgb(&map_info->ceil_color, temp, line, 'C');
}

void	process_texture_line(t_data *data, char *temp, char *line)
{
	if (starts_with_texture_prefix(temp))
		read_texture(data, temp, line);
	else if (starts_with_color_prefix(temp))
		read_color(data, temp, line);
	else if (is_invalid_line(temp))
	{
		free(line);
		exit_map_error(data, "map file has invalid line.");
	}
	check_colors(data, line, temp);
	data->textures_count++;
}

void	parse_textures(t_data *data, char *temp_line, int fd)
{
	char	*line;

	temp_line = get_next_line(fd);
	while (temp_line)
	{
		line = temp_line;
		while (ft_isblank(*temp_line))
			temp_line++;
		process_texture_line(data, temp_line, line);
		free(line);
		if (all_textures_loaded(data))
			break ;
		temp_line = get_next_line(fd);
	}
	if (!temp_line)
		exit_map_error(data, "map file could not be read.\n");
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 00:19:41 by fde-alen          #+#    #+#             */
/*   Updated: 2024/11/22 18:56:54 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_load_tex(t_data *data)
{
	data->tex[0] = mlx_load_png(data->no_path);
	data->tex[1] = mlx_load_png(data->so_path);
	data->tex[2] = mlx_load_png(data->we_path);
	data->tex[3] = mlx_load_png(data->ea_path);
	if (!data->tex[0] || !data->tex[1] \
		|| !data->tex[2] || !data->tex[3])
		exit_map_error(data, "loading texture from png file failed.");
}

static void	read_texture(t_data *data, char *temp, char *line)
{
	if (ft_strncmp("NO", temp, 2) == 0)
	{
		data->prefix = "NO";
		copy_texture_path(data, &(data->no_path), temp, line);
	}
	else if (ft_strncmp("SO", temp, 2) == 0)
	{
		data->prefix = "SO";
		copy_texture_path(data, &(data->so_path), temp, line);
	}
	else if (ft_strncmp("WE", temp, 2) == 0)
	{
		data->prefix = "WE";
		copy_texture_path(data, &(data->we_path), temp, line);
	}
	else if (ft_strncmp("EA", temp, 2) == 0)
	{
		data->prefix = "EA";
		copy_texture_path(data, &(data->ea_path), temp, line);
	}
}

static void	check_colors(t_data *data, char *line, char *temp)
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
		exit_map_error(data, "duplicated color.");
	}
}

static void	process_texture_line(t_data *data, char *temp, char *line)
{
	if (starts_with_texture_prefix(temp))
		read_texture(data, temp, line);
	else if (starts_with_color_prefix(temp))
	{
		if (ft_strncmp("F", temp, 1) == 0)
		{
			data->color = 'F';
			check_rgb(data, &data->floor_color, temp, line);
		}
		else if (ft_strncmp("C", temp, 1) == 0)
		{
			data->color = 'C';
			check_rgb(data, &data->ceil_color, temp, line);
		}
	}
	else if (is_invalid_line(temp))
	{
		free(line);
		exit_map_error(data, "map file has invalid line.");
	}
	check_colors(data, line, temp);
	data->map_start++;
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

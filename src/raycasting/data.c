/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:04:42 by aliferre          #+#    #+#             */
/*   Updated: 2024/11/22 15:42:53 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_textures(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (data->tex[i] != NULL)
			mlx_delete_texture(data->tex[i]);
		i++;
	}
	if (data->no_path)
		free(data->no_path);
	if (data->so_path)
		free(data->so_path);
	if (data->we_path)
		free(data->we_path);
	if (data->ea_path)
		free(data->ea_path);
}

void	ft_free_data(t_data *data)
{
	int		i;

	if (!data)
		return ;
	ft_free_textures(data);
	mlx_delete_image(data->mlx, data->img);
	mlx_terminate(data->mlx);
	i = -1;
	while (++i <= data->map_height && data->map_height > 0)
		free(data->map[i]);
	free(data->map);
	free(data);
}

void	init_data(t_data *data)
{
	int	i;

	data->map_height = 0;
	data->map_width = 0;
	data->map = NULL;
	i = -1;
	while (++i < 4)
		data->tex[i] = NULL;
	data->no_path = NULL;
	data->so_path = NULL;
	data->we_path = NULL;
	data->ea_path = NULL;
	data->pos = vec_new(0, 0);
	data->dir = vec_new(0, 0);
	data->plane = vec_new(0, 0);
	data->time = 0.0;
	data->frames = 0;
	data->ceil_color = 0;
	data->floor_color = 0;
	data->map_start = 0;
	data->map_end = 0;
	data->is_map = false;
	data->map_ended = false;
	data->invalid_chars = 0;
	data->player_count = 0;
}

t_data	*ft_init_cub(char *map_path)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->img = NULL;
	data->mlx = NULL;
	init_data(data);
	data->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", false);
	if (!data->mlx)
		return (NULL);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
		return (NULL);
	data->map = NULL;
	if (load_map_file(data, map_path) == NULL)
		return (NULL);
	data->pos = vec_add(data->pos, vec_new(0.5, 0.5));
	data->time = 0;
	data->frames = 0;
	data->plane = vec_rotate(vec_scale(data->dir, FOV), 90);
	return (data);
}

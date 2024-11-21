/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:04:42 by aliferre          #+#    #+#             */
/*   Updated: 2024/11/20 23:12:27 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



// static int	ft_load_map(t_data *data)
// {
// 	int	y;

// 	if (ft_load_tex(data) == EXIT_FAILURE)
// 		return (EXIT_FAILURE);
// 	data->map_width = 5;
// 	data->map_height = 7; //map_info->lines
// 	data->map = malloc(data->map_height * sizeof(int *));
// 	if (!data->map)
// 		return (EXIT_FAILURE);
// 	y = 0;
// 	while (y < data->map_height)
// 	{
// 		data->map[y] = malloc(data->map_width * sizeof(int));
// 		if (!data->map[y])
// 			return (EXIT_FAILURE);
// 		data->map[y][0] = 1;
// 		data->map[y][1] = (y == 0 || y == 6);
// 		data->map[y][2] = (y <= 2 || y == 4 || y == 6);
// 		data->map[y][3] = (y == 0 || y == 4 || y == 6);
// 		data->map[y][4] = 1;
// 		y++;
// 	}
// 	data->pos = vec_new(3, 1);
// 	data->dir = vec_new(0, VEC_SOUTH_Y);
// 	return (EXIT_SUCCESS);
// }

// static int	ft_load_map(t_data *data)// -> load map file
// {
// 	int	y;

// 	if (ft_load_tex(data) == EXIT_FAILURE)
// 		return (EXIT_FAILURE);
// 	data->map_width = 5;
// 	data->map_height = 7;
// 	data->map = malloc(data->map_height * sizeof(int *));
// 	if (!data->map)
// 		return (EXIT_FAILURE);
// 	y = 0;
// 	while (y < data->map_height)
// 	{
// 		data->map[y] = malloc(data->map_width * sizeof(int));
// 		if (!data->map[y])
// 			return (EXIT_FAILURE);
// 		data->map[y][0] = 1;
// 		data->map[y][1] = (y == 0 || y == 6);
// 		data->map[y][2] = (y <= 2 || y == 4 || y == 6);
// 		data->map[y][3] = (y == 0 || y == 4 || y == 6);
// 		data->map[y][4] = 1;
// 		y++;
// 	}
// 	data->pos = vec_new(3, 1);
// 	data->dir = vec_new(0, VEC_SOUTH_Y);
// 	return (EXIT_SUCCESS);
// }

void	init_data(t_data *data)
{
	int	i;

	data->mlx = NULL;
	data->map_height = 0;
	data->map_width = 0;
	data->map = NULL;
	data->img = NULL;
	i = 0;
	while (i < 4)
	{
		data->tex[i] = NULL;
		i++;
	}
	data->no_path = NULL;
	data->so_path = NULL;
	data->we_path = NULL;
	data->ea_path = NULL;
	data->pos.x = 0.0;
	data->pos.y = 0.0;
	data->dir.x = 0.0;
	data->dir.y = 0.0;
	data->plane.x = 0.0;
	data->plane.y = 0.0;
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



t_data	*ft_init_data(char *map_path)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	init_data(data);
	data->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", false);
	if (!data->mlx)
		return (NULL);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
		return (NULL);
	data->map = NULL;
	if (load_map_file(data, map_path) == NULL)//
		return (NULL);
	data->pos = vec_add(data->pos, vec_new(0.5, 0.5));
	data->time = 0;
	data->frames = 0;
	data->plane = vec_rotate(vec_scale(data->dir, FOV), 90);
	return (data);
}

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
	while (++i <= data->map_height)
		free(data->map[i]);
	free(data->map);
	free(data);
}

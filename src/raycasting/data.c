/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliferre <aliferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:04:42 by aliferre          #+#    #+#             */
/*   Updated: 2024/11/19 14:27:12 by aliferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_load_tex(t_data *data)
{
	data->ceil_color = ft_pixel(0, 255, 255, 255);
	data->floor_color = ft_pixel(127, 63, 0, 255);
	data->tex[0] = mlx_load_png(TEX_FOLDER "placeholder_0.png");
	data->tex[1] = mlx_load_png(TEX_FOLDER "placeholder_1.png");
	data->tex[2] = mlx_load_png(TEX_FOLDER "placeholder_2.png");
	data->tex[3] = mlx_load_png(TEX_FOLDER "placeholder_3.png");
	if (!data->tex[0] || !data->tex[1] \
		|| !data->tex[2] || !data->tex[3])
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	ft_load_map(t_data *data)
{
	int	y;

	if (ft_load_tex(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	data->map_width = 5;
	data->map_height = 7;
	data->map = malloc(data->map_height * sizeof(int *));
	if (!data->map)
		return (EXIT_FAILURE);
	y = 0;
	while (y < data->map_height)
	{
		data->map[y] = malloc(data->map_width * sizeof(int));
		if (!data->map[y])
			return (EXIT_FAILURE);
		data->map[y][0] = 1;
		data->map[y][1] = (y == 0 || y == 6);
		data->map[y][2] = (y <= 2 || y == 4 || y == 6);
		data->map[y][3] = (y == 0 || y == 4 || y == 6);
		data->map[y][4] = 1;
		y++;
	}
	data->pos = vec_new(3, 1);
	data->dir = vec_dir(VEC_SOUTH);
	return (EXIT_SUCCESS);
}

t_data	*ft_init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", false);
	if (!data->mlx)
		return (NULL);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
		return (NULL);
	if (ft_load_map(data) == EXIT_FAILURE)
		return (NULL);
	data->pos = vec_add(data->pos, vec_new(0.5, 0.5));
	data->time = 0;
	data->frames = 0;
	data->plane = vec_rotate(vec_scale(data->dir, FOV), 90);
	return (data);
}

void	ft_free_data(t_data *data)
{
	int		i;

	if (!data)
		return ;
	mlx_delete_texture(data->tex[0]);
	mlx_delete_texture(data->tex[1]);
	mlx_delete_texture(data->tex[2]);
	mlx_delete_texture(data->tex[3]);
	mlx_delete_image(data->mlx, data->img);
	mlx_terminate(data->mlx);
	i = -1;
	while (++i < data->map_height)
		free(data->map[i]);
	free(data->map);
	free(data);
}

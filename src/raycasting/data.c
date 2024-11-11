/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliferre <aliferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:04:42 by aliferre          #+#    #+#             */
/*   Updated: 2024/11/11 18:46:10 by aliferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_load_map(t_data *data)
{
	int	y;

	y = 0;
	while (y < MAP_HEIGHT)
	{
		data->map[y][0] = 1;
		data->map[y][1] = (y + 1) % 2;
		data->map[y][2] = (abs(y - 2) == 2);
		data->map[y][3] = (abs(y - 2) == 2);
		data->map[y][4] = 1;
		y++;
	}
}

static int	ft_load_tex(t_data *data)
{
	data->no_tex = mlx_load_png(TEX_FOLDER "placeholder_null.png");
	data->tex[0] = mlx_load_png(TEX_FOLDER "placeholder_0.png");
	data->tex[1] = mlx_load_png(TEX_FOLDER "placeholder_1.png");
	data->tex[2] = mlx_load_png(TEX_FOLDER "placeholder_2.png");
	data->tex[3] = mlx_load_png(TEX_FOLDER "placeholder_3.png");
	if (!data->no_tex || !data->tex[0] || !data->tex[1] \
		|| !data->tex[2] || !data->tex[3])
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

t_data	*ft_init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!data->mlx)
		return (NULL);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
		return (NULL);
	ft_load_map(data);
	if (ft_load_tex(data) == EXIT_FAILURE)
		return (NULL);
	data->time = 0;
	data->frames = 0;
	data->ceil_color = AQUA;
	data->floor_color = BROWN;
	data->pos = vec_new(2, 3);
	data->pos = vec_add(data->pos, vec_new(0.5, 0.5));
	data->dir = vec_new(0, VEC_NORTH_Y);
	data->plane = vec_rotate(vec_scale(data->dir, FOV), 90);
	return (data);
}

void	ft_free_data(t_data *data)
{
	if (!data)
		return ;
	mlx_delete_texture(data->no_tex);
	mlx_delete_texture(data->tex[0]);
	mlx_delete_texture(data->tex[1]);
	mlx_delete_texture(data->tex[2]);
	mlx_delete_texture(data->tex[3]);
	mlx_delete_image(data->mlx, data->img);
	mlx_terminate(data->mlx);
	free(data);
}

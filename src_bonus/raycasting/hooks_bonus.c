/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:04:20 by aliferre          #+#    #+#             */
/*   Updated: 2024/11/22 18:56:20 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	ft_move(t_data *data, t_vector dir, double rot)
{
	data->dir = vec_rotate(data->dir, -rot * ROT_SPEED * data->mlx->delta_time);
	data->plane = vec_rotate(vec_scale(data->dir, FOV), 90);
	if (dir.x != 0 || dir.y != 0)
		data->pos = vec_add(data->pos, vec_scale(vec_rotate(data->dir, \
							vec_angle(vec_dir(VEC_NORTH), dir)), \
							SPEED * data->mlx->delta_time));
	if (data->pos.x < COLLISION_MARGIN)
		data->pos.x = COLLISION_MARGIN;
	if (data->pos.y < COLLISION_MARGIN)
		data->pos.y = COLLISION_MARGIN;
	if (data->pos.x >= (double)data->map_width - COLLISION_MARGIN)
		data->pos.x = (double)data->map_width - COLLISION_MARGIN;
	if (data->pos.y >= (double)data->map_height - COLLISION_MARGIN)
		data->pos.y = (double)data->map_height - COLLISION_MARGIN;
}

void	ft_loop(void *param)
{
	t_data		*data;
	long		x;

	data = param;
	x = -1;
	minimap(data);
	while (++x < WIDTH)
		ft_display_column(data, x);
	data->time += data->mlx->delta_time;
	data->frames += 1;
	if ((long)data->time >= 5)
	{
		printf("%li FPS\n", (long)(data->frames / data->time));
		data->time = 0;
		data->frames = 0;
	}
}

void	ft_input(void *param)
{
	t_data		*data;
	t_vector	dir;
	double		rot;

	data = param;
	dir = vec_new(0, 0);
	rot = 0;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		dir = vec_add(dir, vec_dir(VEC_NORTH));
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		dir = vec_add(dir, vec_dir(VEC_SOUTH));
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		dir = vec_add(dir, vec_dir(VEC_EAST));
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		dir = vec_add(dir, vec_dir(VEC_WEST));
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		rot += 90;
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		rot -= 90;
	ft_move(data, dir, rot);
}

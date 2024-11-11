/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliferre <aliferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:57:16 by aliferre          #+#    #+#             */
/*   Updated: 2024/11/11 18:12:17 by aliferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ver_line(t_vector x_height, long tex_x, \
				t_data *data, mlx_texture_t *texture)
{
	int		y;
	long	draw_start;
	long	draw_end;
	long	tex_y;

	draw_end = x_height.y / 2 + HEIGHT / 2;
	draw_start = -x_height.y / 2 + HEIGHT / 2;
	y = 0;
	while (y < HEIGHT)
	{
		if (draw_start <= y && y < draw_end)
		{
			tex_y = (y - draw_start) * ((double)TEX_HEIGHT / x_height.y);
			mlx_put_pixel(data->img, x_height.x, y, \
							ft_image_pixel(texture, tex_x, tex_y));
		}
		else if (y <= HEIGHT / 2)
			mlx_put_pixel(data->img, x_height.x, y, data->ceil_color);
		else
			mlx_put_pixel(data->img, x_height.x, y, data->floor_color);
		y++;
	}
}

static int	ft_hit_loop_break(t_data *data, t_vector step, \
								t_vector *map_pos, int side)
{
	if (data->map[(long)data->pos.x][(long)data->pos.y] > 0
		&& ((*map_pos).x < 0 || (*map_pos).x >= MAP_WIDTH
			|| (*map_pos).y < 0 || (*map_pos).y >= MAP_HEIGHT))
		return (0);
	if (data->map[(long)data->pos.x][(long)data->pos.y] == 0
		&& data->map[(long)(*map_pos).x][(long)(*map_pos).y] > 0)
		return (1);
	if (data->map[(long)data->pos.x][(long)data->pos.y] > 0
		&& (data->map[(long)(*map_pos).x][(long)(*map_pos).y] == 0
		|| (*map_pos).x < 0 || (*map_pos).x >= MAP_WIDTH
		|| (*map_pos).y < 0 || (*map_pos).y >= MAP_HEIGHT))
	{
		if ((side % 2) == 1)
			(*map_pos).x -= step.x;
		else
			(*map_pos).y -= step.y;
		return (1);
	}
	return (0);
}

static int	ft_hit_loop(t_data *data, t_vector delta_dist, \
				t_vector ray_dir, t_vector *side_dist)
{
	int			side;
	t_vector	map_pos;

	map_pos = vec_new((long)data->pos.x, (long)data->pos.y);
	while (true)
	{
		if ((*side_dist).x < (*side_dist).y)
		{
			(*side_dist).x += delta_dist.x;
			map_pos.x += 2 * (ray_dir.x >= 0) - 1;
			side = 2 + 2 * (ray_dir.x >= 0) - 1;
		}
		else
		{
			(*side_dist).y += delta_dist.y;
			map_pos.y += 2 * (ray_dir.y >= 0) - 1;
			side = 1 + 2 * (ray_dir.y >= 0) - 1;
		}
		if (((HEIGHT / ((*side_dist).x - delta_dist.x) < 1)
				&& (HEIGHT / ((*side_dist).y - delta_dist.y) < 1))
			|| ft_hit_loop_break(data, vec_new(2 * (ray_dir.x >= 0) - 1, 2 \
							* (ray_dir.y >= 0) - 1), &map_pos, side) == 1)
			break ;
	}
	return (side);
}

static void	ft_draw_column(t_data *data, t_vector x_side, \
					t_vector diff_dist, t_vector ray_dir)
{
	long		line_height;
	double		unused;
	long		tex_x;

	if (((int)x_side.y % 2) == 1)
		line_height = (HEIGHT / diff_dist.x);
	else
		line_height = (HEIGHT / diff_dist.y);
	if (((int)x_side.y % 2) == 1)
		tex_x = modf(data->pos.y + diff_dist.x * ray_dir.y, &unused) \
				* TEX_WIDTH;
	else
		tex_x = modf(data->pos.x + diff_dist.y * ray_dir.x, &unused) \
				* TEX_WIDTH;
	if (x_side.y == 1 || x_side.y == 2)
		tex_x = TEX_WIDTH - tex_x - 1;
	if (x_side.y < 0 || x_side.y >= 4)
		ver_line(vec_new(x_side.x, line_height), tex_x, data, data->no_tex);
	ver_line(vec_new(x_side.x, line_height), tex_x, data, \
					data->tex[(int)x_side.y]);
}

void	ft_display_column(t_data *data, long x)
{
	int			side;
	t_vector	ray_dir;
	t_vector	map_pos;
	t_vector	side_dist;
	t_vector	delta_dist;

	ray_dir = vec_add(data->dir, vec_scale(data->plane, 2.0 * x / WIDTH - 1));
	map_pos = vec_new((long)data->pos.x, (long)data->pos.y);
	delta_dist = vec_func(get_delta_dist, 1, ray_dir);
	side_dist = vec_func(get_side_dist, 4, ray_dir, \
				data->pos, map_pos, delta_dist);
	side = ft_hit_loop(data, delta_dist, ray_dir, &side_dist);
	if (data->map[(long)data->pos.x][(long)data->pos.y] > 0)
		side = (side + 2) % 4;
	ft_draw_column(data, vec_new(x, side), \
				vec_add(side_dist, vec_scale(delta_dist, -1)), ray_dir);
}

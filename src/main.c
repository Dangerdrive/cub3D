/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliferre <aliferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:35:02 by aliferre          #+#    #+#             */
/*   Updated: 2024/11/11 17:08:48 by aliferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// -----------------------------------------------------------------------------

t_color	ft_pixel(t_color r, t_color g, t_color b, t_color a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

t_color	ft_get_r(t_color pixel)
{
	return ((pixel >> 24) & 0xff);
}

t_color	ft_get_g(t_color pixel)
{
	return ((pixel >> 16) & 0xff);
}

t_color	ft_get_b(t_color pixel)
{
	return ((pixel >> 8) & 0xff);
}

t_color	ft_get_a(t_color pixel)
{
	return (pixel & 0xff);
}

t_color	ft_shadow(t_color pixel)
{
	t_color	r;
	t_color	g;
	t_color	b;
	t_color	a;

	r = ft_get_r(pixel) / 2;
	g = ft_get_g(pixel) / 2;
	b = ft_get_b(pixel) / 2;
	a = ft_get_a(pixel);
	return (ft_pixel(r, g, b, a));
}

t_color	ft_image_pixel(mlx_texture_t *img, long x, long y)
{
	long	pos;
	uint8_t	*pixels;

	pos = 4 * (y * TEX_WIDTH + x);
	pixels = img->pixels + pos;
	return (ft_pixel(pixels[0], pixels[1], pixels[2], pixels[3]));
}

// Args: ray_dir
double	get_delta_dist(double *vals)
{
	return (fabs(1 / vals[0]));
}

// Args: ray_dir, pos, map_pos, delta_dist
double	get_side_dist(double *vals)
{
	double	ret;

	ret = vals[2] - vals[1] + 1;
	if (vals[0] < 0)
		ret = 1 - ret;
	return (ret * vals[3]);
}

void	ver_line(t_vector x_height, long tex_x, \
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

void	ft_clear_image(t_data *data)
{
	long	i;
	long	color;

	color = data->ceil_color;
	i = 0;
	while (i < data->img->width * data->img->height)
	{
		if (i == WIDTH * HEIGHT / 2)
			color = data->floor_color;
		mlx_put_pixel(data->img, i % WIDTH, i / HEIGHT, color);
		i++;
	}
}

int	ft_tempname_2(t_data *data, t_vector step, t_vector *map_pos, int side)
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

int	ft_hit_loop(t_data *data, t_vector delta_dist, \
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
			|| ft_tempname_2(data, vec_new(2 * (ray_dir.x >= 0) - 1, 2 \
							* (ray_dir.y >= 0) - 1), &map_pos, side) == 1)
			break ;
	}
	return (side);
}

void	ft_tempname(t_data *data, t_vector x_side, \
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
	ft_tempname(data, vec_new(x, side), \
				vec_add(side_dist, vec_scale(delta_dist, -1)), ray_dir);
}

void	ft_loop(void *param)
{
	t_data		*data;
	long		x;

	data = param;
	x = -1;
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

void	ft_move(t_data *data, t_vector dir, double rot)
{
	data->dir = vec_rotate(data->dir, rot * ROT_SPEED * data->mlx->delta_time);
	data->plane = vec_rotate(vec_scale(data->dir, FOV), 90);
	if (dir.x != 0 || dir.y != 0)
		data->pos = vec_add(data->pos, vec_scale(vec_rotate(data->dir, \
							vec_angle(vec_new(0, VEC_NORTH_Y), dir)), \
							SPEED * data->mlx->delta_time));
	if (data->pos.x < COLLISION_MARGIN)
		data->pos.x = COLLISION_MARGIN;
	if (data->pos.y < COLLISION_MARGIN)
		data->pos.y = COLLISION_MARGIN;
	if (data->pos.x >= (double)MAP_WIDTH - COLLISION_MARGIN)
		data->pos.x = (double)MAP_WIDTH - COLLISION_MARGIN;
	if (data->pos.y >= (double)MAP_HEIGHT - COLLISION_MARGIN)
		data->pos.y = (double)MAP_HEIGHT - COLLISION_MARGIN;
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
		dir = vec_add(dir, vec_new(0, VEC_NORTH_Y));
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		dir = vec_add(dir, vec_new(0, VEC_SOUTH_Y));
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		dir = vec_add(dir, vec_new(VEC_EAST_X, 0));
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		dir = vec_add(dir, vec_new(VEC_WEST_X, 0));
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		rot += 90;
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		rot -= 90;
	ft_move(data, dir, rot);
}

void	ft_load_map(t_data *data)
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

int	ft_load_tex(t_data *data)
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

// -----------------------------------------------------------------------------

int	main(void)
{
	t_data	*data;

	data = ft_init_data();
	if (!data)
		return (EXIT_FAILURE);
	mlx_image_to_window(data->mlx, data->img, 0, 0);
	mlx_loop_hook(data->mlx, ft_input, data);
	mlx_loop_hook(data->mlx, ft_loop, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	free(data);
	return (EXIT_SUCCESS);
}

// 11111
// 10101
// 10001
// 10N01
// 11111

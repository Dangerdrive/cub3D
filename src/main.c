/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliferre <aliferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:35:02 by aliferre          #+#    #+#             */
/*   Updated: 2024/11/07 20:08:48 by aliferre         ###   ########.fr       */
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
	return (pixel >> 24) & 0xff;
}

t_color	ft_get_g(t_color pixel)
{
	return (pixel >> 16) & 0xff;
}

t_color	ft_get_b(t_color pixel)
{
	return (pixel >> 8) & 0xff;
}

t_color	ft_get_a(t_color pixel)
{
	return pixel & 0xff;
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
	return ft_pixel(r, g, b, a);
}

t_color	ft_image_pixel(mlx_texture_t* img, long x, long y)
{
	long	pos;
	uint8_t	*pixels;

	pos = 4 * (y * TEX_WIDTH + x);
	pixels = img->pixels + pos;
	return ft_pixel(pixels[0], pixels[1], pixels[2], pixels[3]);
}

// Args: rayDir
double	getDeltaDist(double* vals)
{
	return fabs(1 / vals[0]);
}

// Args: rayDir, pos, mapPos, deltaDist
double	getSideDist(double* vals)
{
	double	ret;
	ret = vals[2] - vals[1] + 1;
	if(vals[0] < 0)
		ret = 1 - ret;
	return ret * vals[3];
}

void verLine(int x, long texX, long lineHeight, t_data* data, mlx_texture_t* texture)
{
	int	y;
	
    long drawStart = -lineHeight / 2 + HEIGHT / 2;
    long drawEnd = lineHeight / 2 + HEIGHT / 2;
	y = 0;
	while (y < HEIGHT)
	{
		if (drawStart <= y && y < drawEnd)
		{
			long texY = (y - drawStart) * ((double)TEX_HEIGHT / lineHeight);
			mlx_put_pixel(data->img, x, y, ft_image_pixel(texture, texX, texY));
		}
		else if (y <= HEIGHT / 2)
			mlx_put_pixel(data->img, x, y, data->ceil_color);
		else
			mlx_put_pixel(data->img, x, y, data->floor_color);
		y++;
	}
}

void	ft_clear_image(t_data* data)
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

void ft_loop(void* param)
{
	t_data* data = param;

    for(int x = 0; x < WIDTH; x++)
    {
      double cameraX = 2 * x / (double)WIDTH - 1;
      t_vector rayDir = vec_add(data->dir, vec_scale(data->plane, cameraX));
      t_vector mapPos = vec_new((long)data->pos.x, (long)data->pos.y);
      t_vector sideDist;
	  t_vector deltaDist;
      deltaDist = vec_func(getDeltaDist, 1, rayDir);
      double perpWallDist;
      t_vector step = vec_new(1, 1);
      int hit = 0;
      int side;
	  bool in_wall = data->map[(long)mapPos.x][(long)mapPos.y] > 0;
	  if (rayDir.x < 0) step.x = -1;
	  if (rayDir.y < 0) step.y = -1;
      sideDist = vec_func(getSideDist, 4, rayDir, data->pos, mapPos, deltaDist);
      while(hit == 0)
      {
        if(sideDist.x < sideDist.y)
        {
          sideDist.x += deltaDist.x;
          mapPos.x += step.x;
          side = 2 + step.x;
        }
        else
        {
          sideDist.y += deltaDist.y;
          mapPos.y += step.y;
          side = 1 + step.y;
        }
		if ((HEIGHT / (sideDist.x - deltaDist.x) < 1)
		&& (HEIGHT / (sideDist.y - deltaDist.y) < 1))
			break;
		if(!in_wall && (mapPos.x < 0 || mapPos.x >= MAP_WIDTH
		|| mapPos.y < 0 || mapPos.y >= MAP_HEIGHT))
			continue;
        if (!in_wall && data->map[(long)mapPos.x][(long)mapPos.y] > 0) hit = 1;
		if (in_wall && (data->map[(long)mapPos.x][(long)mapPos.y] == 0
		|| mapPos.x < 0 || mapPos.x >= MAP_WIDTH
		|| mapPos.y < 0 || mapPos.y >= MAP_HEIGHT)) {
			hit = 1;
			if ((side % 2) == 1) mapPos.x -= step.x;
			else                 mapPos.y -= step.y;
		}
      }
	  if (in_wall) side = (side + 2) % 4;
      if((side % 2) == 1) perpWallDist = (sideDist.x - deltaDist.x);
      else                perpWallDist = (sideDist.y - deltaDist.y);
      long lineHeight = (long)(HEIGHT / perpWallDist);
	  double wallX;
	  if ((side % 2) == 1) wallX = (data->pos.y + perpWallDist * rayDir.y);
	  else                 wallX = (data->pos.x + perpWallDist * rayDir.x);
	  wallX -= (long)wallX;
	  long texX = (wallX * TEX_WIDTH);
	  if (side == 1 || side == 2) texX = TEX_WIDTH - texX - 1;
	  if (side < 0 || side >= 4)
	  	verLine(x, texX, lineHeight, data, data->no_tex);
      verLine(x, texX, lineHeight, data, data->tex[side]);
    }
	data->time += data->mlx->delta_time;
	data->frames += 1;
	if ((long)data->time >= 5)
	{
		printf("%li FPS\n", (long)(data->frames / data->time));
		data->time = 0;
		data->frames = 0;
	}
}

void ft_input(void* param)
{
	t_data* data = param;
	t_vector	dir = vec_new(0, 0);
	double		rot = 0;

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
	data->dir = vec_rotate(data->dir, rot * ROT_SPEED * data->mlx->delta_time);
	data->plane = vec_rotate(vec_scale(data->dir, FOV), 90);
	if (dir.x != 0 || dir.y != 0)
		data->pos = vec_add(data->pos, vec_scale(vec_rotate(data->dir, vec_angle(vec_new(0, VEC_NORTH_Y), dir)), SPEED * data->mlx->delta_time));
	if (data->pos.x < COLLISION_MARGIN)
		data->pos.x = COLLISION_MARGIN;
	if (data->pos.y < COLLISION_MARGIN)
		data->pos.y = COLLISION_MARGIN;
	if (data->pos.x >= (double)MAP_WIDTH - COLLISION_MARGIN)
		data->pos.x = (double)MAP_WIDTH - COLLISION_MARGIN;
	if (data->pos.y >= (double)MAP_HEIGHT - COLLISION_MARGIN)
		data->pos.y = (double)MAP_HEIGHT - COLLISION_MARGIN;
}

// -----------------------------------------------------------------------------

t_color main(void)
{
	t_data*	data = malloc(sizeof(t_data));
	mlx_t* mlx;

	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}

	data->mlx = mlx;
	
	data->img = mlx_new_image(mlx, WIDTH, HEIGHT);

	for (int y = 0; y < MAP_HEIGHT; y++) data->map[y][0] = 1;
	for (int y = 0; y < MAP_HEIGHT; y++) data->map[y][1] = (y + 1) % 2;
	for (int y = 0; y < MAP_HEIGHT; y++) data->map[y][2] = (abs(y - 2) == 2);
	for (int y = 0; y < MAP_HEIGHT; y++) data->map[y][3] = (abs(y - 2) == 2);
	for (int y = 0; y < MAP_HEIGHT; y++) data->map[y][4] = 1;

	data->no_tex = mlx_load_png("/nfs/homes/aliferre/Desktop/Projetos 42/cub3d/textures/placeholder_null.png");
	data->tex[0] = mlx_load_png("/nfs/homes/aliferre/Desktop/Projetos 42/cub3d/textures/placeholder_0.png");
	data->tex[1] = mlx_load_png("/nfs/homes/aliferre/Desktop/Projetos 42/cub3d/textures/placeholder_1.png");
	data->tex[2] = mlx_load_png("/nfs/homes/aliferre/Desktop/Projetos 42/cub3d/textures/placeholder_2.png");
	data->tex[3] = mlx_load_png("/nfs/homes/aliferre/Desktop/Projetos 42/cub3d/textures/placeholder_3.png");

	data->time = 0;
	data->frames = 0;
	data->ceil_color = AQUA;
	data->floor_color = BROWN;
	data->pos = vec_new(2, 3);
	data->pos = vec_add(data->pos, vec_new(0.5, 0.5));
	data->dir = vec_new(0, VEC_NORTH_Y);
	data->plane = vec_rotate(vec_scale(data->dir, FOV), 90);

	mlx_image_to_window(data->mlx, data->img, 0, 0);

	mlx_loop_hook(mlx, ft_input, data);
	mlx_loop_hook(mlx, ft_loop, data);

	mlx_loop(mlx);
	free(data);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

// 11111
// 10101
// 10001
// 10N01
// 11111

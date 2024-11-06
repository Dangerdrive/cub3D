#include "cub3d.h"

static mlx_image_t* image;

// -----------------------------------------------------------------------------

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

int32_t ft_get_r(int32_t pixel)
{
	return (pixel >> 24) & 0xff;
}

int32_t ft_get_g(int32_t pixel)
{
	return (pixel >> 16) & 0xff;
}

int32_t ft_get_b(int32_t pixel)
{
	return (pixel >> 8) & 0xff;
}

int32_t ft_get_a(int32_t pixel)
{
	return pixel & 0xff;
}

int32_t ft_shadow(int32_t pixel)
{
	return ft_pixel(ft_get_r(pixel) / 2, ft_get_g(pixel) / 2, ft_get_b(pixel) / 2, ft_get_a(pixel));
}

void ft_randomize(void* param)
{
	(void)param;
	for (uint32_t i = 0; i < image->width; ++i)
	{
		for (uint32_t y = 0; y < image->height; ++y)
		{
			uint32_t color = ft_pixel(
				rand() % 0xFF, // R
				rand() % 0xFF, // G
				rand() % 0xFF, // B
				rand() % 0xFF  // A
			);
			mlx_put_pixel(image, i, y, color);
		}
	}
}

void ft_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		image->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		image->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x += 5;
}

// -----------------------------------------------------------------------------

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

// rayDir
double	getDeltaDist(double* vals)
{
	return fabs(1 / vals[0]);
}

// rayDir, pos, mapPos, deltaDist
double	getSideDist(double* vals)
{
	double	ret;
	ret = vals[2] - vals[1] + 1;
	if(vals[0] < 0)
		ret = 1 - ret;
	return ret * vals[3];
}

void verLine(int x, long drawStart, long drawEnd, long color, data_t* data)
{
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		if (drawStart <= y && y < drawEnd)
			mlx_put_pixel(data->img, x, y, color);
		else if (y <= HEIGHT / 2)
			mlx_put_pixel(data->img, x, y, data->ceil_color);
		else
			mlx_put_pixel(data->img, x, y, data->floor_color);
		y++;
	}
}

void	ft_clear_image(data_t* data)
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
	data_t* data = param;

    for(int x = 0; x < WIDTH; x++)
    {
      double cameraX = 2 * x / (double)WIDTH - 1;
      vector_t rayDir = vec_add(data->dir, vec_scale(data->plane, cameraX));
      vector_t mapPos = vec_new((long)data->pos.x, (long)data->pos.y);
      vector_t sideDist;
	  vector_t deltaDist;
      deltaDist = vec_func(getDeltaDist, 1, rayDir);
      double perpWallDist;
      vector_t step = vec_new(1, 1);
      int hit = 0;
      int side;
	  bool in_wall = worldMap[(long)mapPos.x][(long)mapPos.y] > 0;
	  if (rayDir.x < 0) step.x = -1;
	  if (rayDir.y < 0) step.y = -1;
      sideDist = vec_func(getSideDist, 4, rayDir, data->pos, mapPos, deltaDist);
      while(hit == 0)
      {
        if(sideDist.x < sideDist.y)
        {
          sideDist.x += deltaDist.x;
          mapPos.x += step.x;
          side = 0;
        }
        else
        {
          sideDist.y += deltaDist.y;
          mapPos.y += step.y;
          side = 1;
        }
		if ((HEIGHT / (sideDist.x - deltaDist.x) < 1)
		&& (HEIGHT / (sideDist.y - deltaDist.y) < 1))
			break;
		if(!in_wall && (mapPos.x < 0 || mapPos.x >= mapWidth
		|| mapPos.y < 0 || mapPos.y >= mapHeight))
			continue;
        if (!in_wall && worldMap[(long)mapPos.x][(long)mapPos.y] > 0) hit = 1;
		if (in_wall && (worldMap[(long)mapPos.x][(long)mapPos.y] == 0
		|| mapPos.x < 0 || mapPos.x >= mapWidth
		|| mapPos.y < 0 || mapPos.y >= mapHeight)) {
			hit = 1;
			if (side == 0) mapPos.x -= step.x;
			else mapPos.y -= step.y;
		}
      }
      if(side == 0) perpWallDist = (sideDist.x - deltaDist.x);
      else          perpWallDist = (sideDist.y - deltaDist.y);
      long lineHeight = (long)(HEIGHT / perpWallDist);
      long drawStart = -lineHeight / 2 + HEIGHT / 2;
      if(drawStart < 0) drawStart = 0;
      long drawEnd = lineHeight / 2 + HEIGHT / 2;
      if(drawEnd >= HEIGHT) drawEnd = HEIGHT - 1;
	  if (lineHeight < 1)
	  {
		verLine(x, drawStart, drawEnd, 0, data);
	  	continue;
	  }
      long color;
      switch(worldMap[(long)mapPos.x][(long)mapPos.y])
      {
        case 1:  color = TOMATO; break;
        case 2:  color = GREEN;  break;
        case 3:  color = VIOLET; break;
        case 4:  color = WHITE;  break;
        default: color = YELLOW; break;
      }
      if(side == 1) {color = ft_shadow(color);}
      verLine(x, drawStart, drawEnd, color, data);
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
	data_t* data = param;
	vector_t	dir = vec_new(0, 0);
	double		rot = 0;

	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		dir = vec_add(dir, vec_new(0, -1));
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		dir = vec_add(dir, vec_new(0, 1));
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		dir = vec_add(dir, vec_new(-1, 0));
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		dir = vec_add(dir, vec_new(1, 0));
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		rot += 90;
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		rot -= 90;
	data->dir = vec_rotate(data->dir, rot * data->rot_speed * data->mlx->delta_time);
	data->plane = vec_rotate(vec_scale(data->dir, data->fov), 90);
	if (dir.x != 0 || dir.y != 0)
		data->pos = vec_add(data->pos, vec_scale(vec_rotate(data->dir, vec_angle(dir, vec_new(0, -1))), data->speed * data->mlx->delta_time));
	if (data->pos.x <= 0)
		data->pos.x = nexttoward(1, mapWidth) - 1;
	if (data->pos.y <= 0)
		data->pos.y = nexttoward(1, mapWidth) - 1;
	if (data->pos.x >= mapWidth)
		data->pos.x = nexttoward(mapWidth, 0);
	if (data->pos.y >= mapHeight)
		data->pos.y = nexttoward(mapHeight, 0);
}

// -----------------------------------------------------------------------------

int32_t main(void)
{
	data_t*	data = malloc(sizeof(data_t));
	mlx_t* mlx;

	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(image = mlx_new_image(mlx, 128, 128)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}

	data->mlx = mlx;
	data->img = mlx_new_image(mlx, WIDTH, HEIGHT);
	data->fov = 0.66;
	data->speed = 7;
	data->rot_speed = 1.5;
	data->time = 0;
	data->frames = 0;
	data->ceil_color = AQUA;
	data->floor_color = BROWN;
	data->pos = vec_new(22, 12);
	data->dir = vec_new(-1, 0);
	data->plane = vec_rotate(vec_scale(data->dir, data->fov), 90);

	mlx_image_to_window(data->mlx, data->img, 0, 0);

	mlx_loop_hook(mlx, ft_input, data);
	mlx_loop_hook(mlx, ft_loop, data);

	mlx_loop(mlx);
	free(data);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}


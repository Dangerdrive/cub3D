#include "cub3d.h"

static mlx_image_t* image;

// -----------------------------------------------------------------------------

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void	ft_randomize(void *param)
{
	uint32_t	i;
	uint32_t	y;
	uint32_t	color;

	(void)param;
	i = 0;
	while (i < image->width)
	{
		y = 0;
		while (y < image->height)
		{
			color = ft_pixel(
				100 + (rand() % (256 - 100)), // R
				0,                            // G
				0,                            // B
				100 + (rand() % (256 - 100))  // A
			);
			mlx_put_pixel(image, i, y, color);
			y++;
		}
		i++;
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

int32_t main(void)
{
	mlx_t* mlx;

	// Gotta error check this stuff
	if (!(mlx = mlx_init(WIDTH, HEIGHT, "CUB3D", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}

	mlx_texture_t *texture_example = mlx_load_png("./textures/texture_example.png");
	if (!texture_example)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);		
	}
	// if (!(image = mlx_new_image(mlx, 200, 128)))
	// {
	// 	mlx_close_window(mlx);
	// 	puts(mlx_strerror(mlx_errno));
	// 	return(EXIT_FAILURE);
	// }
	image = mlx_texture_to_image(mlx, texture_example);	
	

	// if (!(image = mlx_new_image(mlx, 200, 128)))
	// {
	// 	mlx_close_window(mlx);
	// 	puts(mlx_strerror(mlx_errno));
	// 	return(EXIT_FAILURE);
	// }
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	
	//mlx_loop_hook(mlx, ft_randomize, mlx);
	mlx_loop_hook(mlx, ft_hook, mlx);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}



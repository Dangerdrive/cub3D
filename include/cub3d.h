/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliferre <aliferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:20:58 by fde-alen          #+#    #+#             */
/*   Updated: 2024/11/19 14:20:46 by aliferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//---------------------------------------------------------------------------
#ifndef CUB3D_H
# define CUB3D_H

# define WIDTH	720
# define HEIGHT	720

# define BLACK		0x000000FF
# define WHITE		0xFFFFFFFF
# define MAGENTA	0xFF00FFFF
# define CYAN		0x00FFFFFF
# define YELLOW		0xFFFF00FF
# define ORANGE		0xFFA500FF
# define PURPLE		0x800080FF
# define PINK		0xFFC0CBFF
# define LIME		0x32CD32FF
# define DEEP		0xFF1493FF
# define GREEN		0x00FF00FF
# define VIOLET		0x8A2BE2FF
# define ORANGER	0xFF4500FF
# define TOMATO		0xFF6347FF
# define AQUA		0x00FFFFFF
# define TEAL		0x008080FF
# define GOLD		0xFFD700FF
# define SILVER		0xC0C0C0FF
# define GRAY		0x808080FF
# define BROWN 		0xA52A2AFF

# define DEG2RAD	1.74532925199432954743716805979E-2	// PI / 180
# define RAD2DEG	5.72957795130823228646477218717E1	// 180 / PI

# define COLLISION_MARGIN	2.5E-1	// 1/4

# define VEC_NORTH	0
# define VEC_EAST	1
# define VEC_SOUTH	2
# define VEC_WEST	3

# define TEX_FOLDER	"/nfs/homes/aliferre/Desktop/Projetos 42/cub3d/textures/"

# define FOV		0.66
# define SPEED		6.0
# define ROT_SPEED	1.5

# include <fcntl.h>		// for open
# include <unistd.h>	// for close, read, write
# include <stdlib.h>	// for malloc, free, exit
# include <stdio.h>		// for perror
# include <string.h>	// for strerror
# include <math.h>		// for fabs, modf, cos, sin, atan2
# include <MLX42.h>

typedef int32_t		t_color;

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

// tex order: looking at N, E, S, W

typedef struct s_data
{
	mlx_t			*mlx;

	long			map_height;
	long			map_width;
	int				**map;

	mlx_image_t		*img;
	mlx_texture_t	*no_tex;
	mlx_texture_t	*tex[4];

	t_vector		pos;
	t_vector		dir;
	t_vector		plane;

	double			time;
	long			frames;

	t_color			ceil_color;
	t_color			floor_color;
}	t_data;

// ### data.c ### (static: 2, total: 3)

t_data		*ft_init_data(void);
void		ft_free_data(t_data *data);

// ### hooks.c ### (static: 1, total: 3)

void		ft_loop(void *param);
void		ft_input(void *param);

// ### render_helper.c ### (static: 0, total: 4)

t_color		ft_pixel(t_color r, t_color g, t_color b, t_color a);
t_color		ft_image_pixel(mlx_texture_t *img, long x, long y);
double		ft_get_delta_dist(double *vals);
double		ft_get_side_dist(double *vals);

// ### render.c ### (static: 4, total: 5)

void		ft_display_column(t_data *data, long x);

// ### vec_advanced.c ### (static: 1, total: 3)

double		vec_angle(t_vector vec1, t_vector vec2);
t_vector	vec_func(double (*func)(double*), size_t vec_amt, ...);

// ### vec_basic.c ### (static: 0, total: 4)

t_vector	vec_new(double x, double y);
t_vector	vec_dir(int dir);
t_vector	vec_add(t_vector vec1, t_vector vec2);
t_vector	vec_scale(t_vector vec, double scalar);
t_vector	vec_rotate(t_vector vec, double angle);

#endif

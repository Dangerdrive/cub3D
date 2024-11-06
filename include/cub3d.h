/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:20:58 by fde-alen          #+#    #+#             */
/*   Updated: 2024/10/30 16:35:28 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//---------------------------------------------------------------------------
#ifndef CUB3D_H
# define CUB3D_H

# define WIDTH 720
# define HEIGHT 720

# define BLACK	0x000000FF
# define WHITE	0xFFFFFFFF
# define MAGENTA	0xFF00FFFF
# define CYAN	0x00FFFFFF
# define YELLOW	0xFFFF00FF
# define ORANGE	0xFFA500FF
# define PURPLE	0x800080FF
# define PINK	0xFFC0CBFF
# define LIME	0x32CD32FF
# define DEEP	0xFF1493FF
# define GREEN	0x00FF00FF
# define VIOLET	0x8A2BE2FF
# define ORANGER	0xFF4500FF
# define TOMATO	0xFF6347FF
# define AQUA	0x00FFFFFF
# define TEAL	0x008080FF
# define GOLD	0xFFD700FF
# define SILVER	0xC0C0C0FF
# define GRAY	0x808080FF
# define BROWN 	0xA52A2AFF

# define PI (acos(0)*2)
# define DEG2RAD (acos(0)/90)
# define RAD2DEG (90/acos(0))

#define mapWidth 24
#define mapHeight 24
#define texWidth 64
#define texHeight 64

# include <fcntl.h>    // for open
# include <unistd.h>   // for close, read, write
# include <stdlib.h>   // for malloc, free, exit
# include <stdio.h>    // for perror
# include <string.h>   // for strerror
# include <math.h>
# include <MLX42.h>

typedef struct vector_s
{
	double	x;
	double	y;
}	vector_t;

typedef struct data_s
{
	mlx_t*	mlx;
	mlx_image_t*	img;
	mlx_texture_t*	tex;
	double fov;
	double speed;
	double rot_speed;
	double time;
	long	frames;
	long	ceil_color;
	long	floor_color;
	vector_t pos;  //x and y start position
	vector_t dir; //initial direction vector
	vector_t plane; //the 2d raycaster version of camera plane
}	data_t;

// vectors.c
vector_t	vec_new(double x, double y);
vector_t	vec_add(vector_t vec1, vector_t vec2);
vector_t	vec_sub(vector_t vec1, vector_t vec2);
vector_t	vec_scale(vector_t vec, double scalar);
vector_t	vec_rotate(vector_t vec, double angle); // Positive angle: clock-wise rotation
double		vec_dot(vector_t vec1, vector_t vec2);
double		vec_length(vector_t vec);
vector_t	vec_normal(vector_t vec);
void		vec_print(vector_t vec);
double		vec_angle(vector_t vec1, vector_t vec2);
vector_t	vec_func(double (*func)(double*), size_t vec_amt, ...);

#endif

//gcc *.c MLX42Codam/libmlx42.a -Iinclude -O3 -ldl -lglfw -pthread -lm && ./a.out mandelbrot


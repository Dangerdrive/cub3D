/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:20:58 by fde-alen          #+#    #+#             */
/*   Updated: 2024/11/18 22:53:39 by fde-alen         ###   ########.fr       */
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

# define VEC_NORTH_Y	-1, 0	// Use vec_new(0, VEC_NORTH_Y)
# define VEC_EAST_X		1	// Use vec_new(VEC_EAST_X, 0)
# define VEC_SOUTH_Y	1	// Use vec_new(0, VEC_SOUTH_Y)
# define VEC_WEST_X		-1	// Use vec_new(VEC_WEST_X, 0)

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
# include <libft.h>

typedef enum e_bool
{
	FALSE,
	TRUE
}			t_bool;

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

	long			map_height;//precisa ser long?
	long			map_width;
	int				**map;

	mlx_image_t		*img;
	mlx_texture_t	*no_tex;//qual uso?
	mlx_texture_t	*tex[4];
	char			*no_path;
	char			*so_path;
	char			*we_path;
	char			*ea_path;

	t_vector		pos;
	t_vector		dir;
	t_vector		plane;

	double			time;
	long			frames;

	t_color			ceil_color;
	t_color			floor_color;
	int				textures_count;

	int				map_start_line;
	t_bool			is_map;
	t_bool			map_ended;
}	t_data;

// typedef struct s_map_info
// {
	// char			**map;
	// char			*no_path;
	// char			*so_path;
	// char			*we_path;
	// char			*ea_path;
	// uint32_t		ceil_color;
	// uint32_t		floor_color;
	// int				textures_count;
// }				t_data;


/* validations*/
void			check_map(char *map_path);

// ### check_rgb.c ### (static: 3, total: 4)

void			check_rgb(t_color *color, char *rgb_color, char *original, char c);


// ### copy_texture_path.c ### (static: 4, total: 5)

void			copy_texture_path(t_data *data, char **texture, char *path,
					char *prefix, char *line);//

// ### copy_texture_path.c ###

t_data			*load_map_file(t_data *data, char *map_path);


// ### load_textures.c ### (static: 3, total: 5)

void			parse_textures(t_data *data, char *temp_line, int fd);
void			ft_load_tex(t_data *data);

// ### replace_map_tabs.c ### (static: 2, total: 3)

void			replace_map_tabs(t_data *data);

// ### validate_args.c ### (static: 1, total: 3)

void			exit_usage_error(char *msg);
void			check_args(int argc, char **argv);

// ### validate_map.c ###

void			exit_map_error(t_data *data, char *error_msg);

// ### data.c ###

t_data			*ft_init_data(char *map_path);
void			ft_free_data(t_data *data);

// ### hooks.c ### (static: 1, total: 3)

void		ft_loop(void *param);
void		ft_input(void *param);

// ### render_helper.c ### (static: 0, total: 4)

t_color		ft_pixel(t_color r, t_color g, t_color b, t_color a);
t_color		ft_image_pixel(mlx_texture_t *img, long x, long y);

// ### render.c ### (static: 4, total: 5)

void		ft_display_column(t_data *data, long x);

// ### vec_advanced.c ### (static: 1, total: 3)

double		vec_angle(t_vector vec1, t_vector vec2);
t_vector	vec_func(double (*func)(double*), size_t vec_amt, ...);

// ### vec_basic.c ### (static: 0, total: 4)

t_vector	vec_new(double x, double y);
t_vector	vec_add(t_vector vec1, t_vector vec2);
t_vector	vec_scale(t_vector vec, double scalar);
t_vector	vec_rotate(t_vector vec, double angle);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliferre <aliferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:20:58 by fde-alen          #+#    #+#             */
/*   Updated: 2024/11/21 15:27:24 by aliferre         ###   ########.fr       */
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

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
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

	long			map_height;
	long			map_width;
	char			**map;

	mlx_image_t		*img;
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

	int				map_start;
	int				map_end;
	t_bool			is_map;
	t_bool			map_ended;

	int				invalid_chars;
	int				player_count;
}	t_data;

// ###################
// ### VALIDATIONS ###
// ###################

// ### check_rgb.c ### (static: 3, total: 4)

void		check_rgb(t_color *color, char *rgb_color, char *original,
				char c);

// ### copy_texture_path.c ### (static: 4, total: 5)

void		copy_texture_path(t_data *data, char **texture, char *path,
				char *prefix, char *line);

// ### load_map_file.c ###

void		set_map_dimensions(t_data *data);
t_data		*load_map_file(t_data *data, char *map_path);

// ### load_map.c ###

void		load_map_content(t_data *data, char *temp, int fd);

// ### load_textures.c ### (static: 3, total: 5)

void		parse_textures(t_data *data, char *temp_line, int fd);
void		ft_load_tex(t_data *data);

// ### load_textures_utils.c ###

t_bool		starts_with_texture_prefix(char *temp);
t_bool		starts_with_color_prefix(char *temp);
t_bool		is_invalid_line(char *temp);
t_bool		all_textures_loaded(t_data *map);

// ### replace_map_tabs.c ### (static: 2, total: 3)

void		replace_map_tabs(t_data *data);

// ### validate_args.c ### (static: 1, total: 3)

void		exit_usage_error(char *msg);
void		check_args(int argc, char **argv);

// ### validate_map_extern_walls.c ###

void		validate_map_extern_walls(t_data *data);

// ### validate_map.c ###

void		exit_map_error(t_data *data, char *error_msg);
void		validate_map(t_data *data);

// ##################
// ### RAYCASTING ###
// ##################

// ### data.c ###

t_data		*ft_init_cub(char *map_path);
void		ft_free_data(t_data *data);

// ### hooks.c ### (static: 1, total: 3)

void		ft_loop(void *param);
void		ft_input(void *param);

// ### render_helper.c ### (static: 0, total: 5)

t_color		ft_pixel(t_color r, t_color g, t_color b, t_color a);
t_color		ft_image_pixel(mlx_texture_t *img, long x, long y);
t_vector	ft_get_delta_dist(t_vector ray_dir);
t_vector	ft_get_side_dist(t_vector ray_dir, t_vector pos, \
					t_vector map_pos, t_vector delta_dist);
bool		ft_is_space_empty(t_data *data, t_vector pos);

// ### render.c ### (static: 4, total: 5)

void		ft_display_column(t_data *data, long x);

// ### vec_advanced.c ### (static: 1, total: 2)

double		vec_angle(t_vector vec1, t_vector vec2);

// ### vec_basic.c ### (static: 0, total: 5)

t_vector	vec_new(double x, double y);
t_vector	vec_dir(int dir);
t_vector	vec_add(t_vector vec1, t_vector vec2);
t_vector	vec_scale(t_vector vec, double scalar);
t_vector	vec_rotate(t_vector vec, double angle);

#endif

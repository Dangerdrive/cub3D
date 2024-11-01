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

# include <fcntl.h>    // for open
# include <unistd.h>   // for close, read, write
# include <stdlib.h>   // for malloc, free, exit
# include <stdio.h>    // for perror
# include <string.h>   // for strerror
# include <math.h>
# include <MLX42.h>
# include <libft.h>

typedef enum e_bool
{
	FALSE,
	TRUE
}			t_bool;

typedef struct s_data
{
	struct s_map	*map;

}				t_data;

typedef struct s_map
{
	int 			**map_array;
	char			*no_path;
	char			*so_path;
	char			*we_path;
	char			*ea_path;
	uint32_t		ceiling_color;
	uint32_t		floor_color;

}				t_map;



/* validations*/
void			exit_error(char *msg);
void			check_map(char *map_path);
void			check_args(int argc, char **argv);


#endif

//gcc *.c MLX42Codam/libmlx42.a -Iinclude -O3 -ldl -lglfw -pthread -lm && ./a.out mandelbrot


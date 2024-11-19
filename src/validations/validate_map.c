#include "cub3d.h"

void	exit_map_error(t_data *data, char *error_msg)
{
	ft_dprintf(STDERR_FILENO, "Error: %s\n", error_msg);
	ft_free_data(data);
	exit(EXIT_FAILURE);
}

static void	check_map_content(t_data *data)
{
	if (data->invalid_chars != 0)
		exit_map_error(data, "map contains invalid characters");
	else if (data->player_count != 1)
		exit_map_error(data, "map contains invalid number of players");
}

static void	set_player_dir(t_data *data, char d)
{
	if (data->map[i][j] == 'N')
		data->dir = vec_new(0, VEC_NORTH_Y);
	else if (data->map[i][j] == 'S')
		data->dir = vec_new(0, VEC_SOUTH_Y);
	else if (data->map[i][j] == 'E')
		data->dir = vec_new(VEC_EAST_X, 0);
	else if (data->map[i][j] == 'W')
		data->dir = vec_new(VEC_WEST_X, 0);
}

static t_bool	char_is_invalid(char c)
{
	if (c == ' ' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == '0' || c == '1' || c == '\0'
		|| c == '\n' || (c >= '\t' && c <= '\r'))
		return (false);
	return (true);
}

// void	validate_map(t_data *data)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (data->map[i])
// 	{
// 		j = 0;
// 		while (data->map[i][j])
// 		{
// 			if (char_is_invalid(data->map[i][j]) == 0)
// 				data->invalid_chars++;//iniciar valor //checar valor
// 			else if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
// 				|| data->map[i][j] == 'E' || data->map[i][j] == 'W')
// 			{
// 				data->player_count++;//iniciar valor //checar valor
// 				data->dir = set_player_dir(data, data->map[i][j]);
// 				data->pos = vec_new(j, i);
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }
static void	set_player_start(t_data *data, char *d)
{
	data->player_count++;//iniciar valor //checar valor
	data->dir = set_player_dir(data, data->map[i][j]);
	data->pos = vec_new(j, i);
}

void	validate_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (char_is_invalid(data->map[i][j]) == 0)
				data->invalid_chars++;//iniciar valor //checar valor
			else if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
				|| data->map[i][j] == 'E' || data->map[i][j] == 'W')
				set_player_start(data, data->map[i][j])
			j++;
		}
		i++;
	}
	check_map_content(data);
	validate_map_extern_walls(data);
}

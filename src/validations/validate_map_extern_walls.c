#include "cub3d.h"

static void	expand_map_with_padding(t_data *data)
{
	size_t	i;
	size_t	j;
	char	**new_map;

	i = 0;
	new_map = ft_calloc(data->lines + 1, sizeof(char *));
	while (i < (size_t)data->lines)
	{
		j = 0;
		new_map[i] = ft_calloc((data->columns + 1), sizeof(char));
		while (j < ft_strlen(data->map[i]) - 1)
		{
			new_map[i][j] = data->map[i][j];
			j++;
		}
		while (j < (size_t)data->columns)
		{
			new_map[i][j] = '2';
			j++;
		}
		i++;
	}
	ft_free_arr(data->map);
	data->map = new_map;
}

static int	count_non_padding_chars(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '2')
		i++;
	return (i);
}

static t_bool	check_diagonals(t_data *data, int line, int col)
{
	char	**map;

	map = data->map;
	if (line > 0 && col > 0
		&& (map[line - 1][col - 1] == ' ' || map[line - 1][col - 1] == '2'))
		return (false);
	if (line + 1 < data->lines && col > 0
		&& (map[line + 1][col - 1] == ' ' || map[line + 1][col - 1] == '2'))
		return (false);
	if (line > 0 && col + 1 < data->columns
		&& (map[line - 1][col + 1] == ' ' || map[line - 1][col + 1] == '2'))
		return (false);
	if (line + 1 < data->lines && col + 1 < data->columns
		&& (map[line + 1][col + 1] == ' ' || map[line + 1][col + 1] == '2'))
		return (false);
	return (true);
}

static t_bool	check_adjacent(t_data *data, int line, int col)
{
	char	**map;

	map = data->map;
	if (line <= 0 || line >= data->lines || col <= 0 || col >= data->columns)
		return (false);
	if (line > 0 && (map[line - 1][col] == ' ' || map[line - 1][col] == '2'))
		return (false);
	if (line + 1 < data->lines
		&& (map[line + 1][col] == ' ' || map[line + 1][col] == '2'))
		return (false);
	if (col > 0 && (map[line][col - 1] == ' ' || map[line][col - 1] == '2'))
		return (false);
	if (col + 1 < data->columns
		&& (map[line][col + 1] == ' ' || map[line][col + 1] == '2'))
		return (false);
	return (true);
}

void	validate_map_extern_walls(t_data *data)
{
	char	**map;
	int		y;
	int		x;

	y = 0;
	expand_map_with_padding(data);
	map = data->map;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '0' || ft_strchr("NSWE", map[y][x]))
			{
				if ((y == 0 || y == data->lines - 1)
					|| (x == 0 || x == count_non_padding_chars(map[y]) - 1))
					exit_map_error(data, "invalid map edges.");//change message
				if (!check_adjacent(data, y, x) || !check_diagonals(data, y, x))
					exit_map_error(data, "invalid map walls.");//change message
			}
			x++;
		}
		y++;
	}
}

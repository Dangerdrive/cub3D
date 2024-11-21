/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 00:20:26 by fde-alen          #+#    #+#             */
/*   Updated: 2024/11/21 00:20:27 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_map_error(t_data *data, char *error_msg)
{
	ft_dprintf(STDERR_FILENO, "Error: %s\n", error_msg);
	ft_free_data(data);
	exit(EXIT_FAILURE);
}

static void	set_player_dir(t_data *data, char d)
{
	if (d == 'N')
		data->dir = vec_new(0, -1);
	else if (d == 'S')
		data->dir = vec_new(0, 1);
	else if (d == 'E')
		data->dir = vec_new(1, 0);
	else if (d == 'W')
		data->dir = vec_new(-1, 0);
}

static t_bool	char_is_invalid(char c)
{
	if (c == ' ' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == '0' || c == '1' || c == '\0'
		|| c == '\n' || (c >= '\t' && c <= '\r'))
		return (false);
	return (true);
}

static void	set_player_start(t_data *data, char d, int i, int j)
{
	data->player_count++;
	set_player_dir(data, d);
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
			if (char_is_invalid(data->map[i][j]))
				data->invalid_chars++;
			else if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
				|| data->map[i][j] == 'E' || data->map[i][j] == 'W')
				set_player_start(data, data->map[i][j], i, j);
			j++;
		}
		i++;
	}
	if (data->invalid_chars != 0)
		exit_map_error(data, "map contains invalid characters");
	else if (data->player_count != 1)
		exit_map_error(data, "map contains invalid number of players");
	validate_map_extern_walls(data);
}

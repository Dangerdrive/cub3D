/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 00:19:24 by fde-alen          #+#    #+#             */
/*   Updated: 2024/11/21 00:19:25 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	handle_map_line(t_data *data, char *temp)
{
	static int	i;

	if (data->map_ended)
	{
		free(temp);
		set_map_dimensions(data);
		exit_map_error(data, "invalid map");
	}
	if (data->map_end >= data->map_start)
	{
		data->map[i] = ft_strdup(temp);
		i++;
		data->is_map = true;
	}
}

void	load_map_content(t_data *data, char *temp, int fd)
{
	data->map_end = 0;
	data->is_map = false;
	data->map_ended = false;
	temp = get_next_line(fd);
	while (temp)
	{
		if (temp[0] == '\n')
		{
			if (data->is_map && !data->map_ended)
				data->map_ended = true;
		}
		else
			handle_map_line(data, temp);
		data->map_end++;
		free(temp);
		temp = get_next_line(fd);
	}
	close(fd);
}

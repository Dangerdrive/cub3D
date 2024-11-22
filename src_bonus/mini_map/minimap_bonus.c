/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:04:42 by aliferre          #+#    #+#             */
/*   Updated: 2024/11/22 18:56:14 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_player_square(t_data *data, int start_x, int start_y, int size)
{
	uint32_t	x;
	uint32_t	y;
	uint32_t	end_x;
	uint32_t	end_y;

	end_x = start_x + size;
	end_y = start_y + size;
	y = (uint32_t)start_y;
	while (y < end_y)
	{
		x = (uint32_t)start_x;
		while (x < end_x)
		{
			if (x < data->mini_map->width && y < data->mini_map->height)
				mlx_put_pixel(data->mini_map, x, y, 0xFFFFFFFF);
			x++;
		}
		y++;
	}
}

void	draw_player(t_data *data, int scale)
{
	float	start_x;
	float	start_y;
	int		player_scale;

	player_scale = (int)(scale * 0.5);
	start_x = data->pos.x * scale - player_scale / 2;
	start_y = data->pos.y * scale - player_scale / 2;
	if (data->mini_map)
		draw_player_square(data, start_x, start_y, player_scale);
}

void	draw_map_square(t_data *data, t_mini mini)
{
	uint32_t	x;
	uint32_t	y;

	y = mini.start_y;
	while (y < mini.y)
	{
		x = mini.start_x;
		while (x < mini.x)
		{
			if (x < data->mini_map->width && y < data->mini_map->height)
				mlx_put_pixel(data->mini_map, x, y, mini.color);
			x++;
		}
		y++;
	}
}

void	draw_map(t_data *data, int scale)
{
	int				i;
	int				j;
	t_mini			mini;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width && data->map[i][j])
		{
			mini.start_x = j * scale;
			mini.start_y = i * scale;
			mini.x = mini.start_x + scale;
			mini.y = mini.start_y + scale;
			if (data->map[i][j] == '1')
				mini.color = 0xA5808005;
			else
				mini.color = 0x00FF0000;
			draw_map_square(data, mini);
			j++;
		}
		i++;
	}
	mlx_image_to_window(data->mlx, data->mini_map, WIDTH - WIDTH / 4,
		HEIGHT - HEIGHT / 4);
}


void	minimap(void *param)
{
	t_data	*data;
	int		scale;

	data = param;
	if (data->map_height > data->map_width)
		scale = 150 / data->map_height;
	else
		scale = 150 / data->map_width;
	draw_map(data, scale);
	draw_player(data, scale);
	mlx_image_to_window(data->mlx, data->mini_map, WIDTH - WIDTH / 4,
		HEIGHT - HEIGHT / 4);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliferre <aliferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:01:22 by aliferre          #+#    #+#             */
/*   Updated: 2024/11/21 15:22:51 by aliferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_color	ft_pixel(t_color r, t_color g, t_color b, t_color a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

t_color	ft_image_pixel(mlx_texture_t *img, long x, long y)
{
	long	pos;
	uint8_t	*pixels;

	pos = 4 * (y * img->width + x);
	pixels = img->pixels + pos;
	return (ft_pixel(pixels[0], pixels[1], pixels[2], pixels[3]));
}

t_vector	ft_get_delta_dist(t_vector ray_dir)
{
	return (vec_new(fabs(1.0 / ray_dir.x), fabs(1.0 / ray_dir.y)));
}

t_vector	ft_get_side_dist(t_vector ray_dir, t_vector pos, \
							t_vector map_pos, t_vector delta_dist)
{
	t_vector	ret;

	ret = vec_add(vec_add(map_pos, vec_scale(pos, -1)), vec_new(1, 1));
	if (ray_dir.x < 0)
		ret.x = 1 - ret.x;
	if (ray_dir.y < 0)
		ret.y = 1 - ret.y;
	return (vec_new(ret.x * delta_dist.x, ret.y * delta_dist.y));
}

bool	ft_is_space_empty(t_data *data, t_vector pos)
{
	char	c;

	c = data->map[(long)pos.y][(long)pos.x];
	return (c == '0' || c == 'N' || c == 'E' || c == 'S' || c == 'W');
}

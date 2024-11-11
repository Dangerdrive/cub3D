/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliferre <aliferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:01:22 by aliferre          #+#    #+#             */
/*   Updated: 2024/11/11 18:59:34 by aliferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_color	ft_pixel(t_color r, t_color g, t_color b, t_color a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

t_color	ft_image_pixel(mlx_texture_t *img, long x, long y)
{
	long	pos;
	uint8_t	*pixels;

	pos = 4 * (y * TEX_WIDTH + x);
	pixels = img->pixels + pos;
	return (ft_pixel(pixels[0], pixels[1], pixels[2], pixels[3]));
}

// Args: ray_dir
double	ft_get_delta_dist(double *vals)
{
	return (fabs(1.0 / vals[0]));
}

// Args: ray_dir, pos, map_pos, delta_dist
double	ft_get_side_dist(double *vals)
{
	double	ret;

	ret = vals[2] - vals[1] + 1;
	if (vals[0] < 0)
		ret = 1 - ret;
	return (ret * vals[3]);
}

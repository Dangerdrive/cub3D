/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_basic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:10:22 by aliferre          #+#    #+#             */
/*   Updated: 2024/11/22 18:56:35 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

t_vector	vec_new(double x, double y)
{
	t_vector	vec;

	vec.x = x;
	vec.y = y;
	return (vec);
}

t_vector	vec_dir(int dir)
{
	if (dir == VEC_NORTH)
		return (vec_new(0, -1));
	if (dir == VEC_EAST)
		return (vec_new(1, 0));
	if (dir == VEC_SOUTH)
		return (vec_new(0, 1));
	if (dir == VEC_WEST)
		return (vec_new(-1, 0));
	return (vec_new(0, 0));
}

t_vector	vec_add(t_vector vec1, t_vector vec2)
{
	return (vec_new(vec1.x + vec2.x, vec1.y + vec2.y));
}

t_vector	vec_scale(t_vector vec, double scalar)
{
	return (vec_new(vec.x * scalar, vec.y * scalar));
}

// Positive angle: clock-wise rotation
t_vector	vec_rotate(t_vector vec, double angle)
{
	double	integer;
	double	decimal;
	double	radian;
	double	cos_a;
	double	sin_a;

	decimal = modf(angle, &integer);
	angle = (long)integer % 360 + decimal;
	radian = angle * DEG2RAD;
	cos_a = cos(radian);
	sin_a = sin(radian);
	return (vec_new(vec.x * cos_a + vec.y * sin_a, \
					-vec.x * sin_a + vec.y * cos_a));
}

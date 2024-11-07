/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliferre <aliferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:10:22 by aliferre          #+#    #+#             */
/*   Updated: 2024/11/07 18:31:02 by aliferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector	vec_new(double x, double y)
{
	t_vector	vec;

	vec.x = x;
	vec.y = y;
	return (vec);
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

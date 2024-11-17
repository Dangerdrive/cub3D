/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_advanced.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliferre <aliferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:31:38 by aliferre          #+#    #+#             */
/*   Updated: 2024/11/07 18:31:40 by aliferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static double	vec_dot(t_vector vec1, t_vector vec2)
{
	return ((vec1.x * vec2.x) + (vec1.y * vec2.y));
}

double	vec_angle(t_vector vec1, t_vector vec2)
{
	double	n;

	n = vec1.y * vec2.x - vec1.x * vec2.y;
	return (atan2(n, vec_dot(vec1, vec2)) * RAD2DEG);
}

// Applies a function to each coordinate of 1 or more vectors
t_vector	vec_func(double (*func)(double*), size_t vec_amt, ...)
{
	va_list		va[2];
	double		*vecs[2];
	t_vector	ret;
	size_t		i;

	va_start(va[0], vec_amt);
	va_start(va[1], vec_amt);
	vecs[0] = malloc(vec_amt * sizeof(double));
	vecs[1] = malloc(vec_amt * sizeof(double));
	i = 0;
	while (i++ < vec_amt)
	{
		vecs[0][i - 1] = va_arg(va[0], t_vector).x;
		vecs[1][i - 1] = va_arg(va[1], t_vector).y;
	}
	va_end(va[0]);
	va_end(va[1]);
	ret = vec_new(func(vecs[0]), func(vecs[1]));
	free(vecs[0]);
	free(vecs[1]);
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_advanced.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliferre <aliferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:31:38 by aliferre          #+#    #+#             */
/*   Updated: 2024/11/19 14:46:36 by aliferre         ###   ########.fr       */
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

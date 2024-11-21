/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 00:19:29 by fde-alen          #+#    #+#             */
/*   Updated: 2024/11/21 00:19:30 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	starts_with_texture_prefix(char *temp)
{
	return (ft_strncmp("NO", temp, 2) == 0
		|| ft_strncmp("SO", temp, 2) == 0
		|| ft_strncmp("WE", temp, 2) == 0
		|| ft_strncmp("EA", temp, 2) == 0);
}

t_bool	starts_with_color_prefix(char *temp)
{
	return (ft_strncmp("F", temp, 1) == 0
		|| ft_strncmp("C", temp, 1) == 0);
}

t_bool	is_invalid_line(char *temp)
{
	return (temp[0] != '\n' && temp[0] != '\0');
}

t_bool	all_textures_loaded(t_data *map)
{
	return (map->no_path && map->so_path && map->we_path && map->ea_path
		&& map->ceil_color && map->floor_color);
}

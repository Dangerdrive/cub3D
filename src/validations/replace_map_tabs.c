/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_map_tabs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 00:19:48 by fde-alen          #+#    #+#             */
/*   Updated: 2024/11/21 00:19:49 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	tabs_count(char *line)
{
	int	i;
	int	tabs;

	i = 0;
	tabs = 0;
	while (line[i])
	{
		if (line[i] == '\t')
			tabs++;
		i++;
	}
	return (tabs);
}

static char	*tabs_to_spaces(char *line, int tabs)
{
	char	*replaced;
	int		i;
	int		j;
	int		x;

	i = 0;
	j = 0;
	replaced = ft_calloc(sizeof(char), ft_strlen(line) + (tabs * 4) + 1);
	while (line[i])
	{
		x = 0;
		if (line[i] == '\t')
		{
			while (x++ < 4)
				replaced[j++] = ' ';
			i++;
			continue ;
		}
		replaced[j++] = line[i++];
	}
	return (replaced);
}

void	replace_map_tabs(t_data *data)
{
	int		i;
	int		tabs;
	char	*temp;

	i = 0;
	while (data->map[i])
	{
		tabs = tabs_count(data->map[i]);
		if (tabs > 0)
		{
			temp = data->map[i];
			data->map[i] = tabs_to_spaces(data->map[i], tabs);
			free(temp);
		}
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 00:19:00 by fde-alen          #+#    #+#             */
/*   Updated: 2024/11/21 19:22:34 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	exit_rgb_error(t_data *data, char *original_input, char **rgb,
			int arr_len)
{
	free(original_input);
	ft_strarr_free(rgb, arr_len);
	ft_dprintf(STDERR_FILENO, "Error: invalid color(s).\n" \
		"Please input valid RGB color(s) in the" \
		"format \"R,G,B\", where R, G, and B are integer values between 0 and"\
		" 255.\n");
	ft_free_data(data);
	exit(EXIT_FAILURE);
}

static void	sanitize_rgb_input(t_data *data, char *rgb_color,
				char *original_input)
{
	int	qtd;
	int	space;

	qtd = 0;
	space = 0;
	while (ft_isblank(*rgb_color) || *rgb_color == data->color)
	{
		if (*rgb_color == data->color)
			qtd++;
		if (ft_isblank(*rgb_color))
			space++;
		rgb_color++;
	}
	if (qtd != 1 || space < 1)
		exit_rgb_error(data, original_input, NULL, 0);
}

static void	split_rgb(t_data *data, char ***rgb, char *rgb_color,
		char *original_input)
{
	char	*temp_strim;
	int		i;

	i = 0;
	while (ft_isblank(*rgb_color) || *rgb_color == data->color)
		rgb_color++;
	*rgb = ft_split(rgb_color, ',');
	if (!*rgb)
		exit_rgb_error(data, original_input, *rgb, 0);
	while ((*rgb)[i])
	{
		if (ft_strncmp((*rgb)[i], "\n", 1) == 0 || ft_isblank((*rgb)[i][0]))
			exit_rgb_error(data, original_input, *rgb, ft_strarr_len(*rgb));
		temp_strim = ft_strtrim((*rgb)[i], " \t\v\f\r\n\b");
		free((*rgb)[i]);
		(*rgb)[i] = temp_strim;
		i++;
	}
	if (i != 3)
		exit_rgb_error(data, original_input, *rgb, ft_strarr_len(*rgb));
}

void	check_rgb(t_data *data, t_color *color, char *rgb_color,
			char *original_input)
{
	char	**rgb;
	int		i;
	int		j;

	i = 0;
	sanitize_rgb_input(data, rgb_color, original_input);
	split_rgb(data, &rgb, rgb_color, original_input);
	while (rgb[i])
	{
		j = 0;
		while (rgb[i][j])
		{
			if (!ft_isdigit(rgb[i][j]))
				exit_rgb_error(data, original_input, rgb, ft_strarr_len(rgb));
			j++;
		}
		if (ft_atoi(rgb[i]) < 0 || ft_atoi(rgb[i]) > 255)
			exit_rgb_error(data, original_input, rgb, ft_strarr_len(rgb));
		i++;
	}
	*color = ft_pixel(ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]), 255);
	ft_strarr_free(rgb, i);
}

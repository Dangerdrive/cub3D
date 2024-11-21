/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 00:19:00 by fde-alen          #+#    #+#             */
/*   Updated: 2024/11/21 00:19:03 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	exit_rgb_error(char *original_input, char **rgb, int arr_len)
{
	free(original_input);
	ft_strarr_free(rgb, arr_len);
	ft_dprintf(STDERR_FILENO, "Error: invalid color(s).\n" \
		"Please input valid RGB color(s) in the" \
		"format \"R,G,B\", where R, G, and B are integer values between 0 and"\
		" 255.\n");
	exit(EXIT_FAILURE);
}

static void	sanitize_rgb_input(char *rgb_color, char *original_input, char c)
{
	int	qtd;
	int	space;

	qtd = 0;
	space = 0;
	while (ft_isblank(*rgb_color) || *rgb_color == c)
	{
		if (*rgb_color == c)
			qtd++;
		if (ft_isblank(*rgb_color))
			space++;
		rgb_color++;
	}
	if (qtd != 1 || space < 1)
		exit_rgb_error(original_input, NULL, 0);
}

static void	split_rgb(char ***rgb, char *rgb_color,
		char *original_input, char c)
{
	char	*temp_strim;
	int		i;

	i = 0;
	while (ft_isblank(*rgb_color) || *rgb_color == c)
		rgb_color++;
	*rgb = ft_split(rgb_color, ',');
	if (!*rgb)
		exit_rgb_error(original_input, *rgb, i);
	while ((*rgb)[i])
	{
		if (ft_strncmp((*rgb)[i], "\n", 1) == 0 || ft_isblank((*rgb)[i][0]))
			exit_rgb_error(original_input, *rgb, i);
		temp_strim = ft_strtrim((*rgb)[i], " \t\v\f\r\n\b");
		free((*rgb)[i]);
		(*rgb)[i] = temp_strim;
		i++;
	}
	if (i != 3)
		exit_rgb_error(original_input, *rgb, i);
}

void	check_rgb(t_color *color, char *rgb_color, char *original_input, char c)
{
	char	**rgb;
	int		i;
	int		j;

	i = 0;
	sanitize_rgb_input(rgb_color, original_input, c);
	split_rgb(&rgb, rgb_color, original_input, c);
	while (rgb[i])
	{
		j = 0;
		while (rgb[i][j])
		{
			if (!ft_isdigit(rgb[i][j]))
				exit_rgb_error(original_input, rgb, i);
			j++;
		}
		if (ft_atoi(rgb[i]) < 0 || ft_atoi(rgb[i]) > 255)
			exit_rgb_error(original_input, rgb, i);
		i++;
	}
	*color = ft_pixel(ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]), 255);
	ft_strarr_free(rgb, i);
}

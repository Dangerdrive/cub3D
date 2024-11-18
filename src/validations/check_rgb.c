#include "cub3d.h"

void	exit_rgb_error(char *original, char **rgb, int arr_len)
{
	free(original);
	ft_strarr_free(rgb, arr_len);
	// perror("Error: invalid color.\n");

	printf("Error: invalid color(s).\nPlease input valid RGB color(s) in the" \
		"format \"R,G,B\", where R, G, and B are integer values between 0 and"\
		" 255.\n");
	exit(EXIT_FAILURE);
}

void	check_colors(t_data *data, char *line, char *temp)
{
	static int	ceiling;
	static int	floor;

	if (ft_strncmp("F", temp, 1) == 0)
		floor++;
	if (ft_strncmp("C", temp, 1) == 0)
		ceiling++;
	if (ceiling > 1 || floor > 1)
	{
		free(line);
		exit_map_error(data, "duplicated color.");
	}
}

void	sanitize_rgb_input(char *rgb_color, char *original, char c)
{
	int	qtd;
	int	space;

	qtd = 0;
	space = 0;
	while (ft_isspace(*rgb_color) || *rgb_color == c)
	{
		if (*rgb_color == c)
			qtd++;
		if (ft_isspace(*rgb_color))
			space++;
		rgb_color++;
	}
	if (qtd != 1 || space < 1)
		exit_rgb_error(original, NULL, 0);
}

void	split_rgb(char ***rgb, char *rgb_color, char *original, char c)
{
	char	*temp_strim;
	int		i;

	i = 0;
	while (ft_isspace(*rgb_color) || *rgb_color == c)
		rgb_color++;
	*rgb = ft_split(rgb_color, ',');
	if (!*rgb)
		exit_rgb_error(original, *rgb, i);
	while ((*rgb)[i])
	{
		if (ft_strncmp((*rgb)[i], "\n", 1) == 0 || ft_isspace((*rgb)[i][0]))
			exit_rgb_error(original, *rgb, i);
		temp_strim = ft_strtrim((*rgb)[i], " \t\v\f\r\n\b");
		free((*rgb)[i]);
		(*rgb)[i] = temp_strim;
		i++;
	}
	if (i != 3)
		exit_rgb_error(original, *rgb);
}

void	check_rgb(t_color *color, char *rgb_color, char *original, char c)
{
	char	**rgb;
	int		i;
	int		j;

	i = 0;
	sanitize_rgb_input(rgb_color, original, c);
	split_rgb(&rgb, rgb_color, original, c);
	while (rgb[i])
	{
		j = 0;
		while (rgb[i][j])
		{
			if (!ft_isdigit(rgb[i][j]))
				exit_rgb_error(original, rgb);
			j++;
		}
		if (ft_atoi(rgb[i]) < 0 || ft_atoi(rgb[i]) > 255)
			exit_rgb_error(original, rgb);
		i++;
	}
	*color = ft_pixel(ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]), 255);
	ft_strarr_free(rgb, i);
}

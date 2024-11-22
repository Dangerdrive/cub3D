/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 00:19:59 by fde-alen          #+#    #+#             */
/*   Updated: 2024/11/22 19:09:18 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	exit_usage_error(char *msg)
{
	char	*usage;

	usage = "usage: \n" \
			"\t./cub3d_bonus <directory><map.cub>\n" \
			"example:" \
			"\t./cub3d_bonus maps/map_sample.cub\n";
	ft_dprintf(STDERR_FILENO, "%s\n %s", msg, usage);
	exit(EXIT_FAILURE);
}

static t_bool	extension_is_invalid(char *map_file)
{
	char	*valid_extension;
	int		file_len;
	int		ext_len;
	int		start_pos;

	valid_extension = ".cub";
	file_len = ft_strlen(map_file);
	ext_len = ft_strlen(valid_extension);
	if (file_len < ext_len)
		return (true);
	start_pos = file_len - ext_len;
	while (map_file[start_pos] && *valid_extension)
	{
		if (map_file[start_pos++] != *valid_extension++)
			return (true);
	}
	return (false);
}

void	check_args(int argc, char **argv)
{
	if (argc < 2)
		exit_usage_error("Error: no map used.\n");
	else if (argc > 2)
		exit_usage_error("Error: too many arguments\n");
	else if (argc == 2)
	{
		if (extension_is_invalid(argv[1]))
			exit_usage_error("Error: invalid map extension\n");
	}
}

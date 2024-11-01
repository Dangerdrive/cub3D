#include "cub3d.h"

void exit_error(char *msg)
{
	perror(msg);
	printf("usage: \n" \
			"\t./cub3d <directory><map.cub>\n" \
			"example:" \
			"\t./cub3d maps/map_sample.cub\n");
	exit(EXIT_FAILURE);
}

// t_bool	extension_is_invalid(char *map_file)
// {
// 	char	*valid_extension;
// 	int		i;
// 	int		len;
// 	t_bool	is_invalid;

// 	i = 0;
// 	valid_extension = ".cub";
// 	len = ft_strlen(map_file);
// 	len = len - 4;
// 	while (map_file[len] && valid_extension[i] && map_file[len] == valid_extension[i])
// 	{
// 		i++;
// 		len++;
// 	}
// 	if (valid_extension[i] == '\0')
// 		return(false);
// 	return(true);
// }

t_bool	extension_is_invalid(char *map_file)
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


void check_args(int argc, char **argv)
{
	if (argc < 2)
		exit_error("Error: no map used.\n");
	else if (argc > 2)
		exit_error("Error: too many arguments\n");
	else if (argc == 2)
	{
		if (extension_is_invalid(argv[1]))
			exit_error("Error: invalid map extension\n");
	}
}

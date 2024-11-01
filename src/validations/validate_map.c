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

void	check_extension(char *map_file)
{
	char	*dotcub;
	int		i;
	int		len;

	i = 0;
	dotcub = ".cub";
	len = ft_strlen(map_file);
	len = len - 4;
	while (map_file[len] && dotcub[i] && map_file[len] == dotcub[i])
	{
		i++;
		len++;
	}
	if (dotcub[i] == '\0')
		return ;
	handle_error(WARNING_EXT);
	exit(EXIT_FAILURE);
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
			exit_error("Error: invalid map exension\n");

	}

}
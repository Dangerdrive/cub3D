#include "cub3d.h"

void	exit_texture_error(char *error_msg, char *line)
{
	free(line);
	printf(error_msg);
	exit(EXIT_FAILURE);
}

void	trim_line(char *str, char *line)
{
	size_t	i;
	size_t	whitespace_count;

	i = 0;
	whitespace_count = 0;
	while (str[i] && !ft_isspace(str[i]))
		i++;
	while (str[i] && ft_isspace(str[i]))
	{
		whitespace_count++;
		i++;
	}
	if (str[i] != '\0' && str[i] != '\n')
		exit_texture_error("Error: invalid texture path.\n", line);
	str[i - whitespace_count] = '\0';
}

void	check_spaces(char *temp, char *prefix, char *line)
{
	int	i;

	i = 0;
	if (ft_strncmp(prefix, temp, 2) == 0)
		i += 2;
	if (ft_isspace(temp[i]))
		return ;
	else
		exit_texture_error("Error: invalid texture path.\n", line);
}

void	copy_texture_path(char **texture, char *path, char *prefix,
	char *line)
{
	int	prefix_count;

	prefix_count = 0;
	if (*texture != NULL)
		exit_texture_error("Error: duplicated texture path.\n", line);
	check_spaces(path, prefix, line);
	while (ft_isspace(*path) || ft_strncmp(prefix, path, 2) == 0)
	{
		if (ft_strncmp(prefix, path, 2) == 0)
		{
			prefix_count++;
			path++;
		}
		path++;
	}
	trim_line(path, line);
	if (!check_path(path) || prefix_count != 1)
		exit_texture_error("Error: invalid texture path.\n", line);
	*texture = ft_strdup(path);
}

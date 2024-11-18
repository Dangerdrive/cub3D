#include "cub3d.h"

void	exit_texture_error(t_data *data, char *error_msg, char *line)
{
	free(line);
	ft_dprintf(STDERR_FILENO, "Texture error: %s\n", error_msg);
	ft_free_data(data);
	exit(EXIT_FAILURE);
}

void	trim_line(t_data *data, char *str, char *line)
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
		exit_texture_error(data, "invalid texture path.", line);
	str[i - whitespace_count] = '\0';
}

void	check_spaces(t_data *data, char *temp, char *prefix, char *line)
{
	int	i;

	i = 0;
	if (ft_strncmp(prefix, temp, 2) == 0)
		i += 2;
	if (ft_isspace(temp[i]))
		return ;
	else
		exit_texture_error(data, "invalid texture path.", line);
}

void	copy_texture_path(t_data *data, char **texture, char *path,
	char *prefix, char *line)
{
	int	prefix_count;

	prefix_count = 0;
	if (*texture != NULL)
		exit_texture_error(data, "duplicated texture path.", line);
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
		exit_texture_error(data, "invalid texture path.", line);
	*texture = ft_strdup(path);
}

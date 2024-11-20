#include "cub3d.h"

static void	exit_texture_error(t_data *data, char *error_msg, char *line)
{
	free(line);
	ft_dprintf(STDERR_FILENO, "Texture error: %s\n", error_msg);
	ft_free_data(data);
	exit(EXIT_FAILURE);
}

static void	trim_line(t_data *data, char *str, char *line)
{
	size_t	i;
	size_t	whitespace_count;

	i = 0;
	whitespace_count = 0;
	while (str[i] && !ft_isblank(str[i]))
		i++;
	while (str[i] && ft_isblank(str[i]))
	{
		whitespace_count++;
		i++;
	}
	if (str[i] != '\0' && str[i] != '\n')
		exit_texture_error(data, "invalid texture path.", line);
	str[i - whitespace_count] = '\0';
}

static void	check_spaces(t_data *data, char *temp, char *prefix, char *line)
{
	int	i;

	i = 0;
	if (ft_strncmp(prefix, temp, 2) == 0)
		i += 2;
	if (ft_isblank(temp[i]))
		return ;
	else
		exit_texture_error(data, "invalid texture path.", line);
}

t_bool	can_open_texture(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (false);
	close(fd);
	return (true);
}

// static char	*get_prefix(char **texture)
// {
// 	if (ft_strncmp("NO", *texture, 2) == 0)
// 		return ("NO");
// 	if (ft_strncmp("SO", *texture, 2) == 0)
// 		return ("SO");
// 	if (ft_strncmp("WE", *texture, 2) == 0)
// 		return ("WE");
// 	if (ft_strncmp("EA", *texture, 2) == 0)
// 		return ("EA");
// 	return (NULL);
// }

// void	copy_texture_path(t_data *data, char **texture, char *path,
// 	char *line)
// {
// 	int		prefix_count;
// 	char	*prefix;

// 	prefix_count = 0;
// 	prefix = get_prefix(texture);
// 	if (*texture != NULL)
// 		exit_texture_error(data, "duplicated texture.", line);
// 	check_spaces(data, path, prefix, line);
// 	while (ft_isblank(*path) || ft_strncmp(prefix, path, 2) == 0)
// 	{
// 		if (ft_strncmp(prefix, path, 2) == 0)
// 		{
// 			prefix_count++;
// 			path++;
// 		}
// 		path++;
// 	}
// 	trim_line(data, path, line);
// 	if (!can_open_texture(path) || prefix_count != 1)
// 		exit_texture_error(data, "invalid texture path.", line);
// 	*texture = ft_strdup(path);
// }

void	copy_texture_path(t_data *data, char **texture, char *path,
	char *prefix, char *line)
{
	int	prefix_count;

	prefix_count = 0;
	if (*texture != NULL)
		exit_texture_error(data, "duplicated texture path.", line);
	check_spaces(data, path, prefix, line);
	while (ft_isblank(*path) || ft_strncmp(prefix, path, 2) == 0)
	{
		if (ft_strncmp(prefix, path, 2) == 0)
		{
			prefix_count++;
			path++;
		}
		path++;
	}
	trim_line(data, path, line);
	if (!can_open_texture(path))
		exit_texture_error(data, "cannot open texture.", line);
	if (prefix_count != 1)
		exit_texture_error(data, "invalid number of texture per direction.",
			line);
	*texture = ft_strdup(path);
}

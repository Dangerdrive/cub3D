#include "cub3d.h"

void	alloc_map(t_map_info *map_info, char *temp, int fd)
{
	int	map_size;

	map_size = 0;
	temp = get_next_line(fd);
	while (temp)
	{
		map_size++;
		free(temp);
		temp = get_next_line(fd);
	}
	close(fd);
	if (map_size == 0)
		handle_error("Error: no map information found.\n");//
	map_info->map = ft_calloc(sizeof(char *), (map_size + 1));
	if (!map_info->map)
		handle_error("Error: map allocation error.\n");//
}

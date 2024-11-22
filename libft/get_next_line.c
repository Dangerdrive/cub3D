/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:41:37 by fde-alen          #+#    #+#             */
/*   Updated: 2024/11/22 16:32:49 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	add_char_node(t_char_node **char_list, char c);
char	*list_to_string(t_char_node *char_list, int len);
int		contains_newline(t_char_node *char_list);
void	free_char_list(t_char_node **char_list);

static int	extract_line(t_file_state *file, t_char_node **char_list, int bytes)
{
	int	len;

	len = 0;
	while (file->pos < bytes)
	{
		if (file->buffer[file->pos] == '\n' || file->buffer[file->pos] == '\0')
		{
			add_char_node(char_list, file->buffer[file->pos]);
			len++;
			file->pos++;
			break ;
		}
		add_char_node(char_list, file->buffer[file->pos]);
		len++;
		file->pos++;
	}
	if (file->pos == bytes)
		file->pos = 0;
	return (len);
}

static int	read_to_buffer(int fd, t_file_state *file, t_char_node **char_list)
{
	file->bytes = read(fd, file->buffer, BUFFER_SIZE);
	if (file->bytes < 0)
	{
		free_char_list(char_list);
		return (0);
	}
	if (file->bytes == 0)
		return (1);
	file->buffer[file->bytes] = '\0';
	return (2);
}

char	*get_next_line(int fd)
{
	static t_file_state	file;
	t_char_node			*char_list;
	int					len;
	int					verify;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	char_list = NULL;
	len = 0;
	while (contains_newline(char_list) == 0)
	{
		if (file.pos > 0 && file.pos != file.bytes && file.bytes != 0)
		{
			len += extract_line(&file, &char_list, file.bytes);
			continue ;
		}
		verify = read_to_buffer(fd, &file, &char_list);
		if (verify == 0)
			return (NULL);
		if (verify == 1)
			break ;
		len += extract_line(&file, &char_list, file.bytes);
	}
	return (list_to_string(char_list, len));
}

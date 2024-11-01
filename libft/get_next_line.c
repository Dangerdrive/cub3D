/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:41:37 by fde-alen          #+#    #+#             */
/*   Updated: 2024/01/22 00:24:08 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3000
#endif

/**
 * Joins two strings, creating a new string, and frees the first string.
 *
 * Dynamically allocates memory to create a new string that concatenates 'str1'
 * and 'str2'. It also ensures that if 'str1' is NULL, it is initialized to an
 * empty string before concatenation. After creating the new string, 'str1' is
 * freed.
 *
 * @param[in] str1 The first string to concatenate. It is freed after
 *                 concatenation.
 * @param[in] str2 The second string to concatenate.
 *
 * @return A new dynamically allocated string containing 'str1' followed by
 *         'str2'.
 */

static char	*gnl_strjoin(char *str1, char *str2)
{
	size_t	i;
	size_t	j;
	char	*result;

	if (!str1)
	{
		str1 = (char *)malloc(1 * sizeof(char));
		str1[0] = 0;
	}
	if (!str1 || !str2)
		return (NULL);
	result = malloc(sizeof(char) * ((ft_strlen(str1) + ft_strlen(str2)) + 1));
	if (result == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (str1)
		while (str1[++i] != '\0')
			result[i] = str1[i];
	while (str2[j] != '\0')
		result[i++] = str2[j++];
	result[ft_strlen(str1) + ft_strlen(str2)] = '\0';
	free(str1);
	return (result);
}

/**
 * Reads text from a file descriptor into a buffer until a newline character is
 * found or the end of the file is reached.
 *
 * Continuously reads text from 'fd' and appends it to 'line_buffer' until a
 * newline character is encountered or EOF is reached. Utilizes 'gnl_strjoin'
 * for appending and ensures memory allocation failure is handled.
 *
 * @param[in] fd The file descriptor from which to read.
 * @param[in] line_buffer The buffer containing the current line content.
 *
 * @return The updated line buffer containing text from the file descriptor.
 */
static char	*read_text(int fd, char *line_buffer)
{
	char	*read_buffer;
	int		read_size;

	read_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!read_buffer)
		return (NULL);
	read_size = 1;
	while (!ft_strchr(line_buffer, '\n') && read_size != 0)
	{
		read_size = read(fd, read_buffer, BUFFER_SIZE);
		if (read_size == -1)
		{
			free(line_buffer);
			free(read_buffer);
			return (NULL);
		}
		read_buffer[read_size] = '\0';
		line_buffer = gnl_strjoin(line_buffer, read_buffer);
	}
	free(read_buffer);
	return (line_buffer);
}

/**
 * Extracts a single line, including the newline character, from a buffer.
 *
 * Allocates memory for a new string and copies characters from 'line_buffer'
 * into it until a newline character or the end of the string is reached.
 * The resulting string includes the newline character if present.
 *
 * @param[in] line_buffer The buffer from which to extract the line.
 *
 * @return A newly allocated string containing the extracted line.
 */
static char	*extract_line(char *line_buffer)
{
	int		i;
	char	*extracted_line;

	i = 0;
	if (!line_buffer[i])
		return (0);
	while (line_buffer[i] && line_buffer[i] != '\n')
		i++;
	extracted_line = (char *)malloc(sizeof(char) * (i + 2));
	if (!extracted_line)
		return (NULL);
	i = 0;
	while (line_buffer[i] && line_buffer[i] != '\n')
	{
		extracted_line[i] = line_buffer[i];
		i++;
	}
	if (line_buffer[i] == '\n')
	{
		extracted_line[i] = line_buffer[i];
		i++;
	}
	extracted_line[i] = '\0';
	return (extracted_line);
}

/**
 * Extracts remaining text after the first newline in a buffer.
 *
 * Allocates a new string and copies characters from 'line_buffer',
 * starting after the first newline. Frees the original 'line_buffer'.
 *
 * @param line_buffer The buffer to extract text from.
 * @return A newly allocated string containing the remaining text.
 */
static char	*extract_remaining(char *line_buffer)
{
	int		i;
	int		j;
	char	*remaining_buffer;

	i = 0;
	j = 0;
	while (line_buffer[i] && line_buffer[i] != '\n')
		i++;
	if (!line_buffer[i])
	{
		free(line_buffer);
		return (NULL);
	}
	remaining_buffer = malloc(sizeof(char) * (ft_strlen(line_buffer) - i + 1));
	if (!remaining_buffer)
		return (NULL);
	i++;
	while (line_buffer[i])
		remaining_buffer[j++] = line_buffer[i++];
	remaining_buffer[j] = '\0';
	free(line_buffer);
	return (remaining_buffer);
}

/**
 * Reads a line from a file descriptor, handling intermediate buffering.
 *
 * Manages a static buffer for leftover data between calls. Reads a line
 * up to and including the newline (or to EOF if no newline is present).
 * Uses helper functions for reading, line extraction, and buffer management.
 *
 * @param fd The file descriptor to read from.
 * @return A newly allocated string containing the next line, or NULL if
 *         there's nothing left to read or an error occurs.
 */
char	*get_next_line(int fd)
{
	char		*line;
	static char	*line_buffer;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line_buffer = read_text(fd, line_buffer);
	if (!line_buffer)
		return (NULL);
	line = extract_line(line_buffer);
	line_buffer = extract_remaining(line_buffer);
	return (line);
}
/*
#include <stdio.h>
#include "get_next_line.h"

int main(void) {
    char *line;

    printf("Enter lines of text (press Ctrl+D to stop):\n");

    while ((line = get_next_line(0)) != NULL) {
        printf("Line: %s\n", line);
        free(line);
    }

    printf("End of input.\n");

    return 0;
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:12:13 by fde-alen          #+#    #+#             */
/*   Updated: 2024/01/19 18:01:20 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * Outputs a string to the specified file descriptor.
 *
 * Writes each character of the string to the given file descriptor. If the
 * string is NULL, it outputs "(null)".
 *
 * @param fd The file descriptor to write to.
 * @param str The string to be printed.
 * @return The number of characters printed.
 */
int	ft_print_str(int fd, char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (write(fd, "(null)", 6));
	while (str[count])
	{
		write(fd, &str[count], 1);
		count++;
	}
	return (count);
}

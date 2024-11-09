/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 20:15:31 by fde-alen          #+#    #+#             */
/*   Updated: 2024/01/19 18:02:27 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * Outputs a single character to the specified file descriptor.
 *
 * Writes the given character to the file descriptor provided. This function
 * is used for printing a single character to a file descriptor, typically
 * used in formatted output functions like printf.
 *
 * @param fd The file descriptor to write to.
 * @param c The character to be printed.
 * @return The number of characters printed, which is always 1.
 */
int	ft_print_char(int fd, char c)
{
	write(fd, &c, 1);
	return (1);
}

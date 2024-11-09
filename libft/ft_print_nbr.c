/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 20:15:31 by fde-alen          #+#    #+#             */
/*   Updated: 2024/01/19 18:01:46 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * Prints an integer with a specific flag to the specified file descriptor.
 *
 * Converts an integer to a string and prints it. If the flag is '+' and the
 * number is non-negative, a '+' is prefixed. If the flag is ' ' and the
 * number is non-negative, a space is prefixed.
 *
 * @param fd The file descriptor to write to.
 * @param num The integer to be printed.
 * @param flag The flag character ('+', ' ', or other).
 * @return The length of the printed string including the flag character.
 */
int	ft_print_nbr(int fd, int num, const char flag)
{
	int		count;
	char	*str;

	count = 0;
	if (flag == '+')
	{
		if (num >= 0)
			count += write(fd, "+", 1);
	}
	else if (flag == ' ')
	{
		if (num >= 0)
			count += write(fd, " ", 1);
	}
	str = ft_itoa(num);
	count += ft_print_str(fd, str);
	free(str);
	return (count);
}

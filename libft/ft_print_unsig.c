/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsig.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 20:16:38 by fde-alen          #+#    #+#             */
/*   Updated: 2024/04/05 16:50:01 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * Prints an unsigned integer to the specified file descriptor.
 *
 * Converts an unsigned integer to a base-10 string and then outputs it.
 * Utilizes the `ft_uitoa_base` function for conversion and `ft_print_str`
 * for printing the converted string.
 *
 * @param num The unsigned integer to be printed.
 * @return The length of the printed string.
 */
int	ft_print_unsigned(int fd, unsigned int num)
{
	char	*str;
	int		len;

	str = ft_uitoa_base(num, 10, 'x');
	len = ft_print_str(fd, str);
	free(str);
	return (len);
}

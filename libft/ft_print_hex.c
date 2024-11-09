/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 20:15:11 by fde-alen          #+#    #+#             */
/*   Updated: 2024/04/05 16:51:10 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
* Prints an unsigned integer in hexadecimal format to the specified file
* descriptor.
 *
 * Converts the number to a hexadecimal string using either lowercase ('x') or
 * uppercase ('X') characters. If the flag '#' is provided and the number is
 * non-zero, the appropriate prefix ("0x" or "0X") is added.
 *
 * @param num The unsigned integer to be printed in hexadecimal.
 * @param format The format character ('x' for lowercase, 'X' for uppercase).
 * @param flag The flag character ('#', or other).
 * @return The length of the printed string including the prefix if applicable.
 */
int	ft_print_hex(int fd, unsigned int num, const char format, const char flag)
{
	char	*str;
	int		len;

	len = 0;
	if (flag == '#' && num != 0)
	{
		if (format == 'x')
			len += ft_print_str(fd, "0x");
		if (format == 'X')
			len += ft_print_str(fd, "0X");
	}
	if (format == 'x')
		str = ft_uitoa_base(num, 16, 'x');
	if (format == 'X')
		str = ft_uitoa_base(num, 16, 'X');
	len += ft_print_str(fd, str);
	free(str);
	return (len);
}

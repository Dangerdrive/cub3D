/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 20:14:56 by fde-alen          #+#    #+#             */
/*   Updated: 2024/01/19 18:01:36 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * Prints a pointer address to the specified file descriptor.
 *
 * Converts the address of a pointer to a hexadecimal string and then prints
 * it preceded by "0x". If the pointer is NULL, it outputs "(nil)".
 *
 * @param fd The file descriptor to write to.
 * @param num The pointer address to be printed.
 * @return The length of the printed address.
 */
int	ft_print_ptr(int fd, unsigned long int num)
{
	char	*str;
	int		len;

	len = 0;
	if (num == 0)
	{
		len += write(fd, "(nil)", 5);
		return (len);
	}
	str = ft_uitoa_base(num, 16, 'x');
	len += write(fd, "0x", 2);
	len += ft_print_str(fd, str);
	free(str);
	return (len);
}

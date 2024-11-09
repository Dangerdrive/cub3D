/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 20:17:50 by fde-alen          #+#    #+#             */
/*   Updated: 2024/04/05 16:53:53 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * Parses the format string and dispatches appropriate print functions.
 *
 * This function iterates over the format string and processes each formatting
 * directive it encounters. It supports a range of format specifiers (like %c,
 * %s, %d, %i, %u, %x, %X, and %p). The function also handles flags for certain
 * format specifiers. It sends output to the file descriptor defined by the FD
 * macro. The function is versatile and capable of printing various data types to
 * a specified file descriptor.
 *
 * @param[in] args Variable arguments list containing the data to be printed.
 * @param[in] type Pointer to the current position in the format string.
 *
 * @return The total number of characters printed.
 */
static int	parse_format_type(va_list args, const char *type)
{
	int		len;
	char	flag;

	flag = NO_FLAG;
	len = 0;
	if (*type == '#' || *type == ' ' || *type == '+')
	{
		flag = *type;
		type++;
	}
	if (*type == '%')
		len += ft_print_char(FD, '%');
	else if (*type == 'c')
		len += ft_print_char(FD, va_arg(args, int));
	else if (*type == 's')
		len += ft_print_str(FD, va_arg(args, char *));
	else if (*type == 'd' || *type == 'i')
		len += ft_print_nbr(FD, va_arg(args, int), flag);
	else if (*type == 'u')
		len += ft_print_unsigned(FD, va_arg(args, unsigned int));
	else if (*type == 'x' || *type == 'X')
		len += ft_print_hex(FD, va_arg(args, unsigned int), *type, flag);
	else if (*type == 'p')
		len += ft_print_ptr(FD, va_arg(args, unsigned long));
	return (len);
}

/**
 * Custom implementation of printf that directs output to a specific file
 * descriptor.
 *
 * This function works similarly to the standard printf but outputs to the file
 * descriptor specified by the FD macro. It can handle various format specifiers
 * and flags. This function is useful for directing formatted output to different
 * streams, like standard output or standard error, as defined by the FD macro.
 * It parses the format string and handles each directive accordingly.
 *
 * @param[in] frmt The format string containing text to be printed and format
 *                 specifiers.
 *
 * @return The total number of characters printed or -1 if an error occurs.
 */
int	ft_printf(const char *frmt, ...)
{
	va_list	args;
	int		len;

	if (frmt == NULL)
		return (-1);
	len = 0;
	va_start(args, frmt);
	while (*frmt)
	{
		if (*frmt == '%')
		{
			len += parse_format_type(args, frmt + 1);
			if (*(frmt + 1) == '#' || *(frmt + 1) == ' ' || *(frmt + 1) == '+')
				frmt++;
			frmt++;
		}
		else
			len += ft_print_char(FD, *frmt);
		frmt++;
	}
	va_end(args);
	return (len);
}

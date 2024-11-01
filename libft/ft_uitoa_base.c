/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 22:35:21 by fde-alen          #+#    #+#             */
/*   Updated: 2024/01/22 00:34:06 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
* Converts an unsigned long to its string representation in a given base.
*
* Allocates a new string and converts 'num' to a string in the specified
* 'base' (typically 16 for hex). Uses 'format' ('x' or 'X') for hex digit case.
*
* @param num The unsigned long number to convert.
* @param base The base for the conversion.
* @param format The format specifier ('x' or 'X') for hex digit case.
* @return A pointer to the new string, or NULL if allocation fails.
*/
char	*ft_uitoa_base(unsigned long num, int base, const char format)
{
	char	*str;
	int		len;

	len = ft_unumlen_base(num, base);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	while (len >= 0)
	{
		if (format == 'x')
			str[len--] = "0123456789abcdef"[num % base];
		if (format == 'X')
			str[len--] = "0123456789ABCDEF"[num % base];
		num /= base;
	}
	return (str);
}

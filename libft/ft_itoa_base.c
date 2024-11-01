/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:42:51 by fde-alen          #+#    #+#             */
/*   Updated: 2024/04/27 12:14:20 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Converts a number to a string in the specified base.
 *
 * @param[in] num The number to convert.
 * @param[in] base The numerical base (2-16) for the conversion.
 * @return A string representing the number in the specified base,
 *  or NULL if fails.
 */
char	*ft_itoa_base(long long num, int base)
{
	char	*str;
	int		len;
	int		sign;

	if (num < 0)
		sign = -1;
	else
		sign = 1;
	len = ft_numlen_base(num, base);
	if (sign == -1)
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	while (len >= 0)
	{
		str[len--] = "0123456789abcdef"[(sign * (num % base))];
		num /= base;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:42:51 by fde-alen          #+#    #+#             */
/*   Updated: 2024/04/27 12:12:44 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Converts an integer to a string representation.
 *
 * @param[in] num The integer to convert.
 * @return A string representing the integer or NULL if allocation fails.
 */
char	*ft_itoa(int num)
{
	char	*str;
	int		len;
	int		sign;

	if (num < 0)
		sign = -1;
	else
		sign = 1;
	len = ft_numlen(num);
	if (sign == -1)
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	while (len >= 0)
	{
		str[len--] = (sign * (num % 10)) + '0';
		num /= 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}

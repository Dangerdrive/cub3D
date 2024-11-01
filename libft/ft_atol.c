/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:58:52 by fde-alen          #+#    #+#             */
/*   Updated: 2024/03/06 12:11:59 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Converts a string to a long integer (ASCII to Long).
 *
 * This function scans the string pointed to by nptr for the first sequence of
 * characters that represent a decimal number, which could be preceded by white
 * space characters (as defined by isspace) and an optional '+' or '-' sign. It
 * then converts this number into a long integer. The function stops reading the
 * string at the first character that is not a decimal digit.
 *
 * @param[in] nptr Pointer to the null-terminated string to be converted.
 * @return The long integer value of the number in the string.
 */
long	ft_atol(const char *nptr)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
	{
		nptr++;
	}
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
	{
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (sign * result);
}

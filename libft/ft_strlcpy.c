/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:06:29 by fde-alen          #+#    #+#             */
/*   Updated: 2024/04/27 12:04:52 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Copies a string into another, ensuring the destination buffer is not
 * overrun and is null-terminated.
 *
 * @param[out] dest The destination buffer where the source string is copied.
 * @param[in] src The source string to copy.
 * @param[in] destsize The size of the destination buffer.
 * @return The total length of the source string.
 */
size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	unsigned int	i;
	unsigned int	srclen;

	i = 0;
	srclen = 0;
	while (src[srclen])
		srclen++;
	if (destsize > 0)
	{
		while (src[i] && i < destsize - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (srclen);
}

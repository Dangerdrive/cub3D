/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:59:21 by fde-alen          #+#    #+#             */
/*   Updated: 2024/01/22 00:27:50 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Locates a substring in a string, examining only the first 'len' chars.
 *
 * Searches for the first occurrence of 'little' in 'big', examining
 * up to 'len' characters. Stops at '\0'. If 'little' is empty, returns 'big';
 * if 'little' not found, returns NULL.
 *
 * @param big The string to search in.
 * @param little The substring to locate.
 * @param len The number of chars to search in 'big'.
 * @return A pointer to the first occurrence of 'little', or NULL if not found.
 */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	llen;

	llen = ft_strlen(little);
	if (llen == 0)
		return ((char *)big);
	if (llen > len)
		return (NULL);
	while (*big && len >= llen)
	{
		if (ft_memcmp(big, little, llen) == 0)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}

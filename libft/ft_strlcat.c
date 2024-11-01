/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 02:19:38 by fde-alen          #+#    #+#             */
/*   Updated: 2024/04/27 12:04:29 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Appends a string to the end of another, handling buffer sizes.
 *
 * @param[in, out] dest The destination string to which the source is appended.
 * @param[in] src The source string to append to the destination.
 * @param[in] destsize The total size of the destination buffer.
 * @return The total length of the string attempted to create, which is
 *         the initial length of dest plus the length of src.
 */
size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (destsize <= dest_len)
		return (src_len + destsize);
	i = 0;
	while (src[i] && dest_len + i + 1 < destsize)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (src_len + dest_len);
}

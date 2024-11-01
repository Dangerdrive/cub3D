/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:59:21 by fde-alen          #+#    #+#             */
/*   Updated: 2024/01/11 17:20:20 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Copies 'n' bytes from memory area 'src' to memory area 'dest'.
 * Unlike ft_memcpy, ft_memmove handles overlapping memory areas.
 * 
 * @param[out] dest A pointer to the destination memory area.
 * @param[in] src A pointer to the source memory area.
 * @param[in] n The number of bytes to copy.
 * @return A pointer to the destination memory area 'dest'.
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_ptr;
	unsigned char	*src_ptr;

	dest_ptr = (unsigned char *)dest;
	src_ptr = (unsigned char *)src;
	if (dest_ptr == src_ptr)
		return (dest);
	if (dest_ptr < src_ptr)
	{
		while (n--)
			*dest_ptr++ = *src_ptr++;
	}
	else
	{
		dest_ptr += n;
		src_ptr += n;
		while (n--)
			*--dest_ptr = *--src_ptr;
	}
	return (dest);
}

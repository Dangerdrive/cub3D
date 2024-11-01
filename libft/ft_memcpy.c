/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:59:21 by fde-alen          #+#    #+#             */
/*   Updated: 2024/01/11 17:18:37 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Copies 'n' bytes from memory area 'src' to memory area 'dest'.
 * The memory areas must not overlap.
 * 
 * @param[out] dest A pointer to the destination memory area.
 * @param[in] src A pointer to the source memory area.
 * @param[in] n The number of bytes to copy.
 * @return A pointer to the destination memory area 'dest'.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_cpy;
	const unsigned char	*src_cpy;

	if (dest == NULL && src == NULL)
		return (NULL);
	dest_cpy = (unsigned char *)dest;
	src_cpy = (const unsigned char *)src;
	while (n--)
		*dest_cpy++ = *src_cpy++;
	return (dest);
}

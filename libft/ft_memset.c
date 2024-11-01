/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:59:21 by fde-alen          #+#    #+#             */
/*   Updated: 2024/01/11 17:18:48 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Fills the first 'n' bytes of the memory area pointed to by 's'
 * with the constant byte 'c'.
 * 
 * @param[out] s A pointer to the memory area to be filled.
 * @param[in] c The byte to fill the area with.
 * @param[in] n The number of bytes to be filled.
 * @return A pointer to the memory area 's'.
 */
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*tmp_str;
	unsigned char	tmp_char;

	tmp_str = s;
	tmp_char = c;
	while (n-- > 0)
	{
		*tmp_str++ = tmp_char;
	}
	return (s);
}

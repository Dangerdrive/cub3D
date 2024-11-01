/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:59:21 by fde-alen          #+#    #+#             */
/*   Updated: 2024/01/11 17:20:01 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Compares the first 'n' bytes of two memory areas 's1' and 's2'.
 * 
 * @param[in] s1 The first memory area.
 * @param[in] s2 The second memory area.
 * @param[in] n The number of bytes to compare.
 * @return An integer less than, equal to, or greater than zero if 's1' is
 * found, respectively, to be less than, to match, or be greater than 's2'.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1 = s1;
	const unsigned char	*p2 = s2;

	while (n--)
	{
		if (*p1 != *p2)
		{
			if (*p1 - *p2 > 0)
				return (1);
			return (-1);
		}
		p1++;
		p2++;
	}
	return (0);
}

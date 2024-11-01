/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:59:21 by fde-alen          #+#    #+#             */
/*   Updated: 2024/04/27 12:13:44 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Sets the first n bytes of the memory area pointed to by s to zero.
 *
 * @param[in, out] s The memory area to fill.
 * @param[in] n The number of bytes to set to zero.
 */
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n-- > 0)
		*p++ = '\0';
}

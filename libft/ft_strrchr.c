/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:59:21 by fde-alen          #+#    #+#             */
/*   Updated: 2024/01/11 16:57:29 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Locates the last occurrence of a character in a string.
 *
 * @param[in] s The string to be searched.
 * @param[in] c The character to search for. It's cast to an unsigned char.
 *
 * @return A pointer to the last occurrence of the character in the string,
 *         or NULL if the character is not found.
 */
char	*ft_strrchr(const char *s, int c)
{
	const char	*last;

	last = NULL;
	while (*s)
	{
		if (*s == (unsigned char)c)
			last = s;
		s++;
	}
	if (*s == (unsigned char)c)
		return ((char *)s);
	return ((char *)last);
}

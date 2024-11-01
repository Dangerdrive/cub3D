/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:59:21 by fde-alen          #+#    #+#             */
/*   Updated: 2024/01/11 17:12:49 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Locates the first occurrence of 'c' (converted to a char) in the
 * string pointed to by 'str'. The terminating null byte is considered
 * part of the string.
 * 
 * @param[in] str The string to be searched.
 * @param[in] c The character to search for.
 * 
 * @return A pointer to the first occurrence of 'c' in 'str'.
 *         If 'c' is not found, returns NULL.
 */
char	*ft_strchr(const char *str, int c)
{
	if (str == NULL)
		return (NULL);
	while (*str != '\0')
	{
		if (*str == (unsigned char)c)
			return ((char *)str);
		str++;
	}
	return (NULL);
}

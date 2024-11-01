/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:41:59 by fde-alen          #+#    #+#             */
/*   Updated: 2024/03/13 12:44:21 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Duplicates the string 'src' using malloc.
 * 
 * @param[in] src The string to be duplicated.
 * 
 * @return A pointer to the newly allocated string, which is a duplicate
 *         of 'src'. Returns NULL if the allocation fails.
 */
char	*ft_strdup(const char *src)
{
	char	*dest;
	char	*temp;
	size_t	len;

	len = ft_strlen(src);
	dest = ft_calloc(len + 1, sizeof(char));
	if (dest == NULL)
		return (NULL);
	temp = dest;
	while (*src)
	{
		*temp++ = *src++;
	}
	*temp = '\0';
	return (dest);
}

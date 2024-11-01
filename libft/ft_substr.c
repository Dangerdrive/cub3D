/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:30:37 by fde-alen          #+#    #+#             */
/*   Updated: 2024/01/22 00:29:32 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Extracts a substring from a string.
 *
 * Creates a new string that's a substring of 'str', starting at 'start'
 * with max length 'len'. If 'start' > str length, returns empty string.
 * If 'len' exceeds remaining str, substring extends to end of 'str'.
 * Memory allocated with malloc; caller must free it.
 *
 * @param str The source string.
 * @param start The start index of the substring.
 * @param len The maximum length of the substring.
 * @return A pointer to the newly created substring, or NULL if allocation fails.
 */
char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;

	if (len > ft_strlen(str) - start)
		len = ft_strlen(str) - start;
	if (start > ft_strlen(str))
		len = 0;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (*str && i < start)
	{
		i++;
		str++;
	}
	while (*str && i - start < len)
	{
		*substr = *str;
		i++;
		str++;
		substr++;
	}
	*substr = '\0';
	return (substr - (len));
}

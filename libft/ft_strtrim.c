/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:34:18 by fde-alen          #+#    #+#             */
/*   Updated: 2024/01/22 00:30:02 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Checks if a character is part of a given set.
 *
 * @param[in] c The character to be checked.
 * @param[in] set A null-terminated string representing the set of
 * characters to check against.
 *
 * @return 1 if the character is found in the set, 0 otherwise.
 */
static int	is_set_char(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

/**
 * Trims the beginning and end of a string by removing specified characters.
 *
 * @param[in] s1 The string to be trimmed.
 * @param[in] set A null-terminated string representing the set of characters
 * to be trimmed.
 *
 * @return A newly allocated string with the specified characters removed from
 *         the beginning and end of the original string. Returns NULL if memory
 *         allocation fails or if either of the input strings is NULL.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && is_set_char(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && is_set_char(s1[end - 1], set))
		end--;
	trimmed = (char *)malloc((end - start + 1) * sizeof(char));
	if (!trimmed)
		return (NULL);
	ft_strlcpy(trimmed, s1 + start, end - start + 1);
	return (trimmed);
}

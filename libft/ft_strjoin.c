/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:26:40 by fde-alen          #+#    #+#             */
/*   Updated: 2024/01/22 00:28:16 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Concatenates two strings into a new string.
 *
 * Allocates and returns a new string, which is the result of the concatenation
 * of `s1` and `s2`. The new string is created by first copying `s1` and then
 * appending `s2` to it. The function calculates the total length of the new
 * string as the sum of the lengths of `s1` and `s2`, plus one for the null
 * terminator. Memory for the new string is allocated using `malloc`, and both
 * `s1` and `s2` are copied/appended using `ft_strlcpy` and `ft_strlcat`.
 *
 * @param[in] s1 The prefix string.
 * @param[in] s2 The suffix string.
 *
 * @return A pointer to the newly created string, or NULL if memory allocation
 * fails.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	size_t	size;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	strjoin = (char *)malloc(sizeof(char) * size);
	if (strjoin == NULL)
		return (NULL);
	ft_strlcpy(strjoin, s1, size);
	ft_strlcat(strjoin, s2, size);
	return (strjoin);
}

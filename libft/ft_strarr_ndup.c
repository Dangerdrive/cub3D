/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarr_ndup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:38:40 by fde-alen          #+#    #+#             */
/*   Updated: 2024/04/27 12:02:19 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Duplicates an array of strings.
 *
 * @param array The array of strings to duplicate.
 * @return The duplicated array of strings, or NULL if the allocation fails.
 */
char	**ft_strarr_ndup(char **array, int n)
{
	char	**dup;
	int		i;

	if (!array)
		return (NULL);
	dup = (char **)malloc(sizeof(char *) * (n + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < n && array[i])
	{
		dup[i] = ft_strdup(array[i]);
		if (!dup[i])
		{
			ft_strarr_free(dup, i);
			return (NULL);
		}
		i++;
	}
	dup[i] = NULL;
	return (dup);
}

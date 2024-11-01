/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarr_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:38:40 by fde-alen          #+#    #+#             */
/*   Updated: 2024/03/28 13:23:23 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Removes all occurrences of a specified string from an array of strings.
 *
 * @param[in] strarr The input array of strings.
 * @param[in] str The string to remove from the array.
 * @return A new array of strings with the specified string removed,
 *         or NULL if memory allocation fails.
 */
char	**ft_strarr_strrm(char **strarr, const char *str)
{
	int		len;
	int		i;
	int		j;
	char	**new_arr;

	len = ft_strarr_len(strarr);
	i = 0;
	j = 0;
	new_arr = (char **)malloc(sizeof(char *) * (len + 1));
	if (!new_arr)
		return (NULL);
	while (strarr[i] != NULL)
	{
		if (ft_strncmp(strarr[i], str, ft_strlen(str)) != 0)
		{
			new_arr[j] = strarr[i];
			j++;
		}
		else
			free(strarr[i]);
		i++;
	}
	new_arr[j] = NULL;
	free(strarr);
	return (new_arr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarr_stradd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:52:11 by fde-alen          #+#    #+#             */
/*   Updated: 2024/04/27 12:01:42 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Duplicates an array of strings and appends a new string.
 *
 * @param[in] array The original array of strings to duplicate.
 * @param[in] len The length of the original array.
 * @param[in] new_str The new string to append to the array.
 * @return A new array with the original strings and the new string
 *         appended, or NULL if an allocation fails.
 */
static char	**ft_strarr_dup_extend(char **array, int len, const char *new_str)
{
	char	**new_array;
	int		i;

	new_array = (char **)malloc(sizeof(char *) * (len + 2));
	if (!new_array)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_array[i] = ft_strdup(array[i]);
		if (!new_array[i])
		{
			ft_strarr_free(new_array, i);
			return (NULL);
		}
		i++;
	}
	new_array[i] = ft_strdup(new_str);
	new_array[++i] = NULL;
	return (new_array);
}

/**
 * Adds a new string to the end of a dynamically allocated string array.
 *
 * @param[in, out] strarr A pointer to the array of strings to modify.
 * @param[in] str The string to add to the array.
 */
void	ft_strarr_stradd(char ***strarr, const char *str)
{
	int		len;
	char	**new_arr;

	if (!str)
		return ;
	len = ft_strarr_len(*strarr);
	new_arr = ft_strarr_dup_extend(*strarr, len, str);
	if (!new_arr)
		return ;
	ft_strarr_free(*strarr, len);
	*strarr = new_arr;
}

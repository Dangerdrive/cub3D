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
 * Searches for a string within an array of strings and returns its index.
 *
 * @param[in] strarr The array of strings to search.
 * @param[in] target The string to search for within the array.
 * @return The index of the first occurrence of the target string,
 *         or -1 if the target is not found or on error.
 */
int	ft_strarr_str(char **strarr, const char *target)
{
	int	i;

	if (!strarr || !target)
		return (-1);
	i = 0;
	while (strarr[i])
	{
		if (ft_strncmp(strarr[i], target, ft_strlen(target)) == 0)
			return (i);
		i++;
	}
	return (-1);
}

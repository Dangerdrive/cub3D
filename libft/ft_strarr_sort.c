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
 * Sorts an array of strings using the bubble sort algorithm.
 *
 * @param[in, out] arr Array of strings to be sorted.
 * @param[in] len Length of the string array.
 */
static void	sort_str_array(char **arr, int len)
{
	int		ordered;
	int		i;
	char	*tmp;

	ordered = 0;
	while (!ordered)
	{
		ordered = 1;
		i = 0;
		while (i < len - 1)
		{
			if (ft_strcmp(arr[i], arr[i + 1]) > 0)
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				ordered = 0;
			}
			i++;
		}
		len--;
	}
}

/**
 * Creates a sorted copy of the input string array.
 *
 * @param[in] strarr The input array of strings to be sorted.
 * @return A new sorted array of strings or NULL if allocation fails.
 */
char	**ft_strarr_sort(char **strarr)
{
	int		strarr_len;
	char	**sorted_strarr;

	strarr_len = ft_strarr_len(strarr);
	sorted_strarr = ft_strarr_dup(strarr);
	if (!sorted_strarr)
		return (NULL);
	sort_str_array(sorted_strarr, strarr_len);
	return (sorted_strarr);
}

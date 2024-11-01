/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarr_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:38:40 by fde-alen          #+#    #+#             */
/*   Updated: 2024/04/28 11:42:12 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Frees an array of strings and the array itself.
 *
 * @param[in, out] array The array of strings to be freed.
 * @param[in] len The number of elements in the array.
 */
void	ft_strarr_free(char **array, int len)
{
	while (len > 0)
	{
		len--;
		free(array[len]);
	}
	free(array);
}

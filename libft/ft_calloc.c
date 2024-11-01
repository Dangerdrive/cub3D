/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 21:50:44 by fde-alen          #+#    #+#             */
/*   Updated: 2024/03/12 19:23:12 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Allocates memory for an array of 'nmemb' elements of 'size' bytes each and
 * returns a pointer to the allocated memory. The memory is set to zero.
 *
 * @param[in] nmemb The number of elements to allocate.
 * @param[in] size The size of each element.
 * @return A pointer to the allocated memory, or NULL if the request fails.
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;
	size_t	total_size;

	total_size = nmemb * size;
	if (size != 0 && total_size / size != nmemb)
		return (NULL);
	arr = malloc(total_size);
	if (arr != NULL)
		ft_bzero(arr, total_size);
	return (arr);
}

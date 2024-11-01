/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:10:09 by fde-alen          #+#    #+#             */
/*   Updated: 2024/01/11 17:18:08 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Calculates the number of digits in a number for a given base.
 * 
 * @param[in] num The number to calculate the number of digits for.
 * @param[in] base The base for the calculation.
 * @return The number of digits in the number for the specified base.
 */
int	ft_numlen_base(long long num, int base)
{
	int	len;

	len = 1;
	while (num / base)
	{
		num /= base;
		len++;
	}
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:05:46 by fde-alen          #+#    #+#             */
/*   Updated: 2024/01/11 17:18:00 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Calculates the number of digits in an integer.
 * 
 * @param[in] num The integer to calculate the number of digits for.
 * @return The number of digits in the integer.
 */
int	ft_numlen(int num)
{
	int	len;

	len = 1;
	while (num / 10)
	{
		num /= 10;
		len++;
	}
	return (len);
}

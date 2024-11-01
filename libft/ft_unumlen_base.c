/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unumlen_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:10:09 by fde-alen          #+#    #+#             */
/*   Updated: 2024/01/22 00:35:19 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Calculates the length of an unsigned long in a specified base.
 *
 * Computes the number of digits needed to represent 'num' in 'base'
 * by iteratively dividing 'num' by 'base' until it's zero and counting
 * the divisions.
 *
 * @param num The unsigned long number to calculate the length for.
 * @param base The base to calculate the length in.
 * @return The number of digits needed to represent 'num' in 'base'.
 */
int	ft_unumlen_base(unsigned long num, int base)
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

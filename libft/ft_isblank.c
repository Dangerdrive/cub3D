/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isblank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:59:21 by fde-alen          #+#    #+#             */
/*   Updated: 2024/11/01 18:35:40 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Checks if a character is a blank or whitespace character.
 *
 * @param[in] c The character to check.
 * @return Non-zero if the character is blank or whitespace, zero if not.
 */
int	ft_isblank(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

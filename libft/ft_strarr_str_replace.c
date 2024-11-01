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

void	ft_strarr_str_replace(char **strarr, char *target, char *replcmt)
{
	int	i;
	int	len;

	if (!strarr || !target || !replcmt)
		return ;
	len = ft_strarr_len(strarr);
	i = 0;
	while (i < len)
	{
		if (strarr[i] && ft_strncmp(strarr[i], target, ft_strlen(target)) == 0)
		{
			free(strarr[i]);
			strarr[i] = ft_strdup(replcmt);
			if (!strarr[i])
			{
				return ;
			}
		}
		i++;
	}
}

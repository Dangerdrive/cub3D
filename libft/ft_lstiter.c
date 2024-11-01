/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:05:19 by fde-alen          #+#    #+#             */
/*   Updated: 2024/04/27 12:09:41 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Applies a function to each element of a linked list.
 *
 * @param[in] lst The linked list to iterate over.
 * @param[in] f The function to apply to each element's content.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*i;

	if (lst == NULL || f == NULL)
		return ;
	i = lst;
	while (i != NULL)
	{
		f(i->content);
		i = i->next;
	}
}

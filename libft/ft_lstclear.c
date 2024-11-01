/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:05:19 by fde-alen          #+#    #+#             */
/*   Updated: 2024/04/27 12:10:28 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Clears a linked list and frees its memory.
 *
 * @param[in, out] lst Pointer to the linked list.
 * @param[in] del The function to free each node's content.
 */
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*i;
	t_list	*next;

	if (lst == NULL || del == NULL)
		return ;
	i = *lst;
	while (i != NULL)
	{
		next = i->next;
		del(i->content);
		free(i);
		i = next;
	}
	*lst = NULL;
}

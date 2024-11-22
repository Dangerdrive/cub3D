/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:41:37 by fde-alen          #+#    #+#             */
/*   Updated: 2024/11/22 16:31:04 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	add_char_node(t_char_node **char_list, char c)
{
	t_char_node	*new_node;
	t_char_node	*curr;

	new_node = malloc(sizeof(t_char_node));
	if (!new_node)
	{
		free(new_node);
		return ;
	}
	new_node->next = NULL;
	new_node->c = c;
	if (*char_list == NULL)
	{
		*char_list = new_node;
		return ;
	}
	curr = *char_list;
	while (curr != NULL && curr->next != NULL)
		curr = curr->next;
	curr->next = new_node;
}

char	*list_to_string(t_char_node *char_list, int len)
{
	t_char_node	*temp;
	char		*str;
	int			i;

	i = 0;
	if (char_list == NULL || len <= 0)
		return (NULL);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (char_list != NULL)
	{
		str[i] = char_list->c;
		temp = char_list;
		char_list = char_list->next;
		free(temp);
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	contains_newline(t_char_node *char_list)
{
	if (!char_list)
		return (0);
	while (char_list)
	{
		if (char_list->c == '\n' || char_list->c == '\0')
			return (1);
		char_list = char_list->next;
	}
	return (0);
}

void	free_char_list(t_char_node **char_list)
{
	t_char_node	*temp;
	t_char_node	*curr;

	curr = *char_list;
	while (curr != NULL)
	{
		temp = curr;
		curr = curr->next;
		free(temp);
	}
	*char_list = NULL;
}

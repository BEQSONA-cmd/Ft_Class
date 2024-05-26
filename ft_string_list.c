/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 21:26:55 by btvildia          #+#    #+#             */
/*   Updated: 2024/05/26 13:55:28 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_class.h"

t_string_node	*create_node(char *str)
{
	t_string_node	*new_node;

	new_node = (t_string_node *)malloc(sizeof(t_string_node));
	if (new_node)
	{
		new_node->str = strdup(str);
		new_node->next = NULL;
	}
	return (new_node);
}

void	add_string(t_string_node **head, char *str)
{
	t_string_node	*new_node;
	t_string_node	*current;

	new_node = create_node(str);
	if (*head == NULL)
		*head = new_node;
	else
	{
		current = *head;
		while (current->next)
			current = current->next;
		current->next = new_node;
	}
}

void	free_strings(t_string_node *head)
{
	t_string_node	*current;
	t_string_node	*next;

	current = head;
	while (current)
	{
		next = current->next;
		free(current->str);
		free(current);
		current = next;
	}
}

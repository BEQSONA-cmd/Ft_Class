/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 13:51:04 by btvildia          #+#    #+#             */
/*   Updated: 2024/05/26 13:55:26 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_class.h"

t_func_node	*create_func_node(void (*func)(void))
{
	t_func_node	*new_node;

	new_node = (t_func_node *)malloc(sizeof(t_func_node));
	if (new_node)
	{
		new_node->func = func;
		new_node->next = NULL;
	}
	return (new_node);
}

void	add_function(t_func_node **head, void (*func)(void))
{
	t_func_node	*new_node;
	t_func_node	*current;

	new_node = create_func_node(func);
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

void	free_functions(t_func_node *head)
{
	t_func_node	*current;
	t_func_node	*next;

	current = head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

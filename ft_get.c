/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 19:33:15 by btvildia          #+#    #+#             */
/*   Updated: 2024/05/26 20:26:56 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_class.h"

// for getting int attributes from the class
int	get_int(t_class *class, char *name)
{
	t_attribute	*attr;

	attr = get_attribute(class, name);
	if (attr != NULL && attr->type == INT)
		return (attr->value.int_value);
	write(2, "Attribute not found or not of type int\n", 39);
	return (0);
}

// for getting string attributes from the class
char	*get_string(t_class *class, char *name)
{
	t_attribute	*attr;

	attr = get_attribute(class, name);
	if (attr != NULL && attr->type == STR)
		return (attr->value.string_value);
	write(2, "Attribute not found or not of type string\n", 42);
	return (NULL);
}

// for calling functions stored as attributes in the class
void	call_function(t_class *class, char *name)
{
	t_attribute	*attr;

	attr = get_attribute(class, name);
	if (attr != NULL && attr->type == FUNC)
		attr->value.function_value();
	else
		write(2, "Attribute not found or not of type function\n", 45);
}

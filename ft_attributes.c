/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attributes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 14:23:50 by btvildia          #+#    #+#             */
/*   Updated: 2024/05/26 14:27:26 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_class.h"

// Function to add an integer attribute
void	add_int_attribute(t_class *class, const char *name, int value)
{
	class->attributes = realloc(class->attributes, (class->size + 1)
			* sizeof(t_attribute));
	class->attributes[class->size].name = strdup(name);
	class->attributes[class->size].type = TYPE_INT;
	class->attributes[class->size].value.int_value = value;
	class->size++;
}

// Function to add a string attribute
void	add_string_attribute(t_class *class, const char *name,
		const char *value)
{
	class->attributes = realloc(class->attributes, (class->size + 1)
			* sizeof(t_attribute));
	class->attributes[class->size].name = strdup(name);
	class->attributes[class->size].type = TYPE_STRING;
	class->attributes[class->size].value.string_value = strdup(value);
	class->size++;
}

// Function to add a function attribute
void	add_function_attribute(t_class *class, const char *name,
		void (*value)(void *))
{
	class->attributes = realloc(class->attributes, (class->size + 1)
			* sizeof(t_attribute));
	class->attributes[class->size].name = strdup(name);
	class->attributes[class->size].type = TYPE_FUNCTION;
	class->attributes[class->size].value.function_value = value;
	class->size++;
}

// Function to find an attribute by name
t_attribute	*find_attribute(t_class *class, const char *name)
{
	for (size_t i = 0; i < class->size; i++)
	{
		if (strcmp(class->attributes[i].name, name) == 0)
		{
			return (&class->attributes[i]);
		}
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attributes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 14:23:50 by btvildia          #+#    #+#             */
/*   Updated: 2024/05/26 20:34:28 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_class.h"

t_class	*class(void)
{
	t_class	*new_class;

	new_class = malloc(sizeof(t_class));
	new_class->add_attribute = add_attribute;
	new_class->get_attribute = get_attribute;
	new_class->attributes = NULL;
	new_class->size = 0;
	return (new_class);
}

void	destroy_class(t_class *class)
{
	t_attribute	*attr;
	t_attribute	*next;

	attr = class->attributes;
	while (attr != NULL)
	{
		next = attr->next;
		free(attr->name);
		if (attr->type == STR)
			free(attr->value.string_value);
		free(attr);
		attr = next;
	}
	free(class);
}

// for adding attributes to the class
void	add_attribute(t_class *class, char *name, t_value_type type,
		void *value)
{
	t_attribute	*new_attribute;

	new_attribute = malloc(sizeof(t_attribute));
	new_attribute->name = ft_class_strdup(name);
	new_attribute->type = type;
	if (type == STR)
		new_attribute->value.string_value = ft_class_strdup((char *)value);
	else if (type == INT)
		new_attribute->value.int_value = *(int *)value;
	else if (type == FUNC)
		new_attribute->value.function_value = (void (*)(void))value;
	new_attribute->next = class->attributes;
	class->attributes = new_attribute;
	class->size++;
}

// for getting attributes from the class by name
void	*get_attribute(t_class *class, char *name)
{
	t_attribute	*attr;

	attr = class->attributes;
	while (attr != NULL)
	{
		if (ft_class_strcmp(attr->name, name) == 0)
			return (attr);
		attr = attr->next;
	}
	write(2, "Attribute not found\n", 21);
	return (NULL);
}

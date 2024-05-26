/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attributes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 14:23:50 by btvildia          #+#    #+#             */
/*   Updated: 2024/05/26 19:13:17 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_class.h"

t_class *class(void)
{
	t_class *new_class = malloc(sizeof(t_class));
	new_class->attributes = NULL;
	new_class->size = 0;
	new_class->attribute = add_attribute;
	new_class->get_attribute = get_attribute;
	return new_class;
}

void destroy_class(t_class *class)
{
	t_attribute *attr = class->attributes;
	t_attribute *next;
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
void add_attribute(t_class *class, char *name, t_value_type type, void *value)
{
    t_attribute *new_attribute = malloc(sizeof(t_attribute));
    new_attribute->name = strdup(name);
    new_attribute->type = type;
    if (type == STR)
        new_attribute->value.string_value = strdup((char *)value);
    else if (type == INT)
        new_attribute->value.int_value = *(int *)value;
    else if (type == FUNC)
        new_attribute->value.function_value = (void (*)(void))value;
    new_attribute->next = class->attributes;
    class->attributes = new_attribute;
    class->size++;
}

// for getting attributes from the class by name
void *get_attribute(t_class *class, char *name)
{
	t_attribute *attr = class->attributes;
	while (attr != NULL)
	{
		if (strcmp(attr->name, name) == 0)
			return attr;
		attr = attr->next;
	}
	write(2, "Attribute not found\n", 21);
	return NULL;
}

// for getting int attributes from the class
int get_int(t_class *class, char *name)
{
    t_attribute *attr = get_attribute(class, name);
    if (attr != NULL && attr->type == INT)
        return attr->value.int_value;
    write(2, "Attribute not found or not of type int\n", 39);
    return 0;
}

// for getting string attributes from the class
char *get_string(t_class *class, char *name)
{
    t_attribute *attr = get_attribute(class, name);
    if (attr != NULL && attr->type == STR)
        return attr->value.string_value;
    write(2, "Attribute not found or not of type string\n", 42);
    return NULL;
}

// for calling functions stored as attributes in the class
void call_function(t_class *class, char *name)
{
    t_attribute *attr = get_attribute(class, name);
    if (attr != NULL && attr->type == FUNC)
        attr->value.function_value();
    else
        write(2, "Attribute not found or not of type function\n", 45);
}

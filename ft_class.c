/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_class.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:16:45 by btvildia          #+#    #+#             */
/*   Updated: 2024/05/28 22:52:52 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_class.h"

t_class	*class(void)
{
	t_class	*new_class;

	new_class = malloc(sizeof(t_class));
	new_class->attributes = NULL;
	new_class->attr = attr;
	return (new_class);
}

void	destroy_class(t_class *class)
{
	t_attribute	*attr;
	t_attribute	*next;
	int			i;

	attr = class->attributes;
	while (attr)
	{
		next = attr->next;
		free(attr->name);
		if (attr->value.string_value)
			free(attr->value.string_value);
		if (attr->value.string_arr_value)
		{
			i = 0;
			while (attr->value.string_arr_value[i])
			{
				free(attr->value.string_arr_value[i]);
				i++;
			}
			free(attr->value.string_arr_value);
		}
		free(attr);
		attr = next;
	}
	free(class);
}

int	get_arg_size(void **args, size_t size[])
{
	int		i;
	int		num_args;
	size_t	arg_size;

	i = 0;
	num_args = 0;
	while (args[num_args])
		num_args++;
	arg_size = 0;
	i = 0;
	while (i < num_args)
	{
		arg_size += size[i % 3];
		i++;
	}
	return (arg_size);
}

// for adding function arguments to the attribute
void	add_args(t_attribute *attribute, void **args)
{
	int		i;
	size_t	size;
	size_t	current_size;
	size_t	sizes[3];

	sizes[0] = sizeof(int);
	sizes[1] = sizeof(char *);
	sizes[2] = sizeof(char);
	size = get_arg_size(args, sizes);
	i = 0;
	attribute->value.args = malloc(size);
	size = 0;
	i = 0;
	while (args[i])
	{
		current_size = sizes[i % 3];
		ft_class_memcpy((char *)attribute->value.args + size, args[i],
			current_size);
		size += current_size;
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 19:33:15 by btvildia          #+#    #+#             */
/*   Updated: 2024/05/28 22:52:47 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_class.h"

// for getting attributes from the class by name
void	*get_attribute(t_class *class, char *name)
{
	t_attribute	*attr;

	attr = class->attributes;
	while (attr != NULL)
	{
		if (ft_class_strncmp(attr->name, name, ft_class_strlen(name)) == 0)
			return (attr);
		attr = attr->next;
	}
	return (NULL);
}

// for getting int attributes from the class
int	get_int(t_class *class, char *name)
{
	t_attribute	*attr;

	attr = get_attribute(class, name);
	if (attr)
		return (attr->value.int_value);
	return (0);
}

// for getting string attributes from the class
char	*get_string(t_class *class, char *name)
{
	t_attribute	*attr;

	attr = get_attribute(class, name);
	if (attr)
		return (attr->value.string_value);
	return (NULL);
}

// for getting string array attributes from the class
char	**get_string_arr(t_class *class, char *name)
{
	t_attribute	*attr;

	attr = get_attribute(class, name);
	if (attr)
		return (attr->value.string_arr_value);
	return (NULL);
}

// for getting function attributes from the class
void	call_func(t_class *class, char *name)
{
	t_attribute	*tmp;

	tmp = class->attributes;
	while (tmp)
	{
		if (ft_class_strncmp(tmp->name, name, ft_class_strlen(name)) == 0)
		{
			if (tmp->value.function_value)
			{
				tmp->value.function_value(tmp->value.args);
				free(tmp->value.args);
				return ;
			}
		}
		tmp = tmp->next;
	}
}

void	*attr(t_class *class, char *name)
{
	char	*s;
	char	**arr;
	void	*ret;
	int		i;

	s = get_string(class, name);
	i = get_int(class, name);
	arr = get_string_arr(class, name);
	if (s)
		ret = &s;
	else if (i)
		ret = &i;
	else if (arr)
		ret = arr;
	else
	{
		call_func(class, name);
		ret = NULL;
	}
	return (ret);
}

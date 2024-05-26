/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_class.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:12:31 by btvildia          #+#    #+#             */
/*   Updated: 2024/05/26 14:05:59 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct s_class		t_class;

typedef struct s_func_node
{
	void					(*func)(void);
	struct s_func_node		*next;
}							t_func_node;

typedef struct s_string_node
{
	char					*str;
	struct s_string_node	*next;
}							t_string_node;

// ft_string
t_string_node				*create_node(char *str);
void						free_strings(t_string_node *head);
void						add_string(t_string_node **head, char *str);

// ft_func_list
t_func_node					*create_func_node(void (*func)(void));
void						free_functions(t_func_node *head);
void						add_function(t_func_node **head,
								void (*func)(void));

// ft_this
void						this_add_string(t_class *self, char *str);
void						this_add_function(t_class *self,
								void (*func)(void));

typedef enum
{
	TYPE_INT,
	TYPE_STRING,
	TYPE_FUNCTION
}							t_value_type;

typedef struct s_value
{
	t_value_type			type;
	int						int_value;
	char					*string_value;
	void					(*function_value)(void *);
}							t_value;

typedef struct
{
	char					*name;
	t_value_type			type;
	t_value					value;
}							t_attribute;

typedef struct s_class
{
	t_attribute				*attributes;
	size_t					size;
	t_string_node			*str;
	t_func_node				*func;
	struct s_class			*this;
}							t_class;

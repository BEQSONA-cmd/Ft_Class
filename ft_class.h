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

typedef struct s_class	t_class;

typedef enum
{
	INT,
	STR,
	FUNC
}						t_value_type;

typedef struct s_value
{
	int					int_value;
	char				*string_value;
	void				(*function_value)(void);
}						t_value;

typedef struct s_attribute
{
	char				*name;
	t_value_type		type;
	t_value				value;
	struct s_attribute	*next;
}						t_attribute;

typedef struct s_class
{
	t_attribute			*attributes;
	size_t				size;
	void (*attribute)(struct s_class *, char *, t_value_type, void *);
	void *(*get_attribute)(struct s_class *, char *);
}						t_class;

void add_attribute(t_class *class, char *name, t_value_type type, void *value);
void *get_attribute(t_class *class, char *name);
void call_function(t_class *class, char *name);
char *get_string(t_class *class, char *name);
int get_int(t_class *class, char *name);
void destroy_class(t_class *class);
t_class *class(void);

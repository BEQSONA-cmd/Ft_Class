/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:34:50 by btvildia          #+#    #+#             */
/*   Updated: 2024/05/27 20:54:03 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_class.h"

void	say_something(void *args)
{
	int		times;
	char	*str;
	char	c;

	times = *((int *)args);
	str = *((char **)(args + sizeof(int)));
	c = *((char *)(args + sizeof(int) + sizeof(char *)));
	for (int i = 0; i < times; i++)
	{
		printf("%s %c\n", str, c);
	}
}

void	say_hi_times(void *args)
{
	int		times;
	char	*str;

	times = 3;
	str = *((char **)(args));
	for (int i = 0; i < times; i++)
	{
		printf("%s\n", str);
	}
}

int	main(void)
{
	t_class	*new_class;
	void	**args1;
	void	**args2;

	args1 = create_args(3, 2, "Hello", '!');
	args2 = create_args(2, "Hi");
	new_class = class();
	new_class->attribute(new_class, "say_something", FUNC, &say_something);
	add_args(new_class->get_attribute(new_class, "say_something"), args1);
	call_func(new_class, "say_something");
	new_class->attribute(new_class, "say_hi_times", FUNC, &say_hi_times);
	add_args(new_class->get_attribute(new_class, "say_hi_times"), args2);
	call_func(new_class, "say_hi_times");
	destroy_class(new_class);
	free(args1);
	free(args2);
	return (0);
}

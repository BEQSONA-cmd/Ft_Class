/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 21:53:28 by btvildia          #+#    #+#             */
/*   Updated: 2024/05/27 22:01:08 by btvildia         ###   ########.fr       */
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
	t_class	*cat;
	int		i;
	i = 3;

	cat = class();
	i = 0;
	cat->attribute(cat, "say_something", FUNC, &say_something);	
	cat->attribute(cat, "name", STR, "Kitty");
	cat->attribute(cat, "age", INT, &(int){3});
	cat->attribute(cat, "nicknames", STR_ARR, (char *[]){"kitty", "kitten",
		"kittykat", NULL});
	void *args[3] = {&(int){3}, (char *[]){"Hello", NULL}, &(char){'!'}};
	add_args(get_attribute(cat, "say_something"), args);
	while (get_string_arr(cat, "nicknames")[i])
	{
		printf("Nickname: %s\n", get_string_arr(cat, "nicknames")[i]);
		i++;
	}
	call_func(cat, "say_something");
	destroy_class(cat);
	return (0);
}

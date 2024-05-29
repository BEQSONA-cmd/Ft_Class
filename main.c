/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 21:53:28 by btvildia          #+#    #+#             */
/*   Updated: 2024/05/29 12:01:05 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_class.h"

void	say_hi(void **args)
{
	char	*name;

	name = (char *)args[0];
	printf("Hello, %s!\n", name);
}

int	main(void)
{
	t_class	*cat;
	t_arg	args[2];

	args[0].arg = "Zoro";
	args[0].type = sizeof(char *);
	args[1].arg = NULL;
	args[1].type = 0;
	cat = class();
	add(cat, "say_hi", FUNC, say_hi);
	add(cat, "name", STR, "Zoro");
	add_func_args(cat, "say_hi", args);
	printf("Name: %s\n", get_str(cat, "name"));
	call_func(cat, "say_hi");
	destroy_class(cat);
	return (0);
}

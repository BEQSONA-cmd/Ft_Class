/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_class.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:16:45 by btvildia          #+#    #+#             */
/*   Updated: 2024/05/26 20:56:18 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_class.h"

void	bark_or_meow(int is_dog)
{
	if (is_dog)
		printf("Bark!\n");
	else
		printf("Meow!\n");
}

void	say_hello(void)
{
	printf("Hello!\n");
}

int	main(void)
{
	t_class	*dog;

	dog = class();
	dog->attribute(dog, "name", STR, "Doggo");
	dog->attribute(dog, "age", INT, &(int){5});
	dog->attribute(dog, "bark", FUNC_WITH_ARGS, bark_or_meow, 1);
	dog->attribute(dog, "say_hello", FUNC, say_hello);
	
	printf("Name: %s\n", get_string(dog, "name"));
	printf("Age: %d\n", get_int(dog, "age"));
	printf("Bark: ");
	call_function(dog, "bark");
	printf("Say Hello: ");
	call_function(dog, "say_hello");
	destroy_class(dog);

	t_class	*cat;
	
	cat = class();
	cat->attribute(cat, "name", STR, "Kitty");
	cat->attribute(cat, "age", INT, &(int){3});
	cat->attribute(cat, "bark", FUNC_WITH_ARGS, bark_or_meow, 0);
	cat->attribute(cat, "say_hello", FUNC, say_hello);
	
	printf("Name: %s\n", get_string(cat, "name"));
	printf("Age: %d\n", get_int(cat, "age"));
	printf("Bark: ");
	call_function(cat, "bark");
	printf("Say Hello: ");
	call_function(cat, "say_hello");
	destroy_class(cat);	
	return (0);
}

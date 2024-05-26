/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_class.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:16:45 by btvildia          #+#    #+#             */
/*   Updated: 2024/05/26 20:26:17 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_class.h"

void	bark(void)
{
	printf("Woof!\n");
}

void	say_hello(void)
{
	printf("Hello!\n");
}

int	main(void)
{
	t_class	*dog;

	dog = class();
	dog->add_attribute(dog, "name", STR, "Doggo");
	dog->add_attribute(dog, "age", INT, &(int){5});
	dog->add_attribute(dog, "bark", FUNC, bark);
	dog->add_attribute(dog, "say_hello", FUNC, say_hello);
	printf("Name: %s\n", get_string(dog, "name"));
	printf("Age: %d\n", get_int(dog, "age"));
	printf("Bark: ");
	call_function(dog, "bark");
	printf("Say Hello: ");
	call_function(dog, "say_hello");
	destroy_class(dog);
	return (0);
}

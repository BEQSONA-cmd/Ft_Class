/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 21:53:28 by btvildia          #+#    #+#             */
/*   Updated: 2024/05/28 22:55:35 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_class.h"

int	main(void)
{
	t_class	*cat;

	cat = class();
	add(cat, 1, "the_name", "Cat");
	add(cat, 3, "the_age", &(int){5});
	printf("%s\n", *(char **)cat->attr(cat, "the_name"));
	printf("%d\n", *(int *)cat->attr(cat, "the_age"));
	destroy_class(cat);
	return (0);
}

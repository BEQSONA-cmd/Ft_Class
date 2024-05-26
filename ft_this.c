/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_this.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 13:52:42 by btvildia          #+#    #+#             */
/*   Updated: 2024/05/26 14:08:27 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_class.h"

void	this_add_string(t_class *self, char *str)
{
	add_string(&self->str, str);
}

void	this_add_function(t_class *self, void (*func)(void))
{
	add_function(&self->func, func);
}

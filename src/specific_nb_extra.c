/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specific_nb_extra.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:29:30 by teojimen          #+#    #+#             */
/*   Updated: 2024/01/28 12:29:30 by teojimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	supp_size3_1(t_node *c, int f)
{
	if (c->index < c->next->next->index && c->index > c->next->index && \
	c->next->index < c->next->next->index && c->next->index < c->index && \
	c->next->next->index > c->next->index && c->next->next->index > c->index && \
	f == 1)
		return (1);
	else if (c->index > c->next->next->index && c->index > c->next->index && \
	c->next->index > c->next->next->index && c->next->index < c->index && \
	c->next->next->index < c->next->index && c->next->next->index < c->index \
	&& f == 2)
		return (2);
	else if (c->index > c->next->next->index && c->index > c->next->index && \
	c->next->index < c->index && c->next->index < c->next->next->index && \
	c->index > c->next->next->index && c->next->index < c->next->next->index \
	&& f == 3)
		return (3);
	else if (c->index < c->next->next->index && c->index < c->next->index && \
	c->next->index > c->index && c->next->index > c->next->next->index && \
	c->next->next->index > c->index && c->next->next->index < c->next->index && \
	f == 4)
		return (4);
	else if (f == 5)
		return (5);
	return (0);
}

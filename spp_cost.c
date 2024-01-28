/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spp_cost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 17:12:20 by teojimen          #+#    #+#             */
/*   Updated: 2024/01/28 17:12:20 by teojimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_rango_min(int *tab, int tab_pos)
{
	int	all;

	all = 0;
	if (tab_pos != 0)
	{
		while (tab_pos > 0)
			all += tab[--tab_pos];
	}
	return (all);
}

int	up_in_one_index(t_node **head_a, int index)
{
	t_node	*current;
	int		count;

	current = *head_a;
	count = 0;
	while (current)
	{
		if (current->index == index)
			return (count);
		current = current->next;
		count++;
	}
	return (0);
}

int	down_in_one_index(t_node **head_a, int index)
{
	t_node	*current;
	int		count;

	current = *head_a;
	count = 0;
	while (current)
	{
		if (current->index == index)
		{
			while (current)
			{
				count++;
				current = current->next;
			}
			return (count);
		}
		current = current->next;
	}
	return (0);
}

int	up_to_push(t_cost **costs)
{
	t_cost	*current_cost;
	int		up;

	current_cost = *costs;
	up = current_cost->cost_up;
	while (current_cost)
	{
		if (current_cost->cost_up < up)
			up = current_cost->cost_up;
		current_cost = current_cost->next;
	}
	current_cost = *costs;
	while (current_cost)
	{
		if (current_cost->cost_up == up)
			return (up);
		current_cost = current_cost->next;
	}
	return (0);
}

int	down_to_push(t_cost **costs)
{
	int		down;
	t_cost	*current_cost;

	current_cost = *costs;
	down = current_cost->cost_down;
	while (current_cost)
	{
		if (current_cost->cost_down < down)
			down = current_cost->cost_down;
		current_cost = current_cost->next;
	}
	current_cost = *costs;
	while (current_cost)
	{
		if (current_cost->cost_down == down)
			return (down);
		current_cost = current_cost->next;
	}
	return (0);
}

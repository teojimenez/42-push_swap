/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 17:10:24 by teojimen          #+#    #+#             */
/*   Updated: 2024/01/28 17:10:24 by teojimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	content_in_costs(int *tab, int tab_pos, t_cost **costs, t_node**head_a)
{
	t_node	*cur_a;
	t_cost	*new;
	int		r_min;
	int		up;
	int		down;

	cur_a = *head_a;
	r_min = get_rango_min(tab, tab_pos);
	while (cur_a)
	{
		if (cur_a->index >= r_min && cur_a->index <= (r_min + tab[tab_pos]))
		{
			up = up_in_one_index(head_a, cur_a->index);
			down = down_in_one_index(head_a, cur_a->index);
			new = ft_newcost(cur_a->index, up, down);
			if (!new)
			{
				free_stack_cost(costs);
				return (-1);
			}
			ft_lstadd_back_cost(costs, new);
		}
		cur_a = cur_a->next;
	}
	return (0);
}

void	push_less_cost(t_cost **costs, t_node **head_a, t_node **head_b)
{
	int	up;
	int	down;

	up = up_to_push(costs);
	down = down_to_push(costs);
	if (ft_lstsize(*head_a) > 1)
	{
		if (up >= down)
		{
			while (down-- > 0)
				rra_rrb(head_a, 1);
		}
		else
		{
			while (up-- > 0)
				ra_rb(head_a, 1);
		}
	}
	pa_pb(head_a, head_b, 0);
}

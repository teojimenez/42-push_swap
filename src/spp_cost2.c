/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spp_cost2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 17:31:08 by teojimen          #+#    #+#             */
/*   Updated: 2024/01/28 17:31:08 by teojimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_single_cheaper(t_node **head_a, t_node **head_b, int up, int down)
{
	if (ft_lstsize(*head_b) > 1)
	{
		if (up >= down)
		{
			while (down-- > 0)
				rra_rrb(head_b, 0);
		}
		else
		{
			while (up-- > 0)
				ra_rb(head_b, 0);
		}
	}
	pa_pb(head_a, head_b, 1);
}

void	search_b_number(t_node **head_a, t_node **head_b, int nb_index)
{
	t_node	*current_b;
	int		count_up;
	int		count_down;

	count_down = 0;
	count_up = 0;
	current_b = *head_b;
	while (current_b)
	{
		if (current_b->index == nb_index)
		{
			while (current_b)
			{
				count_down++;
				current_b = current_b->next;
			}
			break ;
		}
		count_up++;
		current_b = current_b->next;
	}
	push_single_cheaper(head_a, head_b, count_up, count_down);
}

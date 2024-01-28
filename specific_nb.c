/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specific_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:55:46 by teojimen          #+#    #+#             */
/*   Updated: 2024/01/28 12:55:46 by teojimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	size3_index(t_node **head_a)
{
	t_node	*c;

	c = *head_a;
	if (is_sorted(head_a) == 0)
		return ;
	if (c->index == 2 && c->next->index == 1 && c->next->next->index == 3)
		sa_sb(head_a, 1);
	else if (c->index == 3 && c->next->index == 2 && c->next->next->index == 1)
	{
		sa_sb(head_a, 1);
		rra_rrb(head_a, 1);
	}
	else if (c->index == 3 && c->next->index == 1 && c->next->next->index == 2)
		ra_rb(head_a, 1);
	else if (c->index == 1 && c->next->index == 3 && c->next->next->index == 2)
	{
		sa_sb(head_a, 1);
		ra_rb(head_a, 1);
	}
	else if (c->index == 2 && c->next->index == 3 && c->next->next->index == 1)
		rra_rrb(head_a, 1);
}

void	size3(t_node **head_a)
{
	t_node	*current;

	current = *head_a;
	if (is_sorted(head_a) == 0)
		return ;
	if (supp_size3_1(current, 1) == 1)
		sa_sb(head_a, 1);
	else if (supp_size3_1(current, 2) == 2)
	{
		sa_sb(head_a, 1);
		rra_rrb(head_a, 1);
	}
	else if (supp_size3_1(current, 3) == 3)
		ra_rb(head_a, 1);
	else if (supp_size3_1(current, 4) == 4)
	{
		sa_sb(head_a, 1);
		ra_rb(head_a, 1);
	}
	else if (supp_size3_1(current, 5) == 5)
		rra_rrb(head_a, 1);
}

void	size4(t_node **head_a)
{
	t_node	**head_b;

	head_b = (t_node **)malloc(sizeof(t_node *));
	if (!head_b)
		return ;
	(*head_b) = NULL;
	pa_pb(head_a, head_b, 0);
	size3(head_a);
	if ((*head_b)->index < (*head_a)->index)
		pa_pb(head_a, head_b, 1);
	else if ((*head_b)->index < (*head_a)->next->index)
		pa_and_sa(head_a, head_b);
	else if ((*head_b)->index < (*head_a)->next->next->index)
	{
		ra_rb(head_a, 1);
		pa_and_sa(head_a, head_b);
		rra_rrb(head_a, 1);
	}
	else
		pa_and_ra(head_a, head_b);
	free_stack(head_b);
}

void	size5(t_node **head_a)
{
	t_node	**head_b;

	head_b = (t_node **)malloc(sizeof(t_node *));
	if (!head_b)
		return ;
	(*head_b) = NULL;
	pa_pb(head_a, head_b, 0);
	size4(head_a);
	if ((*head_b)->index < (*head_a)->index)
		pa_pb(head_a, head_b, 1);
	else if ((*head_b)->index < (*head_a)->next->index)
		pa_and_sa(head_a, head_b);
	else if ((*head_b)->index < (*head_a)->next->next->index)
	{
		ra_rb(head_a, 1);
		pa_and_sa(head_a, head_b);
		rra_rrb(head_a, 1);
	}
	else if ((*head_b)->index < (*head_a)->next->next->next->index)
		rra_pa_ra_ra(head_a, head_b);
	else
		pa_and_ra(head_a, head_b);
	free_stack(head_b);
}

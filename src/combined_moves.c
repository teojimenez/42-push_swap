/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combined_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:26:53 by teojimen          #+#    #+#             */
/*   Updated: 2024/01/28 12:26:53 by teojimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa_and_ra(t_node **head_a, t_node **head_b)
{
	pa_pb(head_a, head_b, 1);
	ra_rb(head_a, 1);
}

void	pa_and_sa(t_node **head_a, t_node **head_b)
{
	pa_pb(head_a, head_b, 1);
	sa_sb(head_a, 1);
}

void	rra_pa_ra_ra(t_node **head_a, t_node **head_b)
{
	rra_rrb(head_a, 1);
	pa_pb(head_a, head_b, 1);
	ra_rb(head_a, 1);
	ra_rb(head_a, 1);
}

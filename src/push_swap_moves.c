/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:07:29 by teojimen          #+#    #+#             */
/*   Updated: 2024/01/10 11:07:46 by teojimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*swap*/
void	sa_sb(t_node **head, int flag)
{
	first_two_change(head);
	if (flag == 1)
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}

void	ss(t_node **head_a, t_node **head_b)
{
	first_two_change(head_a);
	first_two_change(head_b);
	write(1, "ss\n", 3);
}

/*push first*/
void	pa_pb(t_node **head_a, t_node **head_b, int flag)
{
	if (flag == 1)
	{
		first_push(head_b, head_a);
		write(1, "pa\n", 3);
	}
	else
	{
		first_push(head_a, head_b);
		write(1, "pb\n", 3);
	}
}

/*rotate up*/
void	ra_rb(t_node **head, int flag)
{
	rotate_up(head);
	if (flag == 1)
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}

void	rr(t_node **head_a, t_node **head_b)
{
	rotate_up(head_a);
	rotate_up(head_b);
	write(1, "rr\n", 3);
}

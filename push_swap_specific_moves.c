/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_specific_moves.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:07:57 by teojimen          #+#    #+#             */
/*   Updated: 2024/01/10 11:07:57 by teojimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void size3(t_node **head_a)
{
    t_node *current;

    current = *head_a;
    if(is_sorted(head_a) == 0)
		return ;
    //case 2 1 3
    // if(is_sorted(head_a) == -1)
    //     return ;

    if((current->index == 2 && current->next->index == 1 && current->next->next->index == 3) || (\
    current->index < current->next->next->index && current->index > current->next->index  && \
    current->next->index < current->next->next->index && current->next->index < current->index && \
    current->next->next->index > current->next->index && current->next->next->index > current->index)) //done
        sa_sb(head_a, 1);
    //case 3 2 1
    else if((current->index == 3 && current->next->index == 2 && current->next->next->index == 1) || (\
    current->index > current->next->next->index && current->index > current->next->index && \
    current->next->index > current->next->next->index && current->next->index < current->index && \
    current->next->next->index < current->next->index && current->next->next->index < current->index)) //done
    {
        sa_sb(head_a, 1);
        rra_rrb(head_a, 1);
    }
    //case 3 1 2
    else if((current->index == 3 && current->next->index == 1 && current->next->next->index == 2) || (\
    current->index > current->next->next->index && current->index > current->next->index  && \
    current->next->index < current->index && current->next->index < current->next->next->index && \
    current->index > current->next->next->index && current->next->index < current->next->next->index)) //done
        ra_rb(head_a, 1);
    //case 1 3 2
    else if((current->index == 1 && current->next->index == 3 && current->next->next->index == 2) || (\
    current->index < current->next->next->index && current->index < current->next->index && \
    current->next->index > current->index && current->next->index > current->next->next->index && \
    current->next->next->index > current->index && current->next->next->index < current->next->index))//done
    {
        sa_sb(head_a, 1);
        ra_rb(head_a, 1);
    }
    //case 2 3 1
    else if((current->index == 2 && current->next->index == 3 && current->next->next->index == 1) || (\
    current->index > current->next->next->index && current->index < current->next->index && \
    current->next->index > current->index && current->next->index > current->next->next->index && \
    current->next->next->index < current->next->index && current->next->next->index < current->index))
        rra_rrb(head_a, 1);
}

#include <stdio.h>

void size4(t_node **head_a)
{
    t_node **head_b;
    head_b = (t_node **)malloc(sizeof(t_node *));
    if (!head_b)
        return ; //que pete
    (*head_b) = NULL;


    pa_pb(head_a, head_b, 0);
    size3(head_a);
    if((*head_b)->index < (*head_a)->index)
        pa_pb(head_a, head_b, 1);
    else if((*head_b)->index < (*head_a)->next->index)
    {
        pa_pb(head_a, head_b, 1);
        sa_sb(head_a, 1);
    }
    else if((*head_b)->index < (*head_a)->next->next->index)
    {
        ra_rb(head_a, 1);
        pa_pb(head_a, head_b, 1);
        sa_sb(head_a, 1);
        rra_rrb(head_a, 1);
    }
    else
    {
        // ra_rb(head_a, 1);
        pa_pb(head_a, head_b, 1);
        // sa_sb(head_a, 1);
        ra_rb(head_a, 1);
    }
    free_stack(head_b);
}
void size5(t_node **head_a)
{
    t_node **head_b;
    head_b = (t_node **)malloc(sizeof(t_node *));
    if (!head_b)
        return ; //que pete
    (*head_b) = NULL;


    pa_pb(head_a, head_b, 0);
    size4(head_a);
    if((*head_b)->index < (*head_a)->index)
        pa_pb(head_a, head_b, 1);
    else if((*head_b)->index < (*head_a)->next->index)
    {
        pa_pb(head_a, head_b, 1);
        sa_sb(head_a, 1);
    }
    else if((*head_b)->index < (*head_a)->next->next->index)
    {
        ra_rb(head_a, 1);
        pa_pb(head_a, head_b, 1);
        sa_sb(head_a, 1);
        rra_rrb(head_a, 1);
    }
    else if((*head_b)->index < (*head_a)->next->next->next->index)
    {
        rra_rrb(head_a, 1);
        pa_pb(head_a, head_b, 1);
        // sa_sb(head_a, 1);
        ra_rb(head_a, 1);
        ra_rb(head_a, 1);
    }
    else
    {
        pa_pb(head_a, head_b, 1);
        ra_rb(head_a, 1);
    }
    free_stack(head_b);
}

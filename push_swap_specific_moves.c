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
    //case 2 1 3
    if(current->index > current->next->index && current->index < current->next->next->index && \
        current->next->index < current->index && current->next->index < current->next->next->index)
        sa_sb(head_a, 1);
    //case 3 2 1
    else if(current->index > current->next->index && \
    current->index > current->next->next->index && current->next->index < current->index \
    && current->next->next->index < current->next->content && current->next->next->index < current->content)
    {
        sa_sb(head_a, 1);
        rra_rrb(head_a, 1);
    }
    //case 3 1 2
    else if(current->index > current->next->index && current->index > current->next->next->index \
    && current->next->next->index > current->next->index)
        ra_rb(head_a, 1);

    //case 1 3 2
    else if(current->next->index > current->index && current->next->index > current->next->next->index \
    && current->index < current->next->next->index)
    {
        sa_sb(head_a, 1);
        ra_rb(head_a, 1);
    }
    else
        rra_rrb(head_a, 1);

}       
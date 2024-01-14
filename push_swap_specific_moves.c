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
    if(current->content > current->next->content && current->content < current->next->next->content && \
        current->next->content < current->content && current->next->content < current->next->next->content)
        sa_sb(head_a, 1);
    //case 3 2 1
    else if(current->content > current->next->content && \
    current->content > current->next->next->content)
    {
        sa_sb(head_a, 1);
        rra_rrb(head_a, 1);
    }
}
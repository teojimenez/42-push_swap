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

void size5(t_node **head_a)
{
    t_node *current_a;
    t_node *current_b;
    t_node **head_b;
    head_b = (t_node **)malloc(sizeof(t_node *));
    if (!head_b)
        return ; //que pete
    
    pa_pb(head_a, head_b , 0);
    pa_pb(head_a, head_b , 0);
    size3(head_a);
    current_a = *head_a;
    current_b = *head_b;

    int min;
    int max;
    if(index_sorted(head_a) != -1)
    {
        min = current_a->index;   
        max = current_a->next->next->index;
        if(min == 1)
        {
            if(current_b->index != 4)
                sa_sb(head_b, 0);
            pa_pb(head_a, head_b, 1);
            ra_rb(head_a, 1);
            pa_pb(head_a, head_b, 1);
            ra_rb(head_a, 1);
        }
        else if(min == 2)
        {
            if(current_b->index != 1)
                sa_sb(head_b, 0);
            pa_pb(head_a, head_b, 1);
            pa_pb(head_a, head_b, 1);
            ra_rb(head_a, 1);

        }
        else if(min == 3)
        {
            if(current_b->index == 1)
                sa_sb(head_b, 0);
            pa_pb(head_a, head_b, 1);
            pa_pb(head_a, head_b, 1);
        }
    }
    else
    {
        min = current_a->index;   
        max = current_a->next->next->index;
        int op = max - min;
        if(op == 3)
        {
            if(current_a->next->index == op) //3
            {
                if(current_b->index == 4)
                    sa_sb(head_b, 0);
                pa_pb(head_a, head_b, 1);
                rra_rrb(head_a, 1);
                pa_pb(head_a, head_b, 1);
                ra_rb(head_a, 1);
                ra_rb(head_a, 1);
            }
            else
            {
                if(current_b->index == 1)//aqui
                    sa_sb(head_b, 0);
                pa_pb(head_a, head_b, 1);
                sa_sb(head_a, 1);
                pa_pb(head_a, head_b, 1);
            }
        }
        else if(op == 4)
        {
            if(current_a->next->index == op) //4
            {
                if(current_b->index == 2)
                    sa_sb(head_b, 0);
                pa_pb(head_a, head_b, 1);
                sa_sb(head_a, 1);
                pa_pb(head_a, head_b, 1);
                sa_sb(head_a, 1);
            }
            else
            {
                if(current_b->index == 2)
                    sa_sb(head_b, 0);
                rra_rrb(head_a, 1);
                pa_pb(head_a, head_b, 1);
                ra_rb(head_a, 1);
                ra_rb(head_a, 1);
                pa_pb(head_a, head_b, 1);
                sa_sb(head_a, 1);
            }
        }
    }
    free_stack(head_b);
}

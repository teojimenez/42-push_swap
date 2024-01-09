/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 00:39:54 by teojimene         #+#    #+#             */
/*   Updated: 2024/01/09 00:39:54 by teojimene        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*swap*/
void sa_sb(t_node **head, int flag)
{
    first_two_change(head);
    if(flag == 1)
        write(1, "sa", 2);
    else
        write(1, "sb", 1);
}

void    ss(t_node **head_a, t_node **head_b)
{
    first_two_change(head_a);
    first_two_change(head_b);
    write(1, "ss", 2);
}

/*push first*/
void    pa_pb(t_node **head_a, t_node **head_b, int flag)
{
    if(flag == 1)
    {
        first_push(head_a, head_b);
        write(1, "pa", 2);
    }
    else
    {
        first_push(head_b, head_a);
        write(1, "pb", 2);
    }
}

/*rotate up*/
void    ra_rb(t_node **head, int flag)
{
    rotate_up(head);
    if (flag == 1)
        write(1, "ra", 2);
    else
        write(1, "rb", 2);
}

void    rr(t_node **head_a, t_node **head_b)
{
    rotate_up(head_a);
    rotate_up(head_b);
    write(1, "rr", 1);
}

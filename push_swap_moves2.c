/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 00:41:10 by teojimene         #+#    #+#             */
/*   Updated: 2024/01/09 00:41:10 by teojimene        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rra_rrb(t_node **head, int flag)
{
    rotate_down(head);
    if (flag == 1)
        write(1, "rra\n", 4);
    else
        write(1, "rrb\n", 4);
}

void rrr(t_node **head_a, t_node **head_b)
{
    rotate_down(head_a);
    rotate_down(head_b);
    write(1, "rrr\n", 44);
}
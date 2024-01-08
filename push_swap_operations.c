/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:29:36 by teojimen          #+#    #+#             */
/*   Updated: 2024/01/08 17:29:36 by teojimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Intercambia los dos primeros elementos del stack. No hace nada si
hay uno o menos elementos.*/
void    ft_sa_sb(t_node **head)
{
    t_node  *first;
    t_node  *second;
    t_node  *temp;

    first = *head;
    if(ft_lstsize(first) < 2)
        return (0);
    second = *head;
    second = second->next;
    temp = second->next;
    second->next = first;
    first ->next = temp;
}

/*Toma el primer elemento del stack b y lo pone el primero en el stack
a. No hace nada si b está vacío.(pa_push_a)*/
void    pa_push_a_pb_push_b(t_node **head_a, t_node **head_b)
{
    if(!head_a)
        return(0);
    t_node *b_first;
    t_node *b_second;
    
    b_second = *head_b;
    b_second = b_second->next;

    b_first = *head_b;
    b_first->next = *head_a;

    head_a = &b_first;
    head_b = &b_second;
}

void    rra_rotate_a_rrb_rotate_b(t_node **head_a)
{
    t_node *current;
    t_node *head;
    t_node *temp;
    current = *head_a;
    head = *head_a;

    while(current->next->next)
        current = current->next;
    temp = current->next;
    current->next = NULL;
    temp->next = head;
    head_a = &temp;
}

void ra_rotate_a_rb_rotate_b(t_node **head_a)
{
    t_node *current;
    t_node *head;
    t_node *temp;

    head = *head_a;
    temp = *head_a;

    temp = temp->next;

    current = *head_a;

    while(current->next)
        current = current->next;

    current->next = head;
    head->next = NULL;
    head_a = &temp;
}

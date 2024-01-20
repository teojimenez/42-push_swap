/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:29:36 by teojimen          #+#    #+#             */
/*   Updated: 2024/01/09 00:39:33 by teojimene        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Intercambia los dos primeros elementos del stack. No hace nada si
hay uno o menos elementos.*/
void    first_two_change(t_node **head)
{
    t_node  *first;
    t_node  *second;
    t_node  *temp;

    first = *head;
    if(ft_lstsize(first) < 2)
        return ;
    //set posicions
    second = *head;
    second = second->next;
    //next
    temp = second->next;
    second->next = first;
    first->next = temp;
    //set prev
    second->prev = NULL;
    first->prev = *head;
}

/*Toma el primer elemento del stack 1 y lo pone el primero en el stack
2. No hace nada si 2 está vacío.(pa_push_a)*/
// void    first_push(t_node **head_a, t_node **head_b)
// {
//     if(!head_a)
//         return ;
//     t_node *b_first;
//     t_node *b_second;
    
//     b_second = *head_b;
//     b_second = b_second->next;

//     b_first = *head_b;
//     b_first->next = *head_a;

//     head_a = &b_first;
//     head_b = &b_second;
// }
void    first_push(t_node **head_a, t_node **head_b)
{
    if(!head_a)
        return ;
    t_node *a_first;
    t_node *a_second;
    t_node *b_first;

    a_first = *head_a;
    b_first = *head_b;
    a_second = a_first->next;

    a_first->next = b_first;
    *head_a = a_second; //change
    *head_b = a_first; //change
    ft_put_prev(head_a);
    ft_put_prev(head_b);
}

/*Desplaza hacia abajo todos los elementos del stack 1 una
posición, de forma que el último elemento se convierte en el primero*/
void    rotate_down(t_node **head_a)
{
    t_node *current;
    t_node *head;
    t_node *temp;

    current = *head_a;
    head = *head_a;

    while(current->next->next) //
        current = current->next;
    temp = current->next;
    current->next = NULL;
    temp->next = head;
    *head_a = temp; //change

    ft_put_prev(head_a);
}

/*Desplaza hacia arriba todos los elementos del stack 1 una posición,
de forma que el primer elemento se convierte en el último.*/
void rotate_up(t_node **head_a)
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
    *head_a = temp; //change
    ft_put_prev(head_a);
}

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
void	first_two_change(t_node **head)
{
	t_node	*first;
	t_node	*second;

	if (ft_lstsize(*head) < 2)
		return ;
	first = *head;
	second = (*head)->next;
	first->next = second->next;
	second->next = first;
	*head = second;
	ft_put_prev(head);
}

void	first_push(t_node **head_a, t_node **head_b)
{
	t_node	*a_first;
	t_node	*a_second;
	t_node	*b_first;

	if (!head_a)
		return ;
	a_first = *head_a;
	b_first = *head_b;
	a_second = a_first->next;
	a_first->next = b_first;
	*head_a = a_second;
	*head_b = a_first;
	ft_put_prev(head_a);
	ft_put_prev(head_b);
}

/*Desplaza hacia abajo todos los elementos del stack 1 una
posición, de forma que el último elemento se convierte en el primero*/
void	rotate_down(t_node **head_a)
{
	t_node	*current;
	t_node	*head;
	t_node	*temp;

	current = *head_a;
	head = *head_a;
	while (current->next->next)
		current = current->next;
	temp = current->next;
	current->next = NULL;
	temp->next = head;
	*head_a = temp;
	ft_put_prev(head_a);
}

/*Desplaza hacia arriba todos los elementos del stack 1 una posición,
de forma que el primer elemento se convierte en el último.*/
void	rotate_up(t_node **head_a)
{
	t_node	*current;
	t_node	*head;
	t_node	*temp;

	head = *head_a;
	temp = *head_a;
	temp = temp->next;
	current = *head_a;
	while (current->next)
		current = current->next;
	current->next = head;
	head->next = NULL;
	*head_a = temp;
	ft_put_prev(head_a);
}

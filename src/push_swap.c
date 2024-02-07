/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 09:38:49 by teojimen          #+#    #+#             */
/*   Updated: 2023/12/12 09:38:49 by teojimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// #include <stdio.h>

// void print_stack(t_node **stack) 
// {
// 	t_node *temp; 
// 	temp = *stack; 
// 	while (temp) 
// 	{ 
// 		printf("value -> %d\n", temp->content); 
// 		temp = temp->next;
// 	} 
// }

int	main(int argc, char **argv)
{
	t_node	**stock_a;

	stock_a = (t_node **)malloc(sizeof(t_node *));
	if (!stock_a)
		return (-1);
	(*stock_a) = NULL;
	if (convert_nb_index(argc, argv, stock_a) == -1)
		return (free_stack(stock_a), 0);
	if (is_sorted(stock_a) == -1)
		sort_menu(stock_a);
	free_stack(stock_a);
	return (0);
}

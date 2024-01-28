/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 11:50:17 by teojimen          #+#    #+#             */
/*   Updated: 2024/01/14 11:50:17 by teojimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	every_chunk(int *tab, int tab_pos, t_node **head_a, t_node **head_b)
{
	t_cost	**costs;
	int		rango;
	int		count;

	costs = (t_cost **)malloc(sizeof(t_cost *));
	if (!costs)
		return (-1);
	(*costs) = NULL;
	rango = tab[tab_pos];
	count = -1;
	while (++count != rango)
	{
		content_in_costs(tab, tab_pos, costs, head_a);
		push_less_cost(costs, head_a, head_b);
		ft_lstclear_cost(costs);
	}
	free_stack_cost(costs);
	return (0);
}

void	sort_every_chunk(int *tab, t_node **head_a, t_node **head_b)
{
	int	i;

	i = -1;
	while (tab[++i])
	{
		if (every_chunk(tab, i, head_a, head_b) == -1)
			return ;
	}
}

void	sort_every_thing(t_node **head_a, t_node **head_b)
{
	int	size;

	size = ft_lstsize(*head_b);
	while (size > 0)
	{
		search_b_number(head_a, head_b, size);
		size--;
	}
}

void	algorithm(t_node **head_a)
{
	int		*tab;
	t_node	**stock_b;
	int		nb;

	nb = ft_lstsize(*head_a);
	stock_b = malloc(sizeof(t_node *));
	if (!stock_b)
		return ;
	(*stock_b) = NULL;
	tab = ft_fractions(nb);
	sort_every_chunk(tab, head_a, stock_b);
	sort_every_thing(head_a, stock_b);
	free(stock_b);
	stock_b = NULL;
	free(tab);
}

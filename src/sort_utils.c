/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 08:29:26 by teojimen          #+#    #+#             */
/*   Updated: 2024/01/28 08:29:26 by teojimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_node **head_a)
{
	t_node	*current;

	current = *head_a;
	if (ft_lstsize(*head_a) < 2)
		return (0);
	while (current->next)
	{
		if (current->content > current->next->content)
			return (-1);
		current = current->next;
	}
	return (0);
}

int	index_sorted(t_node **head_a)
{
	t_node	*current;

	current = *head_a;
	while (current->next)
	{
		if (current->index != current->next->index - 1)
			return (-1);
		current = current->next;
	}
	return (0);
}

void	sort_menu(t_node **head_a)
{
	int		size;
	t_node	*current;

	current = *head_a;
	size = ft_lstsize(current);
	if (size == 2)
		sa_sb(head_a, 1);
	else if (size == 3)
		size3_index(head_a);
	else if (size == 4)
		size4(head_a);
	else if (size == 5)
		size5(head_a);
	else
		algorithm(head_a);
}

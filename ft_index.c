/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 08:50:10 by teojimen          #+#    #+#             */
/*   Updated: 2024/01/28 08:50:10 by teojimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	supp_ft_index2(int **tab, int i, int size)
{
	int	step;
	int	temp;

	step = 0;
	while (step < size)
	{
		i = -1;
		while (++i < size - 1)
		{
			if ((*tab)[i] > (*tab)[i + 1])
			{
				temp = (*tab)[i];
				(*tab)[i] = (*tab)[i + 1];
				(*tab)[i + 1] = temp;
			}
		}
		step++;
	}
}

void	supp_ft_index(int i, int **tab, t_node **head_a, int size)
{
	int		step;
	t_node	*current;

	current = *head_a;
	step = 0;
	i = -1;
	while (++i < size)
	{
		(*tab)[i] = current->content;
		current = current->next;
	}
	(*tab)[i] = '\0';
}

void	supp_ft_index3(int i, int **tab, t_node **head_a, int size)
{
	t_node	*current;
	int		step;

	step = 0;
	current = *head_a;
	while (step < size && current)
	{
		i = -1;
		while (++i < size)
		{
			if (current->content == (*tab)[i])
			{
				current->index = i + 1;
				break ;
			}
		}
		current = current->next;
		step++;
	}
}

void	ft_index(t_node **head_a, int size)
{
	int	i;
	int	*tab;

	i = 0;
	tab = (int *)malloc((size + 1) * sizeof(int));
	if (!tab)
		return ;
	supp_ft_index(i, &tab, head_a, size);
	supp_ft_index2(&tab, i, size);
	supp_ft_index3(i, &tab, head_a, size);
	free(tab);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:14:23 by teojimen          #+#    #+#             */
/*   Updated: 2024/01/28 18:14:23 by teojimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_lstadd_back_cost(t_cost **lst, t_cost *new)
{
	t_cost	*p;

	if (*lst)
	{
		p = *lst;
		while (p->next)
			p = p->next;
		p->next = new;
	}
	else
		*lst = new;
}

t_cost	*ft_newcost(int index, int up, int down)
{
	t_cost	*node;

	node = (t_cost *)malloc(sizeof(t_cost));
	if (!node)
		return (NULL);
	node->index = index;
	node->cost_up = up;
	node->cost_down = down;
	node->next = NULL;
	return (node);
}

void	free_stack_cost(t_cost **list)
{
	t_cost	*temp;
	t_cost	*node;

	node = *list;
	while (node)
	{
		temp = node;
		node = node->next;
		free(temp);
	}
	free(list);
}

void	ft_lstclear_cost(t_cost **lst)
{
	t_cost	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone_cost(*lst);
		*lst = temp;
	}
}

void	ft_lstdelone_cost(t_cost *lst)
{
	if (!lst)
		return ;
	free(lst);
}

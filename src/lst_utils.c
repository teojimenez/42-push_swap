/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:08:52 by teojimen          #+#    #+#             */
/*   Updated: 2024/01/10 11:08:52 by teojimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*p;

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

void	ft_put_prev(t_node **head_a)
{
	t_node	*current;
	t_node	*prev;

	prev = NULL;
	current = *head_a;
	while (current)
	{
		current->prev = prev;
		prev = current;
		current = current->next;
	}
}

int	ft_lstsize(t_node *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_node	*ft_newnode(int content)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->content = content;
	node->index = -1;
	node->next = NULL;
	return (node);
}

void	free_stack(t_node **list)
{
	t_node	*node;
	t_node	*temp;

	node = *list;
	while (node)
	{
		temp = node;
		node = node->next;
		free(temp);
	}
	free(list);
}

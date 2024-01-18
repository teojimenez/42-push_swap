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

#include "push_swap."

void ft_lstadd_back(t_node **lst, t_node *new)
{
    t_node *p;

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

void ft_put_prev(t_node **head_a)
{
    t_node *current = *head_a;
    t_node *prev = NULL;


    if (*head_a == NULL)
        return ;
    while (current != NULL)
    {
        current->prev = prev; //set prev al anterior
        prev = current; //prev es el actual
        current = current->next;//avanzas
    }
}

int	ft_lstsize(t_node *lst)
{
	int i;

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


void    free_stack(t_node **list)
{
    t_node *temp;
    t_node *node;

    node = *list;
    while(node)
    {
        temp = node;
        node = node->next;
        free(temp);
    }
    free(list);
}

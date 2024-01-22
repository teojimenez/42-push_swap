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

#include "push_swap.h"

void ft_lstadd_back(t_node **lst, t_node *new)
{
    t_node *p;

    if (*lst)
    {
        p = *lst;
        // if(!lst)
	    // {   
          while (p->next)
                p = p->next;
            p->next = new;
        // }
    }
    else
        *lst = new;
}

void ft_lstadd_back_cost(t_cost **lst, t_cost *new)
{
    t_cost *p;

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


    // if (*head_a == NULL)
    //     return ;
    while (current)
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
void    free_stack_cost(t_cost **list)
{
    t_cost *temp;
    t_cost *node;

    node = *list;
    while(node)
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
// void	ft_lstclear_cost(t_cost **lst)
// {
// 	t_cost	*temp;

// 	while (*lst)
// 	{
// 		temp = (*lst)->next;
// 		ft_lstdelone_cost(*lst);
// 		*lst = temp;
// 	}
// }

void	ft_lstdelone_cost(t_cost *lst)
{
	if (!lst)
		return ;
	free(lst);
}

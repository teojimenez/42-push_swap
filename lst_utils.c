#include "push_swap.h"

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



t_node	*ft_newnode(int content)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->content = content;
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
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

t_node	*ft_newnode(int content, int index)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->content = content;
	node->index = index;
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
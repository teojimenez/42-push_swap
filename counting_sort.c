/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counting_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 11:50:17 by teojimen          #+#    #+#             */
/*   Updated: 2024/01/14 11:50:17 by teojimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void algorithm(t_node **head_a)
{
    t_counting **template;
    t_node *current;
    t_node *current_template;

    current = *head_a;
    current_template = *template;
    template = counting_template();
    if (!template)
        return ;
    //rellenar
    while(current ->next)
    {
        current_template = *template;
        while(current_template->next)
        {
            if(current->index == current_template->index)
            {
                current_template->content++;
                break;
            }else
                current_template = current_template->next;
        }
        current = current->next;
    }
    
}

t_counting **counting_template()
{
    int i = 0;
    template = (t_node **)malloc(sizeof(t_node *));

    while(i <= 9)
    {
		t_node *new;
        new = ft_newnode(0);
        if(!new)
        {
            free_stack(template);	
            return(0);
        }
        new->index = i;
        ft_lstadd_back(template, new);
        i++;
    }
    return (template);
}
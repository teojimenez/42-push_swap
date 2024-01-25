/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 09:38:49 by teojimen          #+#    #+#             */
/*   Updated: 2023/12/12 09:38:49 by teojimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int isNum(char *str)
{
	char *regex;
	int	i;
	
	i = 0;
	regex = "-0123456789";
	while(*str)
	{
		i = 0;
		while(regex[i] != '\0')
		{
			if (regex[i] == *str)
				break;
			i++;
		}
		if(regex[i] == '\0' && regex[i - 1] != *str)
			return (-1);
		str++;
	}
	return (0);
}

int isRepeat(char *str, t_node **lst)
{
	int nb;
	nb = ft_atoi(str);
	t_node *current = NULL;
	// if(*lst)
	// if(!lst)
	// {
		current = *lst;
		while(current)
		{
			if(current->content == nb)
				return (-1);
			current = current->next;
		}
	// }
	return(0);
}

int look_error(char *str, t_node **lst)
{
	int flag = 0;
	
	if(isNum(str) == -1)
		flag = -1;
	else if(ft_atol(str) < -2147483648 || ft_atol(str) > 2147483647)
		flag = -1;
	else if(isRepeat(str, lst) == -1)
		flag = -1;
	if (flag == -1)
		write(1, "Error\n", 6);
	return (flag);
}

void ft_index(t_node **head_a, int size)
{
    int    step;
    int    i = 0;
    int    temp;
    t_node *current = *head_a;
  int *tab = (int *)malloc((size + 1) * sizeof(int));
  while(i < size)
  {
    tab[i] = current->content;
    current = current->next;
    i++;
  }
  tab[i] = '\0';
    step = 0;
    while (step < size)
    {
        i = 0;
        while (i < size - 1)
        {
            if (tab[i] > tab[i + 1])
            {
                temp = tab[i];
                tab[i] = tab[i + 1];
                tab[i + 1] = temp;
            }
            i++;
        }
        step++;
    }
    step = 0;
    i = 0;
    current = *head_a;
    while (step < size && current)
    {
        i = 0;
        while (i < size)
        {
          if(current->content == tab[i])
          {
           current->index = i + 1;
           break;
          }
            i++;
        }
        current = current->next;
        step++;
    }
  
}

int is_sorted(t_node **head_a)
{
    t_node *current;
    current = *head_a;

    while (current->next)
    {
        if(current->content > current->next->content)
            return (-1);
        current = current->next;
    }
    return (0);
}
int index_sorted(t_node **head_a)
{
    t_node *current;
    current = *head_a;

    while (current->next)
    {
        if(current->index != current->next->index - 1)
            return (-1);
        current = current->next;
    }
    return (0);
}


int	convert_nb_index(int argc, char **argv, t_node **lst)
{
	int i = 1;
	int nb = 0;
	int index = 0;

	if(argc <= 1)
		return (-1);
	while (i < argc)
	{
        if (look_error(argv[i], lst) == -1)
            return (-1);
		else
		{
			nb = ft_atoi(argv[i]);
			t_node *new;
			
			new = ft_newnode(nb);
			if(!new)
			{
				free_stack(lst);	
				return(-1);
			}
			ft_lstadd_back(lst, new);
		}
		index++;
        i++;
	}
	ft_put_prev(lst);
	ft_index(lst, ft_lstsize(*lst));
	return (0);
}

void sort_menu(t_node **head_a)
{
	int size;
	t_node *current;

	current = *head_a;
	size = ft_lstsize(current);
	if(size == 2)
		sa_sb(head_a, 1);
	else if(size == 3)
		size3(head_a);
	else if(size == 5)
		size5(head_a);
	else
		algorithm(head_a);
}
#include <stdio.h>

void print_stack(t_node **stack) 
{
	t_node *temp; 
	temp = *stack; 
	while (temp) 
	{ 
		printf("value -> %d\n", temp->content); 
		temp = temp->next;
	}
}


int	main(int argc, char **argv)
{
	t_node **stock_a;
	stock_a = (t_node **)malloc(sizeof(t_node *)); //porque no t_node;
	if(!stock_a)
		return (-1);
	(*stock_a) = NULL;
	//put the numbers in a list
	if (convert_nb_index(argc, argv, stock_a) == -1)
		return (free_stack(stock_a), 0);
	if(is_sorted(stock_a) == -1)
		sort_menu(stock_a);
	print_stack(stock_a);
	free_stack(stock_a);
	return (0); 
}

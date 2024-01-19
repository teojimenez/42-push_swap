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

int look_error(char *str)
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
		{
			write(1, "ERROR", 5);
			return (-1);
		}
		str++;
	}
	return (0);
}

int ft_atoi(char *str)
{
	int	i;
	int	nb;
	int	sig;

	sig = 1;
	i = 0;
	nb = 0;
	if (str[i] == '-')
	{
		sig = sig * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb * sig);
}

void ft_index(t_node **head) {
    int index = 1;
    int min = 0;
    int max = 0;

    // Encontrar el rango de contenidos
    t_node *current = *head;
    while (current) {
        if (current->content < min) {
            min = current->content;
        }
        if (current->content > max) {
            max = current->content;
        }
        current = current->next;
    }

	int i = min;
	while(i <= max)
	{		
        current = *head;
        while (current) {
            if (current->index == -1 && current->content == i) {
                current->index = index++;
            }
            current = current->next;
        }
		i++;
	}
}

int is_sorted(t_node **head_a)
{
	t_node *current;
	current = *head_a;

	while (current->next->next && current->next < current ->next->next)
		current = current->next;

	if (current->next->next)
		return (0);
	return (-1);
}

int	convert_nb_index(int argc, char **argv, t_node **lst, int flag)
{
	int i = 1;
	if	(flag == 1)
	{
		argc++;
		i = 0;
	}
	int nb = 0;
	int index = 0;
	while (i < argc)
	{
        if (look_error(argv[i]) == -1)
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
	ft_index(lst);
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
	else
		algorithm(head_a);
}

int	main(int argc, char **argv)
{
	t_node **stock_a;
	int flag = 0;
	if(argc == 2 && char_exists(argv[1], ' '))
	{
		argv = ft_split(argv[1], ' ');
		flag = 1;
	}
	stock_a = (t_node **)malloc(sizeof(t_node *)); //porque no t_node;
	//put the numbers in a list
	if (convert_nb_index(argc, argv, stock_a, flag) == -1)
		return (free_stack(stock_a), 0);
	if(is_sorted(stock_a) == -1)
		sort_menu(stock_a);
	free_stack(stock_a);
	return (0); 
}

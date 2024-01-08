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

int ft_min(t_node *current, int flag, int last)
{
    int min;

    min = current->content;
    while(current)
    {
        if (flag == 1)
        {
            if (current->content < min)
                min = current->content;
        }
        else
        {
            if (current->content < min && current->content > last)
                min = current->content;
        }
        current = current->next;
    }
    return (min);
}

void	ft_index(t_node **lst)
{
	t_node	*l;
	t_node	*l2;
	int		i;
	int		size;
	int		step;

	i = 0;
	l = *lst;
	l2 = *lst;
	int min = ft_min(l, 1, 0);
	while(l->content != min)
		l = l->next;
	l->index = i++;
	l = *lst;
	size = ft_lstsize(l);
	step = 0;


	while (step < size - 1)
	{
		while(i < size)
		{
			l2 = *lst;
			if(ft_min(l2, 0, min) == l->content)
			{
				l->index = i++;
				min = l->content;
				break;
			}
			l = l->next;
		}
		l = *lst;
		step++;
	}
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
			
			new = ft_newnode(nb, index);
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
	ft_index(lst);
	return (0);
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
		free_stack(stock_a);
	return (0);
}

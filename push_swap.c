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
			return (-1);
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

int	convert_add_num(int argc, char **argv, t_node **lst)
{
	int i = 1;
	int nb = 0;

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
        i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_node **stock_a;

	stock_a = (t_node **)malloc(sizeof(t_node *)); //porque no t_node;
	//put the numbers in a list
	if (convert_add_num(argc, argv, stock_a) == -1)
	{
		free_stack(stock_a);
		write(1, "ERROR", 5);
	}
	return (0);
}
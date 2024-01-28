/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_nb_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 08:33:20 by teojimen          #+#    #+#             */
/*   Updated: 2024/01/28 08:33:20 by teojimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_num(char *str)
{
	char	*regex;
	int		i;

	i = 0;
	regex = "-0123456789";
	while (*str)
	{
		i = 0;
		while (regex[i] != '\0')
		{
			if (regex[i] == *str)
				break ;
			i++;
		}
		if (regex[i] == '\0' && regex[i - 1] != *str)
			return (-1);
		str++;
	}
	return (0);
}

int	is_repeat(char *str, t_node **lst)
{
	int		nb;
	t_node	*current;

	nb = ft_atoi(str);
	current = *lst;
	while (current)
	{
		if (current->content == nb)
			return (-1);
		current = current->next;
	}
	return (0);
}

int	look_error(char *str, t_node **lst)
{
	int	flag;

	flag = 0;
	if (is_num(str) == -1)
		flag = -1;
	else if (ft_atol(str) < -2147483648 || ft_atol(str) > 2147483647)
		flag = -1;
	else if (is_repeat(str, lst) == -1)
		flag = -1;
	if (flag == -1)
		write(1, "Error\n", 6);
	return (flag);
}

int	supp_convert_nb_index(char **argv, int *i, t_node **lst)
{
	int		nb;
	t_node	*new;

	nb = 0;
	if (look_error(argv[*i], lst) == -1)
		return (-1);
	else
	{
		nb = ft_atoi(argv[*i]);
		new = ft_newnode(nb);
		if (!new)
		{
			free_stack(lst);
			return (-1);
		}
		ft_lstadd_back(lst, new);
	}
	return (0);
}

int	convert_nb_index(int argc, char **argv, t_node **lst)
{
	int	i;

	i = 1;
	if (argc <= 1)
		return (-1);
	while (i < argc)
	{
		if (supp_convert_nb_index(argv, &i, lst) == -1)
			return (-1);
		i++;
	}
	ft_put_prev(lst);
	ft_index(lst, ft_lstsize(*lst));
	return (0);
}

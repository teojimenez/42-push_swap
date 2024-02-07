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

#include "../includes/push_swap.h"

int	is_num(char *str)
{
	char	*regex;
	int		i;
	int		min_c;

	i = -1;
	min_c = 0;
	regex = "-0123456789";
	if (!str || *str == '\0')
		return (-1);
	while (*str)
	{
		i = -1;
		while (regex[++i] != '\0')
		{
			if (regex[i] == *str && regex[i] == '-')
				min_c++;
			if (regex[i] == *str)
				break ;
		}
		if ((regex[i] == '\0' && regex[i - 1] != *str) \
		|| min_c > 1 || (str[0] == '-' && min_c > 1))
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
	if (!str || (!ft_isdigit(str[0]) && ft_strlen(str) == 1))
		flag = -1;
	else if (is_num(str) == -1)
		flag = -1;
	else if ((ft_atol(str) < -2147483648 || ft_strlen(str) > 11) \
	|| ft_atol(str) > 2147483647)
		flag = -1;
	else if (is_repeat(str, lst) == -1)
		flag = -1;
	else if (ft_duplicated(str) == -1)
		flag = -1;
	if (flag == -1)
		write(2, "Error\n", 7);
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
	if (is_num(argv[1]) == -1 && ft_lstsize(*lst) < 2)
	{
		look_error("", 0);
		return (-1);
	}
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

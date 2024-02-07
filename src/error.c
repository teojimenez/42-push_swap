/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:50:27 by teojimen          #+#    #+#             */
/*   Updated: 2024/02/07 18:50:27 by teojimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_error(int type)
{
	if (type == 1)
		write(2, "Error\n", 7);
	return (-1);
}

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

int	ft_duplicated(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str == NULL)
		return (-1);
	while (str[i] != '\0')
	{
		j = 0;
		while (j < i)
		{
			if (str[j] == str[i] && !ft_isdigit((int)str[i]))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:08:19 by teojimen          #+#    #+#             */
/*   Updated: 2024/01/10 11:08:19 by teojimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int     char_exists(const char *str, int c)
{
	int	i;
	int	size;

	size = ft_strlen(str);
	i = 0;
	while (i <= size)
	{
		if (str[i] == (char)c)
			return 1;
		i++;
	}
	return (0);
}

int tabsize(int *tab)
{
    int i = 0;

    while(tab[i])
      i++;
    return (i);
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

long    ft_atol(const char *str)
{
    long    sig;
	long    nb;
	int i;

	i = 0;
	sig = 1;
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

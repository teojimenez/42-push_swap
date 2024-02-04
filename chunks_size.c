/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 13:06:09 by teojimen          #+#    #+#             */
/*   Updated: 2024/01/28 13:06:09 by teojimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_nb_fractions(int nb)
{
	int	fractions;

	if (nb <= 30)
		fractions = 6;
	else if (nb > 30 && nb <= 100)
		fractions = 5;
	else
		fractions = 12;
	return (fractions);
}

int	need_last(int nb, int *fractions, int chunk_size, int *last)
{
	if (chunk_size * (*fractions) != nb)
	{
		*last = nb - (chunk_size * (*fractions));
		(*fractions)++;
		return (1);
	}
	else
		return (0);
}

void	fill_result(int fractions, int **result, int c_size, int nb)
{
	int	j;
	int	flag;
	int	last;

	j = -1;
	flag = need_last(nb, &fractions, c_size, &last);
	while (++j < fractions)
	{
		if (j == fractions - 1 && flag == 1)
			(*result)[j] = last;
		else
			(*result)[j] = c_size;
	}
	(*result)[fractions] = '\0';
}

int	*ft_fractions(int nb)
{
	int	fractions;
	int	chunk_size;
	int	last;
	int	flag;
	int	*result;

	last = 0;
	flag = 0;
	fractions = get_nb_fractions(nb);
	chunk_size = nb / fractions;
	result = (int *)malloc((fractions + 1) * sizeof(int));
	if (!result)
		return (NULL);
	fill_result(fractions, &result, chunk_size, nb);
	return (result);
}

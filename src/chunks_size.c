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

#include "../includes/push_swap.h"

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
		return (1);
	}
	else
		return (0);
}

int	sum_tab(int *tab)
{
	int	tab_size;
	int	sum;
	int	i;

	i = -1;
	sum = 0;
	tab_size = tabsize(tab);
	while (tab_size > ++i)
		sum += tab[i];
	return (sum);
}

void	fill_result(int fractions, int **result, int c_size, int nb)
{
	int	j;
	int	flag;
	int	last;

	j = -1;
	flag = need_last(nb, &fractions, c_size, &last);
	while (++j < fractions)
		(*result)[j] = c_size;
	(*result)[fractions] = '\0';
	j = -1;
	while (sum_tab((*result)) < nb)
	{
		if (j - 1 == tabsize((*result)))
			j = -1;
		++j;
		(*result)[j]++;
	}
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

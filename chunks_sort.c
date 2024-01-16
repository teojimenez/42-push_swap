/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 11:50:17 by teojimen          #+#    #+#             */
/*   Updated: 2024/01/14 11:50:17 by teojimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *ft_fractions()
{
    int size;
    int nb; //por lo que se fraccionan
    int nb_size = 4;
    int flag  = 0;
    size = 323;
    int *result;

    int i = 0;
    int j = 0;
    if (size % 3 == 0)
        nb_size = 3;
    else
    { //optimizar para que este mas compensado
        flag = 1;
        nb = size / 3;
        while(size != (nb * 3) + i)//4 numeros, ultimo i
            i++;
    }
    nb = size / 3; //por lo que se dividen los 3 numeros

    result = (int *)malloc((nb_size + 1) * sizeof(int));
    if(!result)
        return NULL;
    while(j < nb_size)
    {
        if (j == nb_size - 1 && nb_size == 4)
            result[j] = i;
        else
          result[j] = nb;
        j++;
    }
    result[j] = '\0';
    return result;
}

void algorithm(t_node **head_a)
{
    int *tab;
    tab = ft_fractions(head_a);
}
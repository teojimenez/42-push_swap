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
#include "printf/ft_printf.h"

int atoi_error(char *str)
{
	int	i;
	int	nb;
	int	sig;

	sig = 1;
	i = 0;
	nb = 0;
	//look for something more
	

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

int	check_num(int argc, char **argv)
{
	int i = 1;

	// int *argv_int;
	int *error = 0;
	// argv_int = (int *)malloc(argc - 1  * sizeof(int));
	// if (!argv_int)
	// 	return (-1); //error de asignar memoria
	while (i < argc - 1)
	{
        if (atoi_error(argv[i]) == -1)
        {
            // free(argv_int);
            return (-1);
        }
        // argv_int[i] = atoi_error(argv[i]);
        i++;
	}
	// free(argv_int);
	return (0);
}

int	main(int argc, char **argv)
{
	//put the numbers in a list
	//check is all argv are numbers
	if(check_num(argc, argv) == -1)
		ft_printf("ERROR");
	return (0);
}
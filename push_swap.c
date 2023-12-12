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

int *atoi(char **argv, int *error)
{
	
}

int	check_num(argc, argv)
{
	int i = 0;

	int *argv_int;
	int *error = 0;
	argv_int = (int *)malloc(argc - 1  * sizeof(int));
	if (!argv_int)
		return (0);
	while (argc - 1 > 0)
	{
		argv_int = atoi(argv, &error);
		if (error == -1)
			return (-1); //hay algo que no es numero
	}
	return (0);
}

int	main(int argc, char **argv)
{
	//check is all argv are numbers
	check_num(argc, argv);
	return (0);
}
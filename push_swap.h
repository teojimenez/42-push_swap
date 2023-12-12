/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 09:16:45 by teojimen          #+#    #+#             */
/*   Updated: 2023/12/12 09:16:45 by teojimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "push_swap.h"
# include <stdio.h> //printf
# include <stdlib.h> //malloc

//list
typedef struct s_node
{
	int		content;
	struct s_node	*before;
	struct s_node	*after;
} t_node;

//functions

#endif
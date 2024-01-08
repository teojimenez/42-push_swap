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
# include <unistd.h>
//list
typedef struct s_node
{
	int		content;
	int		index;
	// struct s_node	*before;
	// struct s_node	*after;
	struct s_node	*next;
} t_node;
	
//functions
void	ft_lstadd_back(t_node **lst, t_node *new);
t_node	*ft_newnode(int content, int index);
int		ft_lstsize(t_node *lst);
void    free_stack(t_node **list);
int     char_exists(const char *str, int c);
char	**ft_split(char const *s, char c);

#endif
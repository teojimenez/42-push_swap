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
# include <stdlib.h> //malloc
# include <unistd.h>

//list
typedef struct s_node
{
	int		content;
	int		index;
	struct s_node	*prev;
	struct s_node	*next;
} t_node;

typedef struct s_cost
{
	int		index;
	int		cost_up;
	int		cost_down;
	struct s_cost	*next;
} t_cost;

//functions
void	ft_lstadd_back(t_node **lst, t_node *new);
void ft_lstadd_back_cost(t_cost **lst, t_cost *new);
void	ft_put_prev(t_node **head_a);
t_node	*ft_newnode(int content);
int		ft_lstsize(t_node *lst);
void	free_stack(t_node **list);
void    free_stack_cost(t_cost **list);
int		char_exists(const char *str, int c);
char	**ft_split(char const *s, char c);
int    ft_atoi(char *str);
long    ft_atol(const char *str);

//operations and moves
void	sa_sb(t_node **head, int flag);
void	ss(t_node **head_a, t_node **head_b);
void	pa_pb(t_node **head_a, t_node **head_b, int flag);
void	ra_rb(t_node **head, int flag);
void	rr(t_node **head_a, t_node **head_b);
void	rra_rrb(t_node **head, int flag);
void	rrr(t_node **head_a, t_node **head_b);

void	first_two_change(t_node **head);
void	first_push(t_node **head_a, t_node **head_b);
void	rotate_down(t_node **head_a);
void	rotate_up(t_node **head_a);

void size3(t_node **head_a);
void algorithm(t_node **head_a, int argc);
int tabsize(int *tab);
t_cost	*ft_newcost(int index, int up, int down);
void	ft_lstclear_cost(t_cost **lst);
void	ft_lstdelone_cost(t_cost *lst);
void size5(t_node **head_a);
int is_sorted(t_node **head_a);
int index_sorted(t_node **head_a);
void print_stack(t_node **stack);

#endif
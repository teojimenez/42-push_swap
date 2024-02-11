/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spp_is_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:18:42 by teojimen          #+#    #+#             */
/*   Updated: 2024/02/11 18:18:42 by teojimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	supp_is_num(char c, int *min_c, int *max_c, char str)
{
	if (c == str && c == '-')
		(*min_c)++;
	else if (c == str && c == '+')
		(*max_c)++;
	if (c == str)
		return (0);
	return (1);
}

int	supp2_is_num(int min_c, int max_c, char *s)
{
	if (min_c > 0 && max_c > 0)
		return (0);
	else if ((min_c > 1 && s[0] == '-') || (min_c == 1 && s[0] != '-'))
		return (0);
	else if ((max_c > 1 && s[0] == '+') || (max_c == 1 && s[0] != '+'))
		return (0);
	return (1);
}

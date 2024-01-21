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

int* ft_fractions(t_node **head_a) {
    int nb;
    nb = ft_lstsize(*head_a);
    int nb_size; //->particiones
    int j = -1;
    int chunk_size; //-> tamanño de cada chunk
    int last;
    
    if (nb % 3 == 0) //divisiones
      nb_size = 3;
    else
      nb_size = 4;
    int *result = (int *)malloc((nb_size + 1) * sizeof(int));
    if (!result)
        return NULL;
    if(nb_size == 4) //tamaño de cada chunk
      chunk_size = nb / 4;
    else 
      chunk_size = nb / 3;
    if (nb_size == 4) //si es de 4 añadir lo que falta a last
      last = nb - (chunk_size * 3);
    while(++j < nb_size) //rellenar
    {
      if (j == nb_size - 1 && nb_size == 4)
        result[j] = last;
      else
        result[j] = chunk_size;
    }
    result[nb_size] = '\0';
    return (result);
}

int down_in_one_index(t_node **head_a, int index)
{
  t_node *current = *head_a;
  int count = 0;
  while(current)
  {
    if (current->index == index)
    {
        while(current)
        {
          count++;
          current = current->next;
        }
        return(count);
    }
    current = current->next;
  }
  return (0); //falta comprovar si suma uno de mas !!!
}

int up_in_one_index(t_node **head_a, int index)
{
  t_node *current = *head_a;
  int count = 0;
  while(current)
  {
    if (current->index == index)
        return (count);
    current = current->next;
    count++;
  }
  return (0);
}

int get_rango_min(int *tab, int tab_pos)
{
  int all;

  all = 0;
  while(tab_pos >= 0)
    all += tab[--tab_pos];
  return (all);
}

int content_in_costs(int* tab, int tab_pos, t_cost **head_costs, t_node**head_a)
{
  //current_a es el primer nodo de list_a
  //necesito el numero maximo del chunk y el menor tambien
  t_node *current_a = *head_a;
  int rango_min;
  int up;
  int down;

  rango_min = 0;
  if (tab_pos != 0)
  {
    rango_min = get_rango_min(tab, tab_pos);
    // rango_min = tab[tab_pos - 1];
  }
  
  while(current_a)
  {
    if (current_a->index >= rango_min && current_a->index <= (rango_min + tab[tab_pos]))
    {
      up = up_in_one_index(head_a, current_a->index);
      down = down_in_one_index(head_a, current_a->index);
      
      t_cost *new;

      new = ft_newcost(current_a->index, up, down);
      if(!new)
        {
            free_stack_cost(head_costs);
            return(-1);
        }
        ft_lstadd_back_cost(head_costs, new);
    }
    current_a = current_a->next;
  }
  return(0);
}

int up_to_push(int *up, t_cost **costs)
{
  t_cost *current_cost = *costs;
  
  *up = current_cost->cost_up;
  while(current_cost)
  {
    if (current_cost->cost_up < *up)
    {
      *up = current_cost->cost_up;
    }
    current_cost = current_cost->next;
  }
  current_cost = *costs;
  while(current_cost)
  {
    if (current_cost->cost_up == *up)
      return (current_cost->index);
    current_cost = current_cost->next;
  }
  return (0);
}

int down_to_push(int *down, t_cost **costs)
{
  t_cost *current_cost = *costs;
  
  *down = current_cost->cost_down;
  while(current_cost)
  {
    if (current_cost->cost_down < *down)
    {
      *down = current_cost->cost_down;
    }
    current_cost = current_cost->next;
  }
  current_cost = *costs;
  while(current_cost)
  {
    if (current_cost->cost_down == *down)
      return (current_cost->index);
    current_cost = current_cost->next;
  }
  return(0);
}

void push_less_cost(t_cost **costs, t_node **head_a, t_node **head_b)
{
  int up;
  int down;
  int index_up = up_to_push(&up, costs);
  int index_down = down_to_push(&down, costs);
  index_up = 0;
  index_down = 0;
  if(ft_lstsize(*head_a) > 1)
  {
    if (up >= down)//hacer el down
    {
      while(down-- > 0)
        rra_rrb(head_a, 1); //down
    }
    else
    {
      while(up-- > 0)
        ra_rb(head_a, 1); //up
    }
    // if (index_up >= index_down)//hacer el down
    // {
    //   while(down-- > i)
    //     rra_rrb(head_a, 1);
    // }
    // else
    // {
    //   while(up-- > i)
    //     ra_rb(head_a, 1);
    // }
  }
  pa_pb(head_a, head_b , 0);
}
int every_chunk (int *tab, int tab_pos, t_node **head_a, t_node **head_b)
{
    //crear una lista con los precios
    t_cost **costs;
    costs = (t_cost **)malloc(sizeof(t_cost *));
    if(!costs)
        return (-1);

    int rango = tab[tab_pos];
    int count = 0;
    while(count != rango)
    {
        content_in_costs(tab, tab_pos, costs, head_a);
        
        push_less_cost(costs, head_a, head_b);//->ahi dentro tener get_max y get_min de todos;
        ft_lstclear_cost(costs); //delete content costs
        count++;
    }
    //para cada valor ir buscando si encuentra ->
    //uno de los numeros en los rangos
    // encontrar el mas barato y entonces
    // els mas barato hacia arriba y hace abajo
    //hacer variable que extrae el mas barato abajo (funcion)
    //hacer variable que extrae el mas barato arriba(funcion)
    //hacer push
    //despues de cada push, se borra toda la lista;

    //para añadir a la lista una vez se sepa el down y up del node;
    // t_cost *new;
			
	// new = ft_newcost(index, down, up);
	// if(!new)
    // {
    //     free_stack(costs);	
    //     return(-1);
    // }
    // ft_lstadd_back(costs, new);
    free_stack_cost(costs);
    return(0);
}

void    sort_every_chunk(int *tab, t_node **head_a, t_node **head_b)
{
    int i = -1;
    // int tab_size = tabsize(tab);
    while(tab[++i])
    {
        if (every_chunk(tab, i, head_a, head_b) == -1)
          return ; //despues hacer que salga si falla
    }

}

void push_single_cheaper(t_node **head_a, t_node **head_b, int up, int down)
{
  if (ft_lstsize(*head_b) > 1)
  {
    if(up >= down)
    {
      while(down-- > 0)
        rra_rrb(head_b, 0); //down
    }
    else
    {
      while(up-- > 0)
        ra_rb(head_b, 0); //up
    }
  }
  pa_pb(head_a, head_b, 1);
}

void  search_b_number(t_node **head_a, t_node **head_b, int nb_index)
{
  t_node *current_b;
  int count_up = 0;
  int count_down = 0;
  current_b = *head_b;
  while(current_b)
  {
    if (current_b->index == nb_index)
    {
      while(current_b)
      {
        count_down++;
        current_b = current_b->next;
      }
      break;
    }
    count_up++;
    current_b = current_b->next;
  }
  push_single_cheaper(head_a, head_b, count_up, count_down);
}
void  sort_every_thing(t_node **head_a, t_node **head_b)
{
  int size;
  size = ft_lstsize(*head_b);
  while(size > 0)
  {
    search_b_number(head_a, head_b, size);
    size--;
    }
}


void algorithm(t_node **head_a)
{
    int *tab;
    t_node **stock_b;
    tab = ft_fractions(head_a);
    stock_b = (t_node **)malloc(sizeof(t_node *));
    if (!stock_b)
        return ; //que pete
    sort_every_chunk(tab, head_a, stock_b);
    sort_every_thing(head_a, stock_b);
    free(stock_b);
    stock_b = NULL;
    free(tab);
}
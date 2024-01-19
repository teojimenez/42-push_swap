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
    return result;
}

int min_in_one_index(t_node **head_a, int index)
{
  t_node *current = *head_a;
  int count = 0;
  while(current)
  {
    if (current->index = index)
    {
        while(current)
        {
          count++;
          current = current->next;
        }
        return(count + 1); //mirar si hace falta sumar uno o restarlo!!!1
    }
    current = current->next;
    count++;
  }
  return (0); //falta comprovar si suma uno de mas !!!
}

int max_in_one_index(t_node **head_a, int index)
{
  t_node *current = *head_a;
  int count = 0;
  while(current)
  {
    if (current->index = index)
    {
        return (count + 1); //falta comprovar si suma uno de mas !!!
    }
    current = current->next;
    count++;
  }
  return (0);
}


int content_in_costs(int* tab, int tab_pos, t_cost **head_costs, t_node**head_a)
{
  //current_a es el primer nodo de list_a
  //necesito el numero maximo del chunk y el menor tambien
  t_node *current_a = *head_a;
  int rango_min;
  int max;
  int min;

  rango_min = 0;
  if (tab_pos != 0)
    rango_min = tab[tab_pos - 1];
  
  while(current_a)
  {
    if (current_a->index <= rango_min && current_a->index >= tab[tab_pos])
    {
      max = max_in_one_index(head_a, current_a->index);
      min = min_in_one_index(head_a, current_a->index);
      //encontrar el altura hacia arriba y altura hacia abajo
    }
    current_a ->next;
  }
  return(0);
}

int every_chunk(int *tab, int tab_pos, t_node **head_a, t_node **head_b)
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
        content_in_costs(rango, tab_pos, costs, head_a);
        push_less_cost();//->ahi dentro tener get_max y get_min de todos;
        //liberar toda la lista de costs
        
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
}

void    sort_every_chunk(int *tab, t_node **head_a, t_node **head_b)
{
    int i = -1;
    int tab_size = tabsize(tab);
    while(tab[++i])
    {
        if (every_chunk(tab, i, head_a, head_b) == -1);
          return (NULL); //despues hacer que salga si falla
    }

}


void algorithm(t_node **head_a)
{
    int *tab;
    t_node **stock_b;
    tab = ft_fractions(head_a);
    stock_b = (t_node **)malloc(sizeof(t_node *));
    if (!stock_b)
        //algo
    sort_every_chunk(tab, head_a, stock_b);
    free(tab);
}
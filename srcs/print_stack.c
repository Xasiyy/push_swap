/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdiallo <asiya040906@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:36:45 by asdiallo          #+#    #+#             */
/*   Updated: 2024/12/16 11:35:15 by asdiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(t_stack *stack)
{
   t_node *current;

   current = stack->top;
   while (current)
   {
      printf("%d\n", current->value);
      current = current->next;
   }
}

void init_stack_with_values(t_stack *stack, int values[], int size)
{
    for (int i = 0; i < size; i++)
    {
        add_elem(stack, values[i]);
    }
}

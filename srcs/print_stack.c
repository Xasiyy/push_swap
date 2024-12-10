/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdiallo <asiya040906@gmailc.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:36:45 by asdiallo          #+#    #+#             */
/*   Updated: 2024/12/10 10:26:42 by asdiallo         ###   ########.fr       */
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

void    test_operations()
{
    t_stack *stack_a = init_stack();
    t_stack *stack_b = init_stack();

    int values_a[] = {1, 2, 3, 4, 5};
    int values_b[] = {};

    init_stack_with_values(stack_a, values_a, 5);
    init_stack_with_values(stack_b, values_b, 0);

    printf("Initial stack A:\n");
    print_stack(stack_a);
    printf("Initial stack B:\n");
    print_stack(stack_b);

    pa(stack_a, stack_b);
    printf("stack A, B\n");
    print_stack(stack_a);
    printf("\n....\n");
    print_stack(stack_b);
    pb(stack_b, stack_a);
    printf("stack B, A\n");
    print_stack(stack_b);
    printf("\n....\n");
    print_stack(stack_a);

    // Free the stacks
    free_stack(stack_a);
    free_stack(stack_b);
}

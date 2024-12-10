/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdiallo <asiya040906@gmailc.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:36:45 by asdiallo          #+#    #+#             */
/*   Updated: 2024/12/10 15:27:03 by asdiallo         ###   ########.fr       */
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

void    test_operations(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b = init_stack();

/*     int values_a[] = {1, 2, 3, 4, 5};
    int values_b[] = {};

    init_stack_with_values(stack_a, values_a, 5);
    init_stack_with_values(stack_b, values_b, 0); */

    stack_a = creat_stack(argc, argv);

    printf("Initial stack A:\n");
    print_stack(stack_a);
    printf("Initial stack B:\n");
    print_stack(stack_b);

    pa(stack_a, stack_b);
    pa(stack_a, stack_b);
    pa(stack_a, stack_b);
    sa(stack_a);
    printf("stack A, B\n");
    print_stack(stack_a);
    printf("\n....\n");
    print_stack(stack_b);
    sb(stack_b);
    printf("stack A, B\n");
    print_stack(stack_a);
    printf("\n....\n");
    print_stack(stack_b);

    // Free the stacks
    free_stack(stack_a);
    free_stack(stack_b);
}

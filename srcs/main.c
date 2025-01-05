/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdiallo <asiya040906@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 21:29:55 by asdiallo          #+#    #`+#             */
/*   Updated: 2024/12/10 09:33:58 by asdiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
    t_stack	*stack_a;
    t_stack *stack_b;

    if (argc < 2)
        return (1);

    if (parsing(argc, argv) < 0)
    {
        printf("error: duplicate value\n");
        return (1);
    }

    stack_a = create_stack(argc, argv);
    if (!stack_a)
        return (1);

    stack_b = init_stack();
    if (!stack_b)
    {
        free_stack(&stack_a);
        return (1);
    }

	printf("Adresse de stack_a : %p\n", (void *)stack_a);
	printf("Adresse de stack_b : %p\n", (void *)stack_b);

    printf("Initial stack A:\n");
    print_stack(stack_a);

    turkish_sort(stack_a, stack_b);
    printf("Sorted stack A:\n");
    print_stack(stack_a);
	printf("stack B :");
	print_stack(stack_b);
    free_stack(&stack_a);
	printf("la pile a est free");
    free_stack(&stack_b);
	printf("la pile b est free");
    return (0);
}

/* int main(void)
{
    t_stack *stack_a = init_stack();
    t_stack *stack_b = init_stack();

    add_elem(stack_a, 1);
    add_elem(stack_a, 2);
    add_elem(stack_a, 3);

    printf("Avant push : stack_a->size = %d, stack_b->size = %d\n", stack_a->size, stack_b->size);
    push(stack_a, stack_b);
    printf("Après push : stack_a->size = %d, stack_b->size = %d\n", stack_a->size, stack_b->size);
    push(stack_a, stack_b);
    printf("Après 2ème push : stack_a->size = %d, stack_b->size = %d\n", stack_a->size, stack_b->size);

    free_stack(stack_a);
    free_stack(stack_b);
    return 0;
} */

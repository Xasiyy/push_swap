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

int count = 0;

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

    printf("Initial stack A:\n");
    print_stack(stack_a);

    sort_stack(stack_a, stack_b);
    printf("Sorted stack A:\n");
    print_stack(stack_a);
    printf("sttack B\n");
    print_stack(stack_b);
    printf("count=%d\n", count);
    free_stack(&stack_a);
    free_stack(&stack_b);
    return (0);
}   

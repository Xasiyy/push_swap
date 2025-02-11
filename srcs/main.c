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

int main(int argc, char **argv) {
    t_stack_node *a = NULL;
    t_stack_node *b = NULL;

    if (argc < 2)
        return 1;
    init_stack_a(&a, argv + 1);
    
    if (!stack_sorted(a)) {
        if (stack_len(a) == 2) {
            sa(&a, false);
            update_all_stacks(&a, NULL);
        }
        else if (stack_len(a) == 3)
            sort_three(&a);
        else
            sort_stacks(&a, &b);
    }
    t_stack_node *curr = a;
    while (curr) {
        printf("%d ", curr->nbr);
        curr = curr->next;
    }
    printf("\n");
    free_stack(&a);
    free_stack(&b);
    return 0;
}


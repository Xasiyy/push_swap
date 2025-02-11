/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdiallo <asiya040906@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:18:20 by asdiallo          #+#    #+#             */
/*   Updated: 2024/12/31 22:51:16 by asdiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *init_stack()
{
    t_stack *stack = malloc(sizeof(t_stack));
    if (!stack)
        return NULL;
    stack->head = NULL;
    return stack;
}

void free_stack(t_stack_node **stack) {
    t_stack_node *curr = *stack;
    while (curr) {
        t_stack_node *next = curr->next;
        free(curr);
        curr = next;
    }
    *stack = NULL;
}

int stack_len(t_stack_node *stack) {
    int count = 0;
    t_stack_node *curr = stack;
    while (curr) {
        count++;
        curr = curr->next;
    }
    return count;
}

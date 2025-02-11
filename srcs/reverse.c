/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdiallo <asiya040906@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 21:17:02 by asdiallo          #+#    #+#             */
/*   Updated: 2024/12/23 15:15:38 by asdiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void rev_rotate(t_stack_node **stack)
{
    if (!stack || !*stack || !((*stack)->next))
        return;
    t_stack_node *last = find_last(*stack);
    if(last->prev)
        last->prev->next = NULL;
    last->prev = NULL;
    last->next = *stack;
    (*stack)->prev = last;
    *stack = last;
}

void rra(t_stack_node **a, bool print)
{
    rev_rotate(a);
    if (!print)
        printf("rra\n");
}

void rrb(t_stack_node **b, bool print)
{
    rev_rotate(b);
    if (!print)
        printf("rrb\n");
}

void rrr(t_stack_node **a, t_stack_node **b, bool print)
{
    rra(a, true);
    rrb(b, true);
    if (!print)
        printf("rrr\n");
}

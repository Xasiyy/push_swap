/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdiallo <asiya040906@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:44:56 by asdiallo          #+#    #+#             */
/*   Updated: 2024/12/02 21:08:43 by asdiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void append_node(t_stack_node **stack, int n)
{
    t_stack_node *node = malloc(sizeof(t_stack_node));
    if (!node)
        return;
    node->value = n;
    node->cost = 0;
    node->index = 0;
    node->above_median = false;
    node->cheapest = false;
    node->target_node = NULL;
    node->next = NULL;
    node->prev = NULL;
    if (!*stack)
    {
        *stack = node;
    }
    else
    {
        t_stack_node *last = find_last(*stack);
        last->next = node;
        node->prev = last;
    }
}

void init_stack_a(t_stack_node **a, char **argv)
{
    long n;
    int i = 0;
    while (argv[i])
    {
        if (error_syntax(argv[i]))
            free_errors(a);
        n = atol(argv[i]);
        if (n > INT_MAX || n < INT_MIN)
            free_errors(a);
        if (error_duplicate(*a, (int)n))
            free_errors(a);
        append_node(a, (int)n);
        i++;
    }
}

void prep_push(t_stack_node **stack, t_stack_node *target, char stack_name)
{
    while (*stack != target)
    {
        if (stack_name == 'a')
            ra(stack, false);
        else
            rb(stack, false);
        update_all_stacks(stack, NULL);
    }
}

void prep(t_stack_node **a, t_stack_node **b, t_stack_node *node, char stack_name)
{
    (void)stack_name;
    while ((*a)->value != node->value)
    {
        if (node->above_median)
            ra(a, false);
        else
            rra(a, false);
        current_index(*a);
    }
    if (b && *b && node->target_node)
    {
        while ((*b)->value != node->target_node->value)
        {
            if (node->target_node->above_median)
                rb(b, false);
            else
                rrb(b, false);
            current_index(*b);
        }
    }
    update_all_stacks(a, b);
}

void update_all_stacks(t_stack_node **a, t_stack_node **b)
{
    init_nodes_a(a, b);
}



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

void insert_in_order(t_stack *stack_a, t_node *node)
{
    t_node *current = stack_a->top;
    if (!current || node->value < current->value)
    {
        node->next = current;
        stack_a->top = node;
        return;
    }

    while (current->next && current->next->value < node->value)
    {
        current = current->next;
    }

    node->next = current->next;
    current->next = node;
}

void insert_in_sorted_order(t_stack *stack_a, t_node *node)
{
    t_node *current = stack_a->top;
    while (current && current->next && current->value < node->value)
        current = current->next;
    node->next = current->next;
    current->next = node;
}

void min_on_top(t_stack *stack)
{
    t_node *current = stack->top;
    t_node  *min = find_min(stack);
    int steps = 0;

    while (current && current->value != min->value)
    {
        steps++;
        current = current->next;
    }

    if (steps > 0)
    {
        if (steps <= stack_size(stack) / 2)
        {
            while (steps--)
				ra(stack);
        }
        else
        {
            steps = stack_size(stack) - steps;
            while (steps--)
			rra(stack);
        }
    }
}

void move_a_to_b(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_size(stack_a) >  3)
		push_to_sorted_b(stack_a, stack_b);
}

void move_b_to_a(t_stack *stack_a, t_stack *stack_b)
{
    while (stack_size(stack_b) > 0)
    {
        pa(stack_b, stack_a);
    }
}

void sort_stacks(t_stack *stack_a, t_stack *stack_b)
{
    if (!stack_a || is_sorted(stack_a))
        return;

    move_a_to_b(stack_a, stack_b);
    sort_three(stack_a);
    move_b_to_a(stack_a, stack_b);
}


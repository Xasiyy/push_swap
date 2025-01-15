/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdiallo <asiya040906@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:26:45 by asdiallo          #+#    #+#             */
/*   Updated: 2025/01/08 14:26:45 by asdiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	push_to_sorted_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node *node_to_push;
	t_node *current;
	t_node *tmp;

	node_to_push = stack_a->top;
	if (!stack_b->top || node_to_push->value > stack_b->top->value)
		pb(stack_a, stack_b);
	else
	{
		current = stack_b->top;
		while (current->next && current->next->value > node_to_push->value)
			current = current->next;
		tmp = current->next;
		pb(stack_a, stack_b);
		stack_b->top->next = tmp;
		current->next = stack_b->top;
		stack_b->top = current->next;
	}
}

void current_index(t_stack *stack)
{
    int i = 0;
    int median;
    t_node *current = stack->top;

    if (!stack || !stack->top)
        return;
    median = stack_size(stack) / 2;
    printf("Calculating current indices with median: %d\n", median);
    while (current) {
        current->index = i;
        if (i <= median)
            current->above_median = true;
        else
            current->above_median = false;
        printf("Node value: %d, Index: %d, Above median: %s\n", current->value, current->index, current->above_median ? "true" : "false");
        current = current->next;
        ++i;
    }
}

void push_elem_b(t_stack *stack_a, t_stack *stack_b)
{
    int value_b = stack_b->top->value;
    t_node *current = stack_a->top;

    while (current && current->next && current->value < value_b)
        current = current->next;

    while (stack_a->top != current)
    {
        if (current->above_median)
            ra(stack_a);
        else
            rra(stack_a);
    }
    pa(stack_b, stack_a);
}


void move_to_top(t_stack *stack, t_node *node)
{
    int steps = 0;
    t_node *current = stack->top;
    while (current)
    {
        if (current == node)
            break;
        current = current->next;
        steps++;
    }
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

t_node *get_cheapest(t_stack *stack)
{
    t_node *current = stack->top;
    t_node *cheapest = NULL;
    long cheapest_cost = LONG_MAX;

    while (current)
    {
        if (current->push_cost < cheapest_cost)
        {
            cheapest_cost = current->push_cost;
            cheapest = current;
        }
        current = current->next;
    }
    return cheapest;
}


void indices_median(t_stack *stack)
{
	t_node *current;
	int size;
	int i;
	int median;

	if (!stack || !stack->top)
		return ;
	size = stack_size(stack);
	median = size / 2;
	current = stack->top;
	i = 0;
	while (current)
	{
		current->index = 1;
		if (i <= median)
			current->above_median = true;
		else
			current->above_median = false;
		current = current->next;
		i++;
	}
}

void set_target_a(t_stack *stack_a, t_stack *stack_b)
{
    t_node *current_a;
    t_node *current_b;
    t_node *target_node;
    int diff;
    int min_diff;

    target_node = NULL;
    if (!stack_a || !stack_b)
        return;

    current_a = stack_a->top;
    while (current_a)
    {
        current_b = stack_b->top;
        min_diff = INT_MAX;
        target_node = NULL;

        printf("Setting target for node A with value: %d\n", current_a->value);
        while (current_b)
        {
            diff = current_b->value - current_a->value;
            printf("  Comparing with node B, value: %d, diff: %d\n", current_b->value, diff);
            if (diff > 0 && diff < min_diff)
            {
                min_diff = diff;
                target_node = current_b;
            }
            current_b = current_b->next;
        }
        if (!target_node)
            target_node = find_max(stack_b);
        if (target_node)
            printf("Target for A node value %d: B node value %d\n", current_a->value, target_node->value);
        else
            printf("No target found for A node value %d, using max B\n", current_a->value);
        current_a->target = target_node;
        current_a = current_a->next;
    }
}


void set_target_b(t_stack *stack_a, t_stack *stack_b)
{
    t_node *current_a;
    t_node *current_b;
    t_node *target;
    int diff;
    int min_diff;

    if (!stack_a || !stack_b)
        return;
    current_a = stack_a->top;
    while (current_a)
    {
        current_b = stack_b->top;
        min_diff = INT_MAX;
        target = NULL;

        while (current_b)
        {
            diff = current_b->value - current_a->value;
            if (diff > 0 && diff < min_diff)
            {
                min_diff = diff;
                target = current_b;
            }
            current_b = current_b->next;
        }
        if (!target)
            target = find_max(stack_b);
        current_a->target = target;
        current_a = current_a->next;
    }
}

void cost(t_stack *stack_a, t_stack *stack_b)
{
    int len_a = stack_size(stack_a);
    int len_b = stack_size(stack_b);
    t_node *current_a = stack_a->top;
    
    while (current_a) {
        current_a->push_cost = current_a->index;
        if (!current_a->above_median)
            current_a->push_cost = len_a - current_a->index;
        if (current_a->target->above_median)
            current_a->push_cost += current_a->target->index;
        else
            current_a->push_cost += len_b - current_a->target->index;
        
        current_a = current_a->next;
    }
}

void prep_for_push(t_stack *stack, t_node *top_node, char stack_name)
{
    t_node *current = stack->top;

    while (current != top_node)
    {
        if (stack_name == 'a')
        {
            if (top_node->above_median)
                ra(stack);
            else
                rra(stack);
        }
        else if (stack_name == 'b')
        {
            if (top_node->above_median)
                rb(stack);
            else
                rrb(stack);
        }
        current = current->next;
    }
}


void cheapest_value(t_stack *stack)
{
    long cheapest_value = LONG_MAX;
    t_node *cheapest_node = NULL;
    t_node *current = stack->top;

    if (!stack || !stack->top)
        return;
    while (current) {
        if (current->push_cost < cheapest_value) {
            cheapest_value = current->push_cost;
            cheapest_node = current;
        }
        current = current->next;
    }   
    if (cheapest_node)
        cheapest_node->cheapest = true;
}

void init_nodes_a(t_stack *a, t_stack *b)
{
    current_index(a);
    current_index(b);
    set_target_a(a, b);
    cost(a, b);
	cheapest_value(a);
}

void init_nodes_b(t_stack *a, t_stack *b)
{
    current_index(a);
    current_index(b);
    set_target_b(a, b);
}

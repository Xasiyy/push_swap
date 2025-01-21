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

// prepush A to B 

void    find_index(t_stack *stack)
{
	int i;
	int median;
	int len;
	t_node *current;

	i = 0;
	if (!stack || !stack->top)
		return ;
	len = stack_size(stack);
	median = len / 2;
	current = stack->top;
	while (current)
	{
		current->index = i;
		current->above_median = (i <= median);
		current = current->next;
		i++;
		if (current == stack->top)
			break;
	}
}

void compare_node_a(t_stack *a, t_stack *b)
{
    t_node *current_a;
    t_node *current_b;
    t_node *best_target;
    int best_difference;

    if (!a || !a->top)
        return;
    current_a = a->top;
    while (current_a)
    {
        best_target = NULL;
        best_difference = INT_MAX;
        current_b = b->top;
        int iter_count = 0;
        while (current_b && iter_count < stack_size(b))
        {
            if (current_b->value < current_a->value &&
                (current_a->value - current_b->value) < best_difference)
            {
                best_difference = current_a->value - current_b->value;
                best_target = current_b;
            }
            current_b = current_b->next;
            iter_count++;
        }
        if (iter_count >= stack_size(b))
        {
            printf("Error: Infinite loop detected in compare_node_a\n");
            return;
        }
        if (best_target)
            current_a->target = best_target;
        else
            current_a->target = find_min(a);
        current_a = current_a->next;
        if (current_a == a->top)
            break;
    }
}


void    find_cost(t_stack *a, t_stack *b)
{
	t_node *current_a;
	int len_a;
	int len_b;

	if (!a || !b || !a->top || !b->top)
		return ;
	len_a = stack_size(a);
	len_b = stack_size(b);

	current_a = a->top;
	while (1)
	{
		if (current_a->index <= len_a / 2)
			current_a->cost_a = current_a->index;
		else
			current_a->cost_a = len_a - current_a->index;
		if (current_a->target->index <= len_b / 2)
			current_a->cost_b = current_a->target->index;
		else
			current_a->cost_b = len_b - current_a->target->index;
		current_a->push_cost = current_a->cost_a + current_a->cost_b;
		current_a = current_a->next;
		if (current_a == a->top)
			break;
	}
}

void	min_cost(t_stack *a)
{
	t_node *current;
	t_node *cheapest;
	int min_cost;

	if (!a || !a->top)
		return;
	current = a->top;
	cheapest = NULL;
	min_cost = INT_MAX;

	while (1)
	{
		if (current->push_cost < min_cost)
		{
			min_cost = current->push_cost;
			cheapest = current;
		}
		current = current->next;
		if(current == a->top)
			break;
	}
	current = a->top;
	while (1)
	{
		current->cheapest = (current == cheapest);
		current = current->next;
		if (current == a->top)
			break;
	}
}

void	calcul_nodes_a(t_stack *a, t_stack *b)
{
	find_index(a);
	find_index(b);
	compare_node_a(a, b);
	find_cost(a, b);
	min_cost(a);
}

// prepush B to A

bool	best_match(int a_value, int b_value, int index)
{
	return (a_value > b_value && a_value < index);
}

void	compare_node_b(t_stack *a, t_stack *b)
{
	t_node *current_a;
	t_node *node;
	t_node *current_b;
	long index;

	if (!a || !b || !a->top || !b->top)
		return;
	current_b = b->top;
	while (current_b)
	{
		current_a = a->top;
		node = NULL;
		index = LONG_MAX;
		while (current_a)
		{
			if (best_match(current_a->value, current_b->value, index))
			{
				index = current_a->value;
				node = current_a;
			}
			current_a = current_a->next;
		}
		if (index == LONG_MAX)
			current_b->target = find_min(a);
		else
			current_b->target = node;
		current_b = current_b->next;
	}
}

void	calcul_node_b(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return;
	find_index(a);
	find_index(b);
	compare_node_b(a, b);
}

void	prepush(t_stack *stack, t_node *top_node, char name)
{
	int size = stack_size(stack);
	int rotation_count = 0;
	if (!stack || !stack->top || !top_node)
		return ;
	while (stack->top != top_node)
	{
		if (rotation_count >= size)
		{
			printf("error infinite loop detected in prepush\n");
			return;
		}
		if (name == 'a')
		{
			if (top_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (name == 'b')
		{
			if (top_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}
		rotation_count++;
	}
}

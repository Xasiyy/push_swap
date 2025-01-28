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

// prepush B to A

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
			if (current_a->value > current_b->value && current_a->value < index)
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
	int size;
	int rotation_count;
	t_node *current;
	if (!stack || !stack->top || !top_node)
		return ;
	size = stack_size(stack);
	rotation_count = 0;
	current = stack->top;
	while (current)
	{
		if (current == top_node)
			break;
		current = current->next;
	}
	while (stack->top != top_node)
	{
		if (rotation_count >= size)
		{
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
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepush_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toadette <toadette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:29:21 by toadette          #+#    #+#             */
/*   Updated: 2025/01/28 15:06:32 by toadette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// prepush A to B

void	find_index(t_stack *stack)
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
	while(current)
	{
		current->index = i;
		current->above_median = i < median;
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
		while (current_b)
		{
			if (current_b->value < current_a->value &&
				(current_a->value - current_b->value) < best_difference)
			{
				best_difference = current_a->value - current_b->value;
				best_target = current_b;
			}
			current_b = current_b->next;
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

void	find_cost(t_stack *a, t_stack *b)
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

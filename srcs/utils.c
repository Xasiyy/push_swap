/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdiallo <asiya040906@gmailc.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:28:03 by asdiallo          #+#    #+#             */
/*   Updated: 2025/02/15 13:14:07 by asdiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*find_min(t_stack_node *stack)
{
	t_stack_node	*curr;
	t_stack_node	*min_node;

	if (!stack)
		return (NULL);
	curr = stack;
	min_node = stack;
	while (curr)
	{
		if (curr->value < min_node->value)
			min_node = curr;
		curr = curr->next;
	}
	return (min_node);
}

t_stack_node	*find_max(t_stack_node *stack)
{
	t_stack_node	*curr;
	t_stack_node	*max_node;

	if (!stack)
		return (NULL);
	curr = stack;
	max_node = stack;
	while (curr)
	{
		if (curr->value > max_node->value)
			max_node = curr;
		curr = curr->next;
	}
	return (max_node);
}

t_stack_node	*find_last(t_stack_node *stack)
{
	t_stack_node	*curr;

	if (!stack)
		return (NULL);
	curr = stack;
	while (curr->next)
		curr = curr->next;
	return (curr);
}

void	init_nodes_a(t_stack_node **a, t_stack_node **b)
{
	if (*a)
		current_index(*a);
	if (b && *b)
		current_index(*b);
	if (*a && b && *b)
	{
		set_target_a(*a, *b);
		cost_analysis_a(*a, *b);
	}
	if (*a)
		set_cheapest(*a);
}

void	init_nodes_b(t_stack_node **a, t_stack_node **b)
{
	if (*a)
		current_index(*a);
	if (*b)
		current_index(*b);
	if (*a && *b)
		set_target_b(*a, *b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_target.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdiallo <asiya040906@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:45:24 by asdiallo          #+#    #+#             */
/*   Updated: 2025/02/14 18:58:50 by asdiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack_node	*get_target_for_node_b(t_stack_node *node, t_stack_node *a)
{
	long			best_match;
	t_stack_node	*target;
	t_stack_node	*curr_a;

	target = NULL;
	best_match = LONG_MAX;
	curr_a = a;
	while (curr_a)
	{
		if (curr_a->value > node->value && curr_a->value < best_match)
		{
			best_match = curr_a->value;
			target = curr_a;
		}
		curr_a = curr_a->next;
	}
	if (!target)
		return (find_min(a));
	return (target);
}

void	set_target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*curr_b;

	curr_b = b;
	while (curr_b)
	{
		curr_b->target_node = get_target_for_node_b(curr_b, a);
		curr_b = curr_b->next;
	}
}

static t_stack_node	*get_target_for_node(t_stack_node *node, t_stack_node *b)
{
	t_stack_node	*target;
	t_stack_node	*curr_b;
	long			best_match;

	best_match = LONG_MIN;
	curr_b = b;
	target = NULL;
	while (curr_b)
	{
		if (curr_b->value < node->value && curr_b->value > best_match)
		{
			best_match = curr_b->value;
			target = curr_b;
		}
		curr_b = curr_b->next;
	}
	if (!target)
		return (find_max(b));
	return (target);
}

void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*curr_a;

	curr_a = a;
	while (curr_a)
	{
		curr_a->target_node = get_target_for_node(curr_a, b);
		curr_a = curr_a->next;
	}
}

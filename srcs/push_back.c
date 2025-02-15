/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdiallo <asiya040906@gmailc.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:04:58 by asdiallo          #+#    #+#             */
/*   Updated: 2025/02/15 13:08:13 by asdiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	align_a_with_target(t_stack_node **a, t_stack_node *cheapest_node)
{
	t_stack_node	*target;

	if (!a || !*a || !cheapest_node || !cheapest_node->target_node)
		return ;
	target = cheapest_node->target_node;
	while ((*a)->value != target->value)
	{
		if (target->index <= stack_len(*a) / 2)
			ra(a, false);
		else
			rra(a, false);
		current_index(*a);
	}
}

t_stack_node	*find_cheapest_node(t_stack_node *b)
{
	t_stack_node	*cheapest_node;
	int				min_cost;

	if (!b)
		return (NULL);
	cheapest_node = NULL;
	min_cost = INT_MAX;
	while (b)
	{
		if (b->cost < min_cost)
		{
			min_cost = b->cost;
			cheapest_node = b;
		}
		b = b->next;
	}
	return (cheapest_node);
}

void	push_back_to_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	while (*b)
	{
		init_nodes_b(a, b);
		cheapest_node = find_cheapest_node(*b);
		if (!cheapest_node)
			return ;
		align_a_with_target(a, cheapest_node);
		pa(a, b, false);
		update_all_stacks(a, b);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdiallo <asiya040906@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:31:16 by asdiallo          #+#    #+#             */
/*   Updated: 2025/02/14 18:46:43 by asdiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_index(t_stack_node *stack)
{
	int				i;
	int				len;
	int				median;
	t_stack_node	*curr;

	i = 0;
	len = stack_len(stack);
	curr = stack;
	median = len / 2;
	while (curr)
	{
		curr->index = i;
		curr->above_median = (i <= median);
		i++;
		curr = curr->next;
	}
}

void	cost_analysis_a(t_stack_node *a, t_stack_node *b)
{
	int				len_a;
	int				len_b;
	t_stack_node	*curr_a;

	len_a = stack_len(a);
	len_b = stack_len(b);
	curr_a = a;
	while (curr_a)
	{
		if (curr_a->above_median)
			curr_a->cost = curr_a->index;
		else
			curr_a->cost = len_a - curr_a->index;
		if (curr_a->target_node)
		{
			if (curr_a->target_node->above_median)
				curr_a->cost += curr_a->target_node->index;
			else
				curr_a->cost += len_b - curr_a->target_node->index;
		}
		curr_a = curr_a->next;
	}
}

void	set_cheapest(t_stack_node *stack)
{
	t_stack_node	*curr;
	t_stack_node	*cheapest_node;
	long			cheapest_value;

	curr = stack;
	while (curr)
	{
		curr->cheapest = false;
		curr = curr->next;
	}
	cheapest_value = LONG_MAX;
	cheapest_node = NULL;
	curr = stack;
	while (curr)
	{
		if (curr->cost < cheapest_value)
		{
			cheapest_value = curr->cost;
			cheapest_node = curr;
		}
		curr = curr->next;
	}
	if (cheapest_node)
		cheapest_node->cheapest = true;
}

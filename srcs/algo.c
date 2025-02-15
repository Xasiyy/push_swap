/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdiallo <asiya040906@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:18:23 by asdiallo          #+#    #+#             */
/*   Updated: 2024/12/28 01:21:40 by asdiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_stack_node **a, t_stack_node **b)
{
	while (stack_len(*a) > 3)
	{
		init_nodes_a(a, b);
		
		t_stack_node *cheapest_node = NULL;
		t_stack_node *curr = *a;
		while (curr)
		{
			if (curr->cheapest)
			{
				cheapest_node = curr;
				break;
			}
			curr = curr->next;
		}
		if (!cheapest_node)
			return;
		
		prep(a, b, cheapest_node, 'a');
		
		pb(b, a, false);
		
		update_all_stacks(a, b);
	}
}

void	push_back_to_a(t_stack_node **a, t_stack_node **b)
{
	while (*b)
	{
		init_nodes_b(a, b);
		
		t_stack_node *cheapest_node = NULL;
		t_stack_node *curr = *b;
		int min_cost = INT_MAX;
		while (curr) {
			if (curr->cost < min_cost)
			{
				min_cost = curr->cost;
				cheapest_node = curr;
			}
			curr = curr->next;
		}
		if (!cheapest_node)
			return;
		if (cheapest_node->target_node)
		{
			while ((*a)->value != cheapest_node->target_node->value)
			{
				if (cheapest_node->target_node->index <= stack_len(*a) / 2)
					ra(a, false);
				else
					rra(a, false);
				current_index(*a);
			}
		}
		pa(a, b, false);
		update_all_stacks(a, b);
	}
}

void	final_sort(t_stack_node **a)
{
	t_stack_node *min_node;
	int len;

	min_node = find_min(*a);
	if (!min_node)
		return;
	len = stack_len(*a);
	if (min_node->index <= len / 2)
	{
		while (*a != min_node)
		{
			ra(a, false);
			update_all_stacks(a, NULL);
		}
	}
	else
	{
		while (*a != min_node) 
		{
			rra(a, false);
			update_all_stacks(a, NULL);
		}
	}
}

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	push_to_b(a, b);
	sort_three(a);
	push_back_to_a(a, b);
	final_sort(a);
}

void	sort_three(t_stack_node **a)
{
	int	third;
	int	first;
	int	second;

	if (stack_len(*a) != 3)
		return;
	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first < second && second < third)
		return;
	else if (first > second && second < third && first < third)
		sa(a, false);
	else if (first > second && second > third)
	{
		sa(a, false);
		rra(a, false);
	}
	else if (first > second && second < third && first > third)
		ra(a, false);
	else if (first < second && second > third && first < third)
	{
		sa(a, false);
		ra(a, false);
	}
	else if (first < second && second > third && first > third)
		rra(a, false);
}

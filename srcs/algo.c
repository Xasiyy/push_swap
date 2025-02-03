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

t_node *find_min(t_stack *stack)
{
	t_node *current = stack->top;
	t_node *min_node = NULL;

	if (!stack || !stack->top)
	{
		return NULL;
	}

	min_node = current;
	while (current->next && current->next != stack->top)
	{
		current = current->next;
		if (current->value < min_node->value)
			min_node = current;
	}
	return min_node;
}

t_node *find_max(t_stack *stack)
{
	t_node *current;
	t_node *max_node = NULL;

	if (!stack || !stack->top)
		return NULL;

	current = stack->top;
	max_node = current;
	while (current != NULL)
	{
		if (current->value > max_node->value)
			max_node = current;
		current = current->next;
		if (current == stack->top)
			break;
	}
	return max_node;
}


int	is_sorted(t_stack *stack)
{
	t_node *current;

	if (!stack || !stack->top)
		return (true);
	current = stack->top;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	push_to_b(t_stack *a, t_stack *b)
{
	t_node *min_node;

	while (stack_size(a) > 3)
	{
		if (a->top->value > a->top->next->value \
			&& a->top->next->value < a->top->next->next->value \
			&& a->top->value < a->top->next->next->value)
			sa(a);
		min_node = find_min(a);
		prepush(a, min_node, 'a');
		if(is_sorted(a))
			break;
		pb(a, b);
	}
}

void push_back_to_a(t_stack *a, t_stack *b)
{
	while (stack_size(b) > 0)
	{
		t_node *max_node = find_max(b);
		prepush(b, max_node, 'b');
			pa(a, b);
	}
}

void	sort_stack(t_stack *a, t_stack *b)
{
	push_to_b(a, b);
	sort_three(a);
	push_back_to_a(a, b);
}

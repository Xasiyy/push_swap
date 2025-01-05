/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdiallo <asiya040906@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:24:11 by asdiallo          #+#    #+#             */
/*   Updated: 2024/12/28 18:06:56 by asdiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_subset(t_stack *stack)
{
	t_stack *sorted;
	int min_value;

	sorted = init_stack();
	if (!stack || !stack->top)
		return;

	while (stack->top)
	{
		min_value = find_min(stack);
		while (stack->top && stack->top->value != min_value)
			ra(stack);
		if (stack->top)
			pb(stack, sorted);
	}

	while (sorted->top)
		pa(sorted, stack);

	free_stack(&sorted);
}

void	merge_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *result;
	result = init_stack();

	if (!stack_a || !stack_b)
		return;

	while (stack_a->top || stack_b->top)
	{
		if (!stack_a->top)
		{
			pa(stack_b, result);
		}
		else if (!stack_b->top)
		{
			pa(stack_a, result);
		}
		else if (stack_a->top->value <= stack_b->top->value)
		{
			pa(stack_a, result);
		}
		else
		{
			pa(stack_b, result);
		}
	}
	while (result->top)
		pa(result, stack_a);
	free_stack(&result);
}

void	turkish_algo(t_stack *stack_a, t_stack *stack_b)
{
	int i = 0;
	int half = 0;
	t_node *current;

	current = stack_a->top;
	while (current)
	{
		half++;
		current = current->next;
	}
	half /= 2;
	while (i++ < half && stack_a->top)
		pb(stack_a, stack_b);
}

void	turkish_sort(t_stack *stack_a, t_stack *stack_b)
{
	int half = 0;
	int i = 0;
	t_node *current = stack_a->top;

	if (!stack_a || !stack_b || !stack_a->top || !stack_a->top->next)
		return;
	while (current)
	{
		half++;
		current = current->next;
	}
	half /= 2;
	while (i < half && stack_a->top)
	{
		pb(stack_a, stack_b);
		i++;
	}
	sort_subset(stack_a);
	sort_subset(stack_b);
	merge_stacks(stack_a, stack_b);
}

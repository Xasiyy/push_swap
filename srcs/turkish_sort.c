/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdiallo <asiya040906@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:26:45 by asdiallo          #+#    #+#             */
/*   Updated: 2025/01/08 14:26:45 by asdiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_insert_pos(t_stack *stack_b, int value)
{
	int	operations;
	t_node *current;

	operations = 0;
	current = stack_b->top;
	if (!stack_b->top)
		return (1);
	if (!current)
		return (1);
	if (value > current->value)
		return (1);
	while (current->next && current->next->value > value)
		current = current->next;
	if (!current->next)
		operations = 2;
	else
		operations = 2;
	return (operations);
}

int	calcul_sorts(t_stack *stack_b, int value)
{
	int	operations;
	int	max_value;
	int	min_value;

	max_value = find_max(stack_b);
	min_value = find_min(stack_b);
	operations = 0;
	if (value > max_value)
		operations = 1;
	else if (value < min_value)
		operations = 1;
	else
		operations = calculate_insert_pos(stack_b, value);
	return (operations);
}

void	turkish_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	min_operations;
	int	best_value;
	t_node *current;
	int	operations;
	int value;

	while (!is_sorted(stack_a))
	{
		min_operations = -1;
		best_value = 0;
		current = stack_a->top;
		while (current)
		{
			operations = calcul_sorts(stack_b, current->value);
			if (min_operations == -1 || operations < min_operations)
			{
				min_operations = operations;
				best_value = current->value;
			}
			current = current->next;
		}
		if (current && best_value == current->value)
			pb(stack_a, stack_b);
		printf("test\n");
	}
	while (stack_b->top)
	{
		value = stack_b->top->value;
		while (stack_a->top && stack_a->top->value != value)
			ra(stack_a);
		pb(stack_a, stack_b);
	}
}

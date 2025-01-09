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

/* int	calculate_insert_pos(t_stack *stack_b, int value)
{
	int	operations;
	t_node *current;

	if (!stack_b->top)
		return (0);
	operations = 0;
	current = stack_b->top;
	if (value > find_max(stack_b) || value < find_min(stack_b))
	{
		while (current->value != find_min(stack_b))
		{
			current = current->next;
			operations++;
		}
		return (operations);
	}
	while (current->next)
	{
		if (current->value < value && current->next->value > value)
			break;
		current = current->next;
		operations++;
	}
	return (operations);
}

int	calcul_sorts(t_stack *stack_a, t_stack *stack_b, int value)
{
	int cost_a;
	int cost_b;
	t_node *current;

	current = stack_a->top;
	cost_a = 0;
	while (current && current->value != value)
	{
		current = current->next;
		cost_a++;
	}
	cost_b = calculate_insert_pos(stack_b, value);
	if (cost_a > stack_size(stack_a) / 2)
		cost_a = stack_size(stack_a) - cost_a;
	if (cost_b > stack_size(stack_b) / 2)
		cost_b = stack_size(stack_b) - cost_b;
	return (cost_a + cost_b);
}

void	insert_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int pos;

	while (stack_b->top)
	{
		pos = calculate_insert_pos(stack_a, stack_b->top->value);
		if (pos <= stack_size(stack_a) / 2)
		{
			while (pos--)
				ra(stack_a);
		}
		else
		{
			pos = stack_size(stack_a) - pos;
			while (pos--)
				rra(stack_a);
		}
		pa(stack_b, stack_a);
	}
}

void	finalize_sort(t_stack *stack_a)
{
	int min_value;
	int rotations;
	t_node *current;

	rotations = 0;
	if (is_sorted(stack_a))
		return;
	min_value = find_min(stack_a);
	current = stack_a->top;
	while (current && current->value != min_value)
	{
		current = current->next;
		rotations++;
	}
	if (rotations <= (stack_size(stack_a) / 2))
	{
		while (rotations--)
			ra(stack_a);
	}
	else
	{
		rotations = stack_size(stack_a) - rotations;
		while (rotations--)
			rra(stack_a);
	}
}


void	sort_stack_b(t_stack *stack_b)
{
	int	max_value;
	int	rotations;
	t_node *current;

	if (!stack_b->top || !stack_b->top->next)
		return ;
	max_value = find_max(stack_b);
	rotations = 0;
	current = stack_b->top;
	while (current && current->value != max_value)
	{
		current = current->next;
		rotations++;
	}
	if (rotations <= stack_size(stack_b) / 2)
	{
		while (rotations--)
			rb(stack_b);
	}
	else
	{
		rotations = stack_size(stack_b) - rotations;
		while (rotations--)
			rrb(stack_b);
	}
}

void	turkish_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	min_operations;
	int	best_value;
	t_node *current;
	int	operations;

	while (stack_size(stack_a) > 3)
	{
		min_operations = -1;
		best_value = 0;
		current = stack_a->top;
		while (current)
		{
			operations = calcul_sorts(stack_a, stack_b, current->value);
			if (min_operations == -1 || operations < min_operations)
			{
				min_operations = operations;
				best_value = current->value;
			}
			current = current->next;
		}
		while (stack_a->top->value != best_value)
		{
			if (find_position(stack_a, best_value) > stack_size(stack_a) / 2)
				rra(stack_a);
			else
				ra(stack_a);
		}
		pb(stack_a, stack_b);
	}
		sort_three(stack_a);
		insert_to_a(stack_a, stack_b);
		finalize_sort(stack_a);
} */

int	find_position(t_stack *stack, int value)
{
	t_node	*current;
	int		position;

	current = stack->top;
	position = 0;

	while (current)
	{
		if (current->value == value)
			return (position);
		current = current->next;
		position++;
	}

	return (-1);
}

void	push_smallest_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int	min_value;
	int	position;

	while (stack_size(stack_a) > 3)
	{
		min_value = find_min(stack_a);
		position = find_position(stack_a, min_value);
		if (position <= stack_size(stack_a) / 2)
		{
			while (position--)
				ra(stack_a);
		}
		else
		{
			position = stack_size(stack_a) - position;
			while (position--)
				rra(stack_a);
		}
		pb(stack_a, stack_b);
	}
}

int	is_sorted_desc(t_stack *stack)
{
	t_node *current;
	
	if (!stack->top || !stack->top->next)
		return (1);
	current = stack->top;
	while (current->next)
	{
		if (current->value < current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	sort_stack_b_descending(t_stack *stack_b)
{
	int	max_value;
	int	rotations;

	while (!is_sorted_desc(stack_b))
	{
		max_value = find_max(stack_b);
		rotations = find_position(stack_b, max_value);
		if (rotations <= stack_size(stack_b) / 2)
		{
			while (rotations--)
				rb(stack_b);
		}
		else
		{
			rotations = stack_size(stack_b) - rotations;
			while (rotations--)
				rrb(stack_b);
		}
	}
}

void	turkish_sort(t_stack *stack_a, t_stack *stack_b)
{
	push_smallest_to_b(stack_a, stack_b);
	sort_three(stack_a);
	sort_stack_b_descending(stack_b);
	while (stack_b->top)
		pa(stack_b, stack_a);
}
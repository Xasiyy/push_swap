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

int	find_median(t_stack *stack)
{
	t_node	*current;
	int		*values;
	int		size;
	int		median;
	int		i;
	int		j;

	size = 0;
	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	while (current)
	{
		size++;
		current = current->next;
	}
	values = malloc(sizeof(int) * size);
	if (!values)
		return (0);
	current = stack->top;
	i = 0;
	while (i < size)
	{
		values[i] = current->value;
		current = current->next;
		i++;
	}
	i = 0;
	while (i < size - 1)
	{
		int min_idx = i;
		j = i + 1;
		while (j < size)
		{
			if (values[j] < values[min_idx])
				min_idx = j;
			j++;
		}
		int temp = values[i];
		values[i] = values[min_idx];
		values[min_idx] = temp;
	}
	median = values[size / 2];
	free(values);
	return (median);
}

int compare_int(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

void	split_stack(t_stack *stack_a, t_stack *stack_b)
{
	int median;
	int size;
	int i;

	i = 0;
	if (!stack_a || !stack_b || !stack_a->top)
		return ;
	median = find_median(stack_a);
	size = stack_size(stack_a);
	while (i < size)
	{
		if (stack_a->top->value < median)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		i++;
	}
}

void	sort_subset(t_stack *stack)
{
	t_stack *sorted;
	int min_value;

	if (!stack || !stack->top || is_sorted(stack))
		return ;
	sorted = init_stack();
	if (!stack || !stack->top)
		return;

	while (stack->top)
	{
		min_value = find_min(stack);
		while (stack->top && stack->top->value != min_value)
		{
			if (stack->top->value > min_value && stack->top->next->value == min_value)
				sa(stack);
			else
				ra(stack);
		}
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

	if (!stack_a || !stack_b)
		return;
	if (is_sorted(stack_b) && !stack_a->top)
	{
		while (stack_b->top)
			pa(stack_b, stack_a);
		return ;
	}
	result = init_stack();
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
	int i;
	int half;
	t_node *current;

	half = 0;
	i = 0;
	current = stack_a->top;
	if (!stack_a || !stack_b || !stack_a->top || !stack_a->top->next)
		return ;
	if (is_sorted(stack_a))
		return ;
	while (current)
	{
		half++;
		current = current->next;
	}
	half /= 2;
	while (i++ < half && stack_a->top)
	{
		pb(stack_a, stack_b);
		i++;
	}
	sort_subset(stack_a);
	sort_subset(stack_b);
	merge_stacks(stack_a, stack_b);
}

void	turkish_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b || !stack_a->top || !stack_a->top->next)
		return ; 
	split_stack(stack_a, stack_b);
	sort_stack(stack_a);
	sort_subset(stack_b);
	merge_stacks(stack_a, stack_b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdiallo <asiya040906@gmailc.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:18:23 by asdiallo          #+#    #+#             */
/*   Updated: 2024/12/19 19:03:02 by asdiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
    int size;

    if (!stack_a || !stack_b)
        return;
    size = stack_size(stack_a);
    if (size <= 3)
        sort_three(stack_a);
    else if (size <= 50)
        bucket_sort(stack_a, stack_b, 5);
//	else
//		radix_sort(stack_a, stack_b);
}

int	stack_size(t_stack *stack)
{
	int size;
	t_node *current;

	if (!stack)
		return 0;
	current = stack->top;
	size = 0;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}

void	insertion_sort(int *arr, int n)
{
	int i;
	int key;
	int j;

	i = 1;
	while (i < n)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
		i++;
	}
}

int	find_pivot(t_stack *stack)
{
	int size;
	int *value;
	int i;
	t_node *current;
	int pivot;

	size = stack_size(stack);
	if (size == 0)
		return (-1);
	value = malloc(sizeof(int) * stack->size);
	if (!value)
		return (-1);
	current = stack->top;
	i = 0;
	while (current)
	{
		value[i++] = current->value;
		current = current->next;
	}
	insertion_sort(value, stack->size);
	pivot = value[stack->size / 2];
	free (value);
	return (pivot);
}

int	find_min(t_stack *stack)
{
	int min;
	t_node *current;

	if(!stack || !stack->top)
		return (-1);
	min = stack->top->value;
	current = stack->top->next;
	
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

int	find_max(t_stack *stack)
{
	int max;
	t_node *current;
	
	if (!stack || !stack->top)
		return (-1);
	max = stack->top->value;
	current = stack->top->next;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

int	partition_stack(t_stack *a, t_stack *b, int pivot)
{
	int rotation;
	int size;
	int i;

	rotation = 0;
	i = 0;
	size = stack_size(a);
	while (i < size && a->top)
	{
		if (a->top->value < pivot)
			pb(a, b);
		else
		{
			ra(a);
			rotation++;
		}
		i++;
	}
	while (rotation > 0)
	{
		rra(a);
		rotation--;
	}
	return (pivot);
}

void	quicksort(t_stack *a, t_stack *b)
{
	int pivot;

	if (stack_size(a) <= 1 || is_sorted(a))
		return ;
	pivot = find_pivot(a);
	partition_stack(a, b, pivot);
	quicksort(a, b);
	quicksort(b, a);
	while (stack_size(b) > 0)
		pa(a, b);
		
}

/* void	bucket_sort(t_stack *a, t_stack *b, int stack_count)
{
	int min; 
	int max;
	int range;
	int bucket_min;
	int bucket_max;
	int size;
	int j;
	int i;

	i = 0;
	max = find_max(a);
	min = find_min(a);
	range = (max - min + 1) / stack_count;
	if (is_sorted(a))
		return ;
	while (i < stack_count)
	{
		bucket_min = min + i * range;
		bucket_max = bucket_min + range - 1;
		size = stack_size(a);
		j = 0;
		while (j < size)
		{
			if(a->top->value >= bucket_min && a->top->value <= bucket_max)
				pb(a, b);
			else
				ra(a);
			j++;
		}
		quicksort(b, a);
		while (stack_size(b) > 0)
			pa(a, b);
		i++;
	}
} */

void	restore_stack(t_stack *stack, int rotations)
{
	while (rotations > 0)
	{
		rra(stack);
		rotations--;
	}
}

int	is_sorted(t_stack *stack)
{
	t_node *current;

	current = stack->top;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}		
	return (1);
}

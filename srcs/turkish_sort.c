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

int	stack_size(t_stack *stack)
{
	int	size;
	t_node *current;

	size = 0;
	current = stack->top;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}
int	find_max_index(t_stack *stack)
{
	t_node	*current;
	int		max;
	int		index;
	int		max_index;

	current = stack->top;
	max = current->value;
	index = 0;
	max_index = 0;
	while (current)
	{
		if (current->value > max)
		{
			max = current->value;
			max_index = index;
		}
		current = current->next;
		index++;
	}
	return (max_index);
}

void	rotate_to_top(t_stack *stack, int index)
{
	int	size;

	size = stack_size(stack);
    if (index < 0 || index >= size)
        return;
    if (index <= size / 2)
    {
        while (index-- > 0)
            ra(stack);
    }
    else
    {
        index = size - index;
        while (index-- > 0)
            rra(stack);
    }
}

void	sort_values(int *values, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (values[j] > values[j + 1])
			{
				temp = values[j];
				values[j] = values[j + 1];
				values[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int	*get_sorted_values(t_stack *stack)
{
	t_node *current;
	int		*values;
	int		size;
	int		i;

	size = stack_size(stack);
	if (size <= 0)
		return (NULL);

	values = malloc(sizeof(int) * size);
	if (!values)
		return (NULL);
	current = stack->top;
	i = 0;
	while (current)
	{
		values[i++] = current->value;
		current = current->next;
	}
	sort_values(values, size);
	return (values);
}

void	split_stack(t_stack *stack_a, t_stack *stack_b, int num_chunks)
{
	int *sorted_value;
	int	chunk_size;
	int	i;
	int count;

	if (!stack_a || !stack_a->top)
		return ;
	sorted_value = get_sorted_values(stack_a);
	if (!sorted_value)
		return;
	chunk_size = (stack_size(stack_a) + num_chunks - 1) / num_chunks;
	i = 0;
	while (stack_a->top)
	{
		if (i < num_chunks && stack_a->top->value <= sorted_value[chunk_size * (i + 1) - 1])
		{
			pb(stack_a, stack_b);
			if (stack_b->top->value <= sorted_value[chunk_size * i])
				rb(stack_b);
			count = 0;
		}
		else
		{
			ra(stack_a);
			count++;
		}	
		if (count >= stack_size(stack_a))
			break;
		if (stack_size(stack_b) >= chunk_size * (i + 1))
			i++;
	}
	free(sorted_value);
}

void	merge_stacks(t_stack *stack_a, t_stack *stack_b)
{
	int	max_index;

	if (!stack_b || !stack_b->top)
		return;
	while (stack_b->top)
	{
		max_index = find_max_index(stack_b);
		rotate_to_top(stack_b, max_index);
		pa(stack_b, stack_a);
	}
}

int	find_chunks(int	stack_size)

{
	if (stack_size <= 10)
        return 2;
    else if (stack_size <= 100)
        return 7;
    else if (stack_size <= 500)
        return 15;
    else
        return 30;
}

void sort_three(t_stack *stack)
{
    int top = stack->top->value;
    int middle = stack->top->next->value;
    int bottom = stack->top->next->next->value;

    if (top > middle && middle > bottom)
    {
        sa(stack);
        rra(stack);
    }
    else if (top > bottom && bottom > middle)
        ra(stack);
    else if (middle > bottom && bottom > top)
    {
        sa(stack);
        ra(stack);
    }
    else if (middle > top && top > bottom)
        rra(stack);
    else if (bottom > top && top > middle)
        sa(stack);
}

void	turkish_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	num_chunks;

	if (is_sorted(stack_a) || stack_size(stack_a) <= 1)
		return ;
	if (stack_size(stack_a) <= 3)
	{
		sort_three(stack_a);
		return ;
	}
	num_chunks = find_chunks(stack_size(stack_a));
	split_stack(stack_a, stack_b, num_chunks);
	merge_stacks(stack_a, stack_b);
}

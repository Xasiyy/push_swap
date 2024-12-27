/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdiallo <asiya040906@gmailc.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:24:11 by asdiallo          #+#    #+#             */
/*   Updated: 2024/12/27 10:57:30 by asdiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	max_value;
	int num_bits;
	int size;
	int i;
	int j;
	int rotations;
	int min_value;
	t_node *current;

	max_value = find_max(stack_a);
	num_bits = 0;
	while ((max_value >> num_bits) != 0)
		num_bits++;
	while(!is_sorted(stack_a))
	{
		i = 0;
		while (i < num_bits)
		{
			size = stack_size(stack_a);
			j = 0;
			while (j < size)
			{
				if (((stack_a->top->value >> i) & 1) == 1)
					ra(stack_a);
				else
					pb(stack_a, stack_b);
				j++;
			}
			while (stack_size(stack_b) > 1 && stack_b->top->value < stack_b->top->next->value)
				sb(stack_b);
			while (stack_size(stack_b) > 0)
				pa(stack_b, stack_a);
			i++;
		}
		rotations = 0;
		min_value = find_min(stack_a);
		current = stack_a->top;
		while (current)
		{
			if (current->value == min_value)
				break;
			rotations++;
			current = current->next;
		}
		if (rotations <= stack_size(stack_a) / 2)
		{
			while (rotations-- > 0)
				ra(stack_a);
		}
		else
		{
			rotations = stack_size(stack_a) - rotations;	
			while (rotations-- > 0)
				rra(stack_a);
		}
	}
}

#include "push_swap.h"

/* void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
    int	max_value;
    int num_bits;
    int size;
    int i;
    int j;
	int rotations;
	int min_value;
	t_node *current;

    if (is_sorted(stack_a))
        return;

    max_value = find_max(stack_a);
    num_bits = 0;
    while ((max_value >> num_bits) != 0)
        num_bits++;
    i = 0;
    while (i < num_bits)
    {
        size = stack_size(stack_a);
        j = 0;
        while (j < size)
        {
            if (((stack_a->top->value >> i) & 1) == 1)
                ra(stack_a);
            else
                pb(stack_a, stack_b);
            j++;
        }
        while (stack_size(stack_b) > 0)
            pa(stack_b, stack_a);
        i++;
    }
	rotations = 0;
	min_value = find_min(stack_a);
	current = stack_a->top;
	while (current)
	{
		if(current->value == min_value)
			break;
		rotations++;
		current = current->next;
	}
	if(rotations <= stack_size(stack_a) / 2)
	{
		while (rotations-- > 0)
			ra(stack_a);
	}
	else
	{
		rotations = stack_size(stack_a) - rotations;
		while (rotations-- > 0)
			rra(stack_a);
	}
} */

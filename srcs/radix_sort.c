/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdiallo <asiya040906@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:24:11 by asdiallo          #+#    #+#             */
/*   Updated: 2024/12/20 14:07:08 by asdiallo         ###   ########.fr       */
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
		{
			pa(stack_b, stack_a);
		}
		i++;
	}
	while (!is_sorted(stack_a))
	{
		rra(stack_a);
	}
}

/* void radix_sort(t_stack *stack_a, t_stack *stack_b)
{
    int max_value;
    int num_bits;
    int size;
    int i;
    int j;

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
            pa(stack_a, stack_b);
        i++;
    }
} */
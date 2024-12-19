/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdiallo <asiya040906@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:51:01 by asdiallo          #+#    #+#             */
/*   Updated: 2024/12/19 17:24:10 by asdiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bucket_sort(t_stack *stack_a, t_stack *stack_b, int bucket_count)
{
	int min;
	int max;
	int range;
	int bucket_min;
	int bucket_max;
	int i;
	int j;
	int size;

	if (!stack_a || !stack_b || is_sorted(stack_a))
		return ;
	min = find_min(stack_a);
	max = find_max(stack_a);
	if (bucket_count <= 0 || (max - min + 1) < bucket_count)
		range = 1;
	else
		range = (max - min + 1) / bucket_count;
	i = 0;
	while (i < bucket_count)
	{
		bucket_min = min + i * range;
		bucket_max = bucket_min + range - 1;
		if (i == bucket_count - 1)
			bucket_max = max;
		size = stack_size(stack_a);
		j = 0;
		while (j < size)
		{
			if (stack_a->top->value >= bucket_min && stack_a->top->value <= bucket_max)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
			j++;
		}
		if (stack_size(stack_b) > 0)
		{
			if (stack_size(stack_b) <= 3)
				sort_three(stack_b);
			else
				quicksort(stack_b, stack_a);
			while (stack_size(stack_b) > 0)
				pa(stack_a, stack_b);
		}
		i++;
	}
}

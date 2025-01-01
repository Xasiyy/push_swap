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

//1080 appels pour 100
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
	if(!is_sorted(stack_a))
	{
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
} */
//1340 appels pour 100
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
			{
				if(stack_size(stack_b) > 1 && ((stack_b->top->value >> i) & 1) == 1)
					rr(stack_a, stack_b);
				else
					ra(stack_a);
			}
            else
                pb(stack_a, stack_b);
            j++;
        }
        while (stack_size(stack_b) > 0)
		{
            if (stack_size(stack_b) > 1 && stack_b->top->value < stack_b->top->next->value)
			{
				if (stack_size(stack_b) > 1 && stack_b->top->value < stack_b->top->next->value)
					ss(stack_a, stack_b);
				else
					sb(stack_b);
			}
			pa(stack_b, stack_a);
		}
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
		{
			if (stack_size(stack_b) > 1)
				rr(stack_a, stack_b);
			else
				ra(stack_a);
		}
	}
	else
	{
		rotations = stack_size(stack_a) - rotations;
		while (rotations-- > 0)
		{
			if (stack_size(stack_b) > 1)
				rrr(stack_a, stack_b);
			else
				rra(stack_a);	
		}
	}
} */

void	sort_subset(t_stack *stack)
{
	t_stack sorted;
	init_stack(&sorted);
	int min_value;

    if (!stack || !stack->top)
		return ;
	while (stack_size(stack) > 0)
	{
		min_value = find_min(stack);
		while (stack->top && stack->top->value != min_value)
			ra(stack);
		if(stack->top)
			pb(stack, &sorted);
	}
	while (stack_size(&sorted) > 0)
		pa(&sorted, stack);
	free_stack(&sorted);
}

void	merge_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_stack result;
	init_stack(&result);

    if (!stack_a || !stack_b)
        return;
    while (stack_size(stack_a) > 0 || stack_size(stack_b) > 0)
	{
        if (stack_size(stack_a) == 0)
        {
            printf("stack_a vide, pa depuis stack_b\n");
            pa(stack_b, &result);
        }
        else if (stack_size(stack_b) == 0)
        {
            printf("stack_b vide, pa depuis stack_a\n");
            pa(stack_a, &result);
        }
        else if (stack_a->top->value <= stack_b->top->value)
        {
            printf("pa depuis stack_a\n");
            pa(stack_a, &result);
        }
        else
        {
            printf("pa depuis stack_b\n");
            pa(stack_b, &result);
        }
    }
	while (stack_size(&result) > 0)
		pa(&result, stack_a);
	free_stack(&result);
}

void	turkish_algo(t_stack *stack_a, t_stack *stack_b)
{
	int i;
	int	half;

	i = 0;
	half = stack_size(stack_a) / 2;
	while (i++ < half)
		pb(stack_a, stack_b);
	
}

void	turkish_sort(t_stack *stack_a, t_stack*stack_b)
{
	int half;
	int i;

	if (!stack_a || !stack_b || stack_size(stack_a) <= 1)
    	return ;
	i = 0;
	half = stack_size(stack_a) / 2;
	while (i < half && stack_a->top)
	{
    	printf("Avant pb : stack_a->size = %d, stack_b->size = %d\n", stack_a->size, stack_b->size);
		pb(stack_a, stack_b);
	    printf("Après pb : stack_a->size = %d, stack_b->size = %d\n", stack_a->size, stack_b->size);
		i++;
	}
	sort_subset(stack_a);
	sort_subset(stack_b);
	merge_stacks(stack_a, stack_b);
}
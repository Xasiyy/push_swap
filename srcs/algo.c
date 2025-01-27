/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdiallo <asiya040906@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:18:23 by asdiallo          #+#    #+#             */
/*   Updated: 2024/12/28 01:21:40 by asdiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_node *find_min(t_stack *stack)
{
    t_node *current = stack->top;
    t_node *min_node = NULL;

    if (!stack || !stack->top)
	{
		printf("\nla pile est vide");
        return NULL;
	}

    min_node = current;
    while (current->next && current->next != stack->top)
    {
		current = current->next;
        if (current->value < min_node->value)
            min_node = current;
    }
    return min_node;
}

t_node *find_max(t_stack *stack)
{
    t_node *current;
    t_node *max_node = NULL;
    
    if (!stack || !stack->top)
		return NULL;

	current = stack->top;
    max_node = current;
    while (current != NULL)
    {
        if (current->value > max_node->value)
            max_node = current;
        current = current->next;
		if (current == stack->top)
			break;
    }
    return max_node;
}

int	is_sorted(t_stack *stack)
{
	t_node *current;

	if (!stack || !stack->top)
		return (1);
	current = stack->top;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}		
	return (1);
}

t_node *find_cheapest_node(t_stack *stack)
{
	t_node *current;
	t_node *cheapest;
	t_node *last_node = stack->top->prev;
	int min_cost;

	if (!stack || !stack->top)
		return (NULL);
	current = stack->top;
	cheapest = NULL;
	min_cost = INT_MAX;
	while (current != last_node)
	{
		if (current->push_cost < min_cost)
		{
			min_cost = current->push_cost;
			cheapest = current;
		}
		current = current->next;
	}
	return (cheapest);
}

void	push_to_b(t_stack *a, t_stack *b)
{
	t_node *min_node;

	while (stack_size(a) > 3)
	{
		min_node = find_min(a);
        printf("Pushing %d from A to B\n", min_node->value);
		prepush(a, min_node, 'a');
		pb(a, b);
		print_stack(a);
		print_stack(b);
	}
}

void push_back_to_a(t_stack *a, t_stack *b)
{
	while (stack_size(b) > 0)
	{
		t_node *max_node = find_max(b);
		prepush(b, max_node, 'b');
			pa(a, b);
	}
}

void	sort_stack(t_stack *a, t_stack *b)
{
	t_node *min_node;

	push_to_b(a, b);
	sort_three(a);
	push_back_to_a(a, b);
	while (!is_sorted(a))
	{
		min_node = find_min(a);
        printf("Pushing %d from A to B\n", min_node->value);
		prepush(a, min_node, 'a');
	}
}

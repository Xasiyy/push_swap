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
        return NULL;

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
    t_node *current = stack->top;
    t_node *max_node = NULL;
    
    if (!stack || !stack->top)
        return NULL;

    max_node = current;
    while (current)
    {
        if (current->value > max_node->value)
            max_node = current;
        current = current->next;
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
	t_node *first_node = stack->top;
	int min_cost;

	if (!stack || !stack->top)
		return (NULL);
	current = stack->top;
	cheapest = NULL;
	min_cost = INT_MAX;
	while (current != first_node)
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
void	sort_stack(t_stack *a, t_stack *b)
{
	t_node *cheapest_node;

	while (stack_size(b) > 0)
	{
		calcul_nodes_a(a, b);
		cheapest_node = find_cheapest_node(a);
		prepush(b, cheapest_node->target, 'b');
		pa(a, b);
	}
	while (!is_sorted(a))
	{
		cheapest_node  = find_cheapest_node(a);
		prepush(a, cheapest_node->target, 'a');
		ra(a);
	}
}

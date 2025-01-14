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

void finalize_sort(t_stack *stack_a)
{
    int min_value = find_min(stack_a);
    int rotations = find_position(stack_a, min_value);

    printf("Min value: %d, Rotations needed: %d\n", min_value, rotations);

    if (rotations == -1)
    {
        fprintf(stderr, "Erreur : impossible de trouver la valeur minimale dans la pile\n");
        return;
    }

    if (rotations <= stack_size(stack_a) / 2)
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

    if (!is_sorted(stack_a))
    {
        fprintf(stderr, "Erreur : la pile A n'est pas triée après finalize_sort\n");
        print_stack(stack_a);
    }
}


void align_stack_a(t_stack *stack_a, int position)
{
    int size = stack_size(stack_a);

    if (position <= size / 2)
    {
        while (position--)
            ra(stack_a);
    }
    else
    {
        position = size - position;
        while (position--)
            rra(stack_a);
    }
}

int calculate_insert_pos(t_stack *stack_a, int value)
{
    t_node *current = stack_a->top;
    int position = 0;

    if (!current || value < find_min(stack_a) || value > find_max(stack_a))
    {
        while (current && current->value != find_min(stack_a))
        {
            current = current->next;
            position++;
        }
        return position;
    }
    while (current->next)
    {
        if (current->value < value && current->next->value > value)
            break;
        current = current->next;
        position++;
    }

    return position + 1;
}

int max(int a, int b)
{
    return (a > b ? a : b);
}

int calcul_sorts(t_stack *stack_a, t_stack *stack_b, int value)
{
    int cost_a = find_position(stack_a, value);
    int cost_b = calculate_insert_pos(stack_b, value);

    if (cost_a > stack_size(stack_a) / 2)
        cost_a = cost_a - stack_size(stack_a);
    if (cost_b > stack_size(stack_b) / 2)
        cost_b = cost_b - stack_size(stack_b);

    if ((cost_a > 0 && cost_b > 0) || (cost_a < 0 && cost_b < 0))
        return (max(abs(cost_a), abs(cost_b)));
    else
        return (abs(cost_a) + abs(cost_b));

}


void align_stacks(t_stack *stack_a, t_stack *stack_b, int pos_a, int pos_b)
{
    while (pos_a > 0 && pos_b > 0)
    {
        rr(stack_a, stack_b);
        pos_a--;
        pos_b--;
    }
    while (pos_a < 0 && pos_b < 0)
    {
        rrr(stack_a, stack_b);
        pos_a++;
        pos_b++;
    }
    while (pos_a > 0)
    {
        ra(stack_a);
        pos_a--;
    }
    while (pos_a < 0)
    {
        rra(stack_a);
        pos_a++;
    }
    while (pos_b > 0)
    {
        rb(stack_b);
        pos_b--;
    }
    while (pos_b < 0)
    {
        rrb(stack_b);
        pos_b++;
    }
}
void turkish_sort(t_stack *stack_a, t_stack *stack_b)
{
    pb(stack_a, stack_b);
    pb(stack_a, stack_b);

    while (stack_size(stack_a) > 3)
    {
        int best_value = 0;
        int best_cost = -1;
        t_node *current = stack_a->top;

        while (current)
        {
            int current_cost = calcul_sorts(stack_a, stack_b, current->value);
            if (best_cost == -1 || current_cost < best_cost)
            {
                best_cost = current_cost;
                best_value = current->value;
            }
            current = current->next;
        }

        align_stack_a(stack_a, find_position(stack_a, best_value));
        pb(stack_a, stack_b);
    }

    sort_three(stack_a);

    while (stack_b->top)
    {
        int insert_pos = calculate_insert_pos(stack_a, stack_b->top->value);
        align_stack_a(stack_a, insert_pos);
        pa(stack_b, stack_a);
    }

    finalize_sort(stack_a);
}

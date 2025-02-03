/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdiallo <asiya040906@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:44:56 by asdiallo          #+#    #+#             */
/*   Updated: 2024/12/02 21:08:43 by asdiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// prepush B to A

// void	compare_node_b(t_stack *a, t_stack *b)
// {
// 	t_node *current_a;
// 	t_node *node;
// 	t_node *current_b;
// 	long index;

// 	if (!a || !b || !a->top || !b->top)
// 		return;
// 	current_b = b->top;
// 	while (current_b)
// 	{
// 		current_a = a->top;
// 		node = NULL;
// 		index = LONG_MAX;
// 		while (current_a)
// 		{
// 			if (current_a->value > current_b->value && current_a->value < index)
// 			{
// 				index = current_a->value;
// 				node = current_a;
// 			}
// 			current_a = current_a->next;
// 		}
// 		if (index == LONG_MAX)
// 			current_b->target = find_min(a);
// 		else
// 			current_b->target = node;
// 		current_b = current_b->next;
// 	}
// }

// void	calcul_node_b(t_stack *a, t_stack *b)
// {
// 	if (!a || !b)
// 		return;
// 	find_index(a);
// 	find_index(b);
// 	compare_node_b(a, b);
// }


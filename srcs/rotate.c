/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdiallo <asiya040906@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:25:31 by asdiallo          #+#    #+#             */
/*   Updated: 2024/12/28 18:04:13 by asdiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (!stack || !*stack || !((*stack)->next))
		return ;
	first = *stack;
	*stack = first->next;
	(*stack)->prev = NULL;
	last = find_last(*stack);
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	ra(t_stack_node **a, bool print)
{
	rotate(a);
	if (!print)
		printf("ra\n");
}

void	rb(t_stack_node **b, bool print)
{
	rotate(b);
	if (!print)
		printf("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b, bool print)
{
	ra(a, true);
	rb(b, true);
	if (!print)
		printf("rr\n");
}

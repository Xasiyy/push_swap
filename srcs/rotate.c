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

void	rotate(t_stack *stack)
{
	t_node *first;
	t_node *last;
	if (!stack || !stack->top || !stack->top->next)
		return ;
	first = stack->top;
	last = stack->top;
	while (last->next)
		last = last->next;
	stack->top = first->next;
	stack->top->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	printf("rotation fait top = %d\n", stack->top->value);
}

void	ra(t_stack *stack_a)
{
	if (!stack_a || !stack_a->top || !stack_a->top->next)
        return;
	count++;
	write (1, "ra\n", 3);
	rotate (stack_a);
}

void	rb(t_stack  *stack_b)
{
	if  (!stack_b || !stack_b->top || !stack_b->top->next)
		return ;
	count++;
	write (1, "rb\n", 3);
	rotate (stack_b);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	if ((!stack_b || !stack_b->top || !stack_a->top->next) && \
		(!stack_b || !stack_b->top || !stack_b->top->next))
		return ;
	count++;
	write (1, "rr\n", 3);
	if (stack_a && stack_a->top && stack_a->top->next)
		rotate (stack_a);
	if (stack_b && stack_b->top && stack_b->top->next)
		rotate (stack_b);
}

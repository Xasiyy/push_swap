/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdiallo <asiya040906@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:25:31 by asdiallo          #+#    #+#             */
/*   Updated: 2024/12/08 21:16:21 by asdiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack)
{
	t_node *first;
	t_node *last;
	if (stack->top == NULL || stack->top->next == NULL)
		return ;
	first = stack->top;
	last = stack-top->prev;
	stack->top = first->next;
	stack->top->prev = last;
	last->next = first->next;
	stack->top->prev = last;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	last->next = first;
}

void	ra(t_stack *stack_a)
{
	write (1, "ra\n", 3);
	rotate (stack_a);
}

void	rb(t_stack  *stack_b)
{
	write (1, "rb\n", 3);
	rotate (stack_b);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	write (1, "rr\n", 3);
	rotate (stack_a);
	rotate (stack_b);
}
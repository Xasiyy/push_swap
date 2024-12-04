/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdiallo <asiya040906@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:02:23 by asdiallo          #+#    #+#             */
/*   Updated: 2024/12/04 12:13:01 by asdiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_node *first;
	t_node *second;
	
	if (stack->top && stack->top->next && stack->top != stack->top->next)
	{
		first = stack->top;
		second = stack->top->next;
		fisrt->next = second->next;
		second->next->prev = first;
		second->next = first;
		second->prev = fisrt->prev;
		first->prev->next = second;
		first->prev = second;
		stack->top = second;
	}
}

void	sa(t_stack *stack_a)
{
	write (1, "sa\n", 3);
	swap(stack_a);
}

void	sb(t_stack *stack_b)
{
	write (1, "sb\n", 3);
	swap (stack_b);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	write (1, "ss\n", 3);
	swap (stack_a);
	swap (stack_b);
}
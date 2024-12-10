/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdiallo <asiya040906@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 21:17:02 by asdiallo          #+#    #+#             */
/*   Updated: 2024/12/09 13:54:39 by asdiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse(t_stack *stack)
{
	t_node *last;
	t_node *second_last;
		
	if (stack->top == NULL || stack->top->next == NULL)
		return ;
	last = stack->top;
	second_last = NULL;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = stack->top;
	stack->top->prev = last;
	stack->top = last;
	stack->top->prev = NULL;
}

void	rra(t_stack *stack_a)
{
	write (1, "rra\n", 4);
	reverse(stack_a);
}

void	rrb(t_stack *stack_b)
{
	write (1, "rrb\n", 4);
	reverse(stack_b);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	write (1, "rrr\n", 4);
	reverse(stack_a);	
	reverse(stack_b);
}

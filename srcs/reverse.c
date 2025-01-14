/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdiallo <asiya040906@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 21:17:02 by asdiallo          #+#    #+#             */
/*   Updated: 2024/12/23 15:15:38 by asdiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse(t_stack *stack)
{
	t_node *last;
	t_node *second_last;
		
	if (!stack || !stack->top || !stack->top->next)
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
	if (!stack_a || !stack_a->top || !stack_a->top->next)
        return;
	write (1, "rra\n", 4);
	reverse(stack_a);
	count++;
}

void	rrb(t_stack *stack_b)
{
	if (!stack_b || !stack_b->top || !stack_b->top->next)
		return ;
	write (1, "rrb\n", 4);
	reverse(stack_b);
	count++;
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	write (1, "rrr\n", 4);
	reverse(stack_a);	
	reverse(stack_b);
	count++;
}

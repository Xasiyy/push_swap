/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdiallo <asiya040906@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:28:02 by asdiallo          #+#    #+#             */
/*   Updated: 2024/12/06 16:56:04 by asdiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack)
{
	t_node *move_node;
	
	if (src->top == NULL)
		return ;
	move_node = src->top;
	src->top = src->top->next;
	if (src->top != NULL)
		src->top->prev = move_node->prev;
	if (dest->top == NULL)
	{
		move_node->next = NULL;
		move_node->prev = NULL;
		dest->top = move_node;
	}
	else
	{
		move_node->next = dest->top;
		move_node->prev = dest->top->prev;
		dest->top->prev = move_node;
		dest->top = move_node;
	}
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	write (1, "pa\n", 3)
	push(stack_a);
}

void	pb(t_stack *staack_a, t_stack *stack_b)
{
	write(1, "pb\n", 3);
	push(stack_b);
}

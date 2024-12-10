/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdiallo <asiya040906@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:28:02 by asdiallo          #+#    #+#             */
/*   Updated: 2024/12/09 13:53:57 by asdiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *src, t_stack *dest)
{
	t_node *move_node;
	
	if (src->top == NULL)
		return ;
	move_node = src->top;
	src->top = src->top->next;
	if (src->top != NULL)
		src->top->prev = NULL;
	move_node->next = dest->top;
	if (dest->top != NULL)
		dest->top = move_node;
	dest->top = move_node;
	dest->top->prev = NULL;
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	write (1, "pa\n", 3);
	push(stack_a, stack_b);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	write(1, "pb\n", 3);
	push(stack_b, stack_a);
}

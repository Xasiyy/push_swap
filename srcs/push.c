/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdiallo <asiya040906@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:28:02 by asdiallo          #+#    #+#             */
/*   Updated: 2024/12/23 15:16:06 by asdiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *src, t_stack *dest)
{
	t_node *move_node;
	
	if (!src || !src->top)
		return ;
	move_node = src->top;
	src->top = src->top->next;
	if (src->top)
		src->top->prev = NULL;
	move_node->next = dest->top;
	if (dest->top)
		dest->top->prev = move_node;
	dest->top = move_node;
	src->size--;
	dest->size++;
}

void	pa(t_stack *stack_b, t_stack *stack_a)
{
	if (!stack_b || !stack_b->top)
	{
		printf("vide\n");
		return ;
	}
	count++;
	write (1, "pa\n", 3);
	push(stack_b, stack_a);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_a->top)
		return ;
	count++;
	write(1, "pb\n", 3);
	push(stack_a, stack_b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdiallo <asiya040906@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:28:02 by asdiallo          #+#    #+#             */
/*   Updated: 2024/12/31 23:00:10 by asdiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *src, t_stack *dest)
{
	t_node *move_node;
	
    printf("Avant push : src = %p, dest = %p\n", (void *)src, (void *)dest);
    printf("src->size = %d, dest->size = %d\n", src->size, dest->size);
	if (!src || !src->top)
		return ;
	move_node = pop(src);
	if (!dest->top)
		dest->top = move_node;
	else
	{
		move_node->next = dest->top;
		dest->top->prev = move_node;
		dest->top = move_node;
	}
	dest->size++;
    printf("Après push : src->size = %d, dest->size = %d\n", src->size, dest->size);
    printf("dest->top->value = %d\n", dest->top->value);
}

void	pa(t_stack *stack_b, t_stack *stack_a)
{
	if (!stack_b || !stack_b->top)
	{
		printf("vide\n");
		return ;
	}
	write (1, "pa\n", 3);
	push(stack_b, stack_a);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_a->top)
	{
        printf("Erreur : pb appelé sur une pile vide (stack_a).\n");    
		return ;
	}
	write(1, "pb\n", 3);
	printf("Avant pb : stack_a->top = %d, stack_a->size = %d, stack_b->size = %d\n", stack_a->top->value, stack_a->size, stack_b->size);	push(stack_a, stack_b);
    printf("Après pb : stack_b->top = %d, stack_b->size = %d\n", stack_b->top->value, stack_b->size);
}	

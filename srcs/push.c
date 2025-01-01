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
	
	if (!src || !src->top)
		return ;
	move_node = src->top;
    printf("Push : Déplacement de %d de src à dest\n", move_node->value);
    printf("Avant push : src->top = %p, src->size = %d, dest->size = %d\n", src->top, src->size, dest->size);
	src->top = src->top->next;
	if (src->top)
		src->top->prev = NULL;
	src->size--;
	move_node->next = dest->top;
	if (dest->top)
		dest->top->prev = move_node;
	dest->top = move_node;
	dest->top->prev = NULL;
	dest->size++;
    if (src->size < 0 || dest->size < 0)
    {
        printf("Erreur : Taille invalide après le push. src->size = %d, dest->size = %d\n", src->size, dest->size);
    }
    printf("Après push : src->top = %p, src->size = %d, dest->top = %p, dest->size = %d\n", src->top, src->size, dest->top, dest->size);
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

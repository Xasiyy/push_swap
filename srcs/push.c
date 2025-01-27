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
	move_node = pop(src);
	if (!dest->top)
		dest->top = move_node;
	else
	{
		move_node->next = dest->top;
		dest->top->prev = move_node;
		dest->top = move_node;
	}
}
// void	pa(t_stack *stack_b, t_stack *stack_a)
// {
// 	if (!stack_b || !stack_b->top)
// 		return ;
// 	write (1, "pa\n", 3);
// 	push(stack_b, stack_a);
// 	count++;
// }
// 

void pa(t_stack *stack_a, t_stack *stack_b)
{
    if (!stack_b || !stack_b->top) // Vérifie si stack_b est vide ou NULL
        return;

    t_node *temp = stack_b->top;  // Récupère le sommet de stack_b

    // Déplace le sommet de stack_b vers stack_a
    stack_b->top = stack_b->top->next;  // Le sommet de stack_b est maintenant le suivant
    temp->next = stack_a->top;  // L'élément déplacé pointe maintenant vers le sommet de stack_a
    stack_a->top = temp;  // Le sommet de stack_a devient l'élément déplacé

    write(1, "pa\n", 3);  // Affiche l'instruction "pa"
}


void	pb(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_a->top)
		return ;
	write(1, "pb\n", 3);
	push(stack_a, stack_b);
	count++;
}	

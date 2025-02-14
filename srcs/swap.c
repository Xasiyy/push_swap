/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdiallo <asiya040906@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:02:23 by asdiallo          #+#    #+#             */
/*   Updated: 2024/12/23 15:15:16 by asdiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_stack(t_stack_node **top)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (!top || !*top || !((*top)->next))
		return ;
	first = *top;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*top = second;
}

void	sa(t_stack_node **a, bool print)
{
	swap_stack(a);
	if (!print)
		printf("sa\n");
}

void	sb(t_stack_node **b, bool print)
{
	swap_stack(b);
	if (!print)
		printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b, bool print)
{
	swap_stack(a);
	swap_stack(b);
	if (!print)
		printf("ss\n");
}

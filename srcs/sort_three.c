/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdiallo <asiya040906@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:18:32 by asdiallo          #+#    #+#             */
/*   Updated: 2024/12/19 11:40:44 by asdiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *stack)
{
	int top;
	int middle;
	int bottom;

	if (stack_size(stack) != 3)
		return ;
	top = stack->top->value;
	middle = stack->top->next->value;
	bottom = stack->top->next->next->value;
	if (top > middle && middle < bottom && top < bottom)
		sa(stack);
	else if (top > middle && middle > bottom && top > bottom)
	{
		sa(stack);
		rra(stack);
	}
	else if (top > middle && middle < bottom && top < bottom)
		ra(stack);
	else if (top < middle && middle > bottom && top < bottom)
	{
		sa(stack);
		ra(stack);
	}
	else if (top < middle && middle > bottom && top > bottom)
		rra(stack);
}

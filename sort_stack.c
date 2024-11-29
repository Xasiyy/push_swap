/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdiallo <asiya040906@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:18:20 by asdiallo          #+#    #+#             */
/*   Updated: 2024/11/28 17:18:37 by asdiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int initStack(t_stack *stack, int capacity)
{
	stack->data = (int *)malloc(capacity * sizeof(int));
	if (!stack->data)
		return (0);
	stack->top = -1;
	stack->capacity = capacity;
	return (1);
}

int pop(t_stack *stack)
{
    if(stack -> top == -1)
        return (-1);
	return (stack -> data[stack -> top--]);
}

int peek(t_stack *stack)
{
    if(stack -> top == -1)
		return (-1);
	return (stack -> data[stack -> top]);
}

int isEmpty(t_stack* stack)
{
	return (stack->top == -1);
}

int is_full(t_stack* stack)
{
	return (stack->top == MAX - 1);
}
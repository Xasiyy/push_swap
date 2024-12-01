/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdiallo <asiya040906@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:18:20 by asdiallo          #+#    #+#             */
/*   Updated: 2024/12/01 22:01:54 by asdiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *init_stack(int capacity)
{
	t_stack *stack;
	
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		exit (1);
	stack->data = (int *)malloc(capacity * sizeof(int));
	if (!stack -> data)
	{
		free(stack);
		exit(1);
	}
	stack->top = -1;
	stack->capacity = capacity;
	return (stack);
}

void	push(t_stack *stack, int value)
{
	if (stack -> top == stack -> capacity - 1)
		return ;
	stack -> data[++stack -> top] = value;
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

int is_empty(t_stack* stack)
{
	return (stack->top == -1);
}

int is_full(t_stack* stack)
{
	return (stack->top == MAX - 1);
}
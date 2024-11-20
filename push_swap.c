/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdiallo <asiya040906@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:44:56 by asdiallo          #+#    #+#             */
/*   Updated: 2024/11/20 22:13:48 by asdiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *stack_initial(int capacity)
{
	t_stack *stack;
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (-1);
	stack -> data = malloc(sizeof(int) * capacity);
	if (!stack->data)
	{
		free(stack);
		return (-1);
	}
	stack -> top = -1;
	stack -> capacity = capacity;
	return (stack);
}

void push(t_stack *stack, int value)
{
	if (stack -> top == stack -> capacity -1)
		return ;
	stack -> data[++stack -> top] = value;
}

t_stack *push_swap(t_stack *stack)
{
	if (malloc_stack(stack) < 0 || stack -> top == -1)
		return (NULL);
	
}
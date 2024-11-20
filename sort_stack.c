/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdiallo <asiya040906@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:18:20 by asdiallo          #+#    #+#             */
/*   Updated: 2024/11/20 22:23:45 by asdiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int is_empty(t_stack *stack)
{
	return (stack -> top == -1);
}
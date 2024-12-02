/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdiallo <asiya040906@gmailc.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:36:45 by asdiallo          #+#    #+#             */
/*   Updated: 2024/12/02 14:42:46 by asdiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(t_stack *stack)
{
    int i;

    if (!stack || !stack->data)
    {
        printf("stack empty");
        return ;
    }
    printf("stack content :\n");
    i = 0;
    while (i < stack->capacity)
    {
        printf("%d\n", stack->data[i]);
        i++;
    }
}

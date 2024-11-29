/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdiallo <asiya040906@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:44:56 by asdiallo          #+#    #+#             */
/*   Updated: 2024/11/28 16:37:07 by asdiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *push_swap(t_stack *stack)
{
	if (malloc_stack(stack) < 0 || stack -> top == -1)
		return (NULL);
	
}

int main(int *argc, int **argv)
{
	int	capacity;

	if (argc < 2)
		return 1;
	capacity = argc -1;
		
}

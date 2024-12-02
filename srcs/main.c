/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdiallo <asiya040906@gmailc.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 21:29:55 by asdiallo          #+#    #+#             */
/*   Updated: 2024/12/02 12:15:32 by asdiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	i;
	int	value;
	t_stack	*stack;

	if (argc >= 2)
	{
		stack = init_stack(argc - 1);
		if (!stack)
			return (1);
		i = 1;
		while (i < argc)
		{
			value = ft_atoi(argv[i]);
			push(stack, value);
			printf("%s\n", argv[i]);
			i++;
		}
		free(stack->data);
		free(stack);
	}
	else
		return (1);
}

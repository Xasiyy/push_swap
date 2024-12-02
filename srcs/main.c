/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdiallo <asiya040906@gmailc.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 21:29:55 by asdiallo          #+#    #+#             */
/*   Updated: 2024/12/02 16:38:35 by asdiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;

	stack = NULL;
	if (argc >= 2)
	{
		stack = creat_stack(argc, argv);
		if (!stack)
			return (1);
	}
	free(stack->data);
	free(stack);
	return (1);
}

t_stack *creat_stack(int argc, char **argv)
{
	t_stack	*stack;
	int		i;
	int		value;

	stack = init_stack(argc - 1);
	if (!stack)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		add_elem(stack, value);
		i++;	
	}
	print_stack(stack);
	return (stack);
}

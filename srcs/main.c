/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdiallo <asiya040906@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 21:29:55 by asdiallo          #+#    #`+#             */
/*   Updated: 2024/12/10 09:33:58 by asdiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack *stack_b;

//	test_operations(argc, argv); // a enlever
	if (parsing(argc, argv) >= 0)
	{
		stack_a = create_stack(argc, argv);
		if (!stack_a)
			return (1);
		stack_b = init_stack();
		if (!stack_b)
		{
			free_stack(stack_b);
			return (1);
		}
	//	partition_stack(stack_a, stack_b);
	//	bucket_sort(stack_a, stack_b, 10);
	//	sort_three(stack_a);
		sort_stack(stack_a, stack_b);
		print_stack(stack_a);
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
	else
	    printf("error doublon"); // a enlever
	return (0);
}

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
	t_stack	*stack;

	stack = NULL;

	test_operations(); // a enlever
	if (parsing(argc, argv) >= 0)
	{
		stack = creat_stack(argc, argv);
		if (!stack)
			return (1);
		free(stack);
		return (0);
	}
	else
	    printf("error doublon"); // a enlever
	return (0);
}

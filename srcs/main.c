/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdiallo <asiya040906@gmailc.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 21:29:55 by asdiallo          #+#    #+#             */
/*   Updated: 2024/12/03 10:45:39 by asdiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;

	stack = NULL;
	if (parsing(argc, argv) >= 0)
	{
		stack = creat_stack(argc, argv);
		if (!stack)
			return (1);
		free(stack);
		return (0);
	}
	else
	    printf("error doublon");
	return (0);
}

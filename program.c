/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdiallo <asiya040906@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 21:29:55 by asdiallo          #+#    #+#             */
/*   Updated: 2024/12/01 22:04:36 by asdiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"
# include "src/libft.h"

int	main(int argc, char **argv)
{
	int	i;
	int	value;
	t_stack *stack;
	
	i = 0;
	if (argc >= 2)
	{
		stack = init_stack(argc - 1);
		while (i < argc)
		{
			value = ft_atoi(argv[i]);
			push(stack, value);
			i++;
		}
		free(stack);
		free(stack -> data);
	}
	else
		return (1);
}
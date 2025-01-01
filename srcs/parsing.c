/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdiallo <asiya040906@gmailc.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 21:22:10 by asdiallo          #+#    #+#             */
/*   Updated: 2024/12/03 10:53:22 by asdiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int parsing(int argc, char **argv)
{
	int i;
	int j;
	int tmp;

	if (argc < 2)
		return (-1);
	i = 1;
	while (i < argc)
	{
		j = i + 1;
		tmp = ft_atoi(argv[i]);
		while (j < argc)
		{
			if (tmp == ft_atoi(argv[j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

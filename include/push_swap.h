/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdiallo <asiya040906@gmailc.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:45:41 by asdiallo          #+#    #+#             */
/*   Updated: 2024/12/02 11:32:42 by asdiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef MAX
#  define MAX 100
# endif

# include "../libs/Libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> // a enlever


typedef struct s_stack{
	int *data;
	int top;
	int capacity;
}	t_stack;

t_stack *init_stack(int capacity);
//t_stack *push_swap(t_stack *stack);
void	push(t_stack *stack, int value);

#endif
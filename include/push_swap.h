/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdiallo <asiya040906@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:45:41 by asdiallo          #+#    #+#             */
/*   Updated: 2024/12/04 11:09:59 by asdiallo         ###   ########.fr       */
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


typedef struct s_node{
	int value;
	struct s_node *next;
	struct s_node *prev;
}	t_node;

typedef struct s_stack{
	t_node *top;	
}	t_stack;

//t_stack *push_swap(t_stack *stack);
t_stack *init_stack();
t_stack *creat_stack(int argc, char **argv);
void	add_elem(t_stack *stack, int value);
void	print_stack(t_stack *stack);
void	free_stack(t_stack *stack);
int parsing(int argc, char **argv);

#endif

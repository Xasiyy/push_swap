/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdiallo <asiya040906@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:45:41 by asdiallo          #+#    #+#             */
/*   Updated: 2024/12/27 15:25:05 by asdiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/Libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <stdio.h> // a enlever

typedef struct s_node{
	int value;
	int index;
	int cost_a;
	int cost_b;
	int push_cost;
	bool cheapest;
	bool above_median;
	struct s_node *next;
	struct s_node *prev;
	struct s_node *target;
}	t_node;

typedef struct s_stack{
	t_node *top;
}	t_stack;

extern int count;

// test
void	print_stack(t_stack *stack);
t_stack *init_stack();
t_stack *create_stack(int argc, char **argv);
t_node *pop(t_stack *stack);
void	add_elem(t_stack *stack, int value);
int	stack_size(t_stack *stack);
void	remove_elem(t_stack *stack, int value);
void	free_stack(t_stack **stack);
int		parsing(int argc, char **argv);
void	push(t_stack *src, t_stack *dest);
void	pa(t_stack *stack_b, t_stack *stack_a);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	swap(t_stack *stack);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	rotate(t_stack *stack);
void	ra(t_stack *stack_a);
void	rb(t_stack  *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	reverse(t_stack *stack);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);
//algo
t_node	*find_min(t_stack *stack);
t_node	*find_max(t_stack *stack);
t_node	*find_cheapest_node(t_stack *stack);
int		is_sorted(t_stack *stack);
void	sort_three(t_stack *stack);
void	prepush(t_stack *stack, t_node *top_node, char name);
//push stack
void    find_index(t_stack *stack);
void    compare_node_a(t_stack *a, t_stack *b);
void    find_cost(t_stack *a, t_stack *b);
void	min_cost(t_stack *a);
void	calcul_nodes_a(t_stack *a, t_stack *b);
bool	best_match(int a_value, int b_value, int index);
void	compare_node_b(t_stack *a, t_stack *b);
void	calcul_node_b(t_stack *a, t_stack *b);
void	prepush(t_stack *stack, t_node *top_node, char name);
void	sort_stack(t_stack *a, t_stack *b);

#endif

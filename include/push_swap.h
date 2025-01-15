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
t_node *find_max(t_stack *stack);
int	is_sorted(t_stack *stack);
void sort_three(t_stack *stack);
void	push_elem_b(t_stack *stack_a, t_stack *stack_b);
void min_on_top(t_stack *stack);
void move_a_to_b(t_stack *stack_a, t_stack *stack_b);
void move_b_to_a(t_stack *stack_a, t_stack *stack_b);
void sort_stacks(t_stack *stack_a, t_stack *stack_b);
void	push_elem_b(t_stack *stack_a, t_stack *stack_b);
void indices_median(t_stack *stack);
void	cheapest_value(t_stack *stack);
t_node *get_cheapest(t_stack *stack);
void move_to_top(t_stack *stack, t_node *node);
void set_target_a(t_stack *stack_a, t_stack *stack_b);
void cost(t_stack *stack_a, t_stack *stack_b);
void current_index(t_stack *stack);
void init_nodes_a(t_stack *a, t_stack *b);
void init_nodes_b(t_stack *a, t_stack *b);
void prep_for_push(t_stack *stack, t_node *top_node, char stack_name);
void insert_in_sorted_order(t_stack *stack_a, t_node *node);
void	adjust_stack_a(t_stack *stack_a);
#endif

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
# include <stdio.h> // a enlever

typedef struct s_node{
	int value;
	struct s_node *next;
	struct s_node *prev;
}	t_node;

typedef struct s_stack{
	t_node *top;
	int size;
}	t_stack;

extern int count; //a enlever 

// test
void	print_stack(t_stack *stack);
void test_operations(int argc, char **argv);
//t_stack *push_swap(t_stack *stack);
t_stack *init_stack();
t_stack *create_stack(int argc, char **argv);
void	add_elem(t_stack *stack, int value);
void	remove_elem(t_stack *stack, int value);
void	free_stack(t_stack *stack);
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
int	find_min(t_stack *stack);
int	find_max(t_stack *stack);
int	find_pivot(t_stack *stack);
int	stack_size(t_stack *stack);
int	partition_stack(t_stack *a, t_stack *b, int pivot);
void	quicksort(t_stack *a, t_stack *b);
void	restore_stack(t_stack *stack, int rotations);
int	is_sorted(t_stack *stack);
void	sort_three(t_stack *stack);
void	bucket_sort(t_stack *stack_a, t_stack *stack_b, int bucket_count);
void	sort_stack(t_stack *stack_a, t_stack *stack_b);
//void	radix_sort(t_stack *stack_a, t_stack *stack_b);
//void radix_merge_sort(t_stack *stack_a, t_stack *stack_b);
void	turkish_sort(t_stack *stack_a, t_stack*stack_b);

#endif

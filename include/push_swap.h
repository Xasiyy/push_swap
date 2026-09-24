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

# include "../libft/libft.h"
# include <stdbool.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					value;
	int					index;
	int					cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

typedef struct s_stack
{
	t_stack_node	*top;
}	t_stack;

// Parsing et gestion des erreurs

bool			error_syntax(const char *str);
bool			error_duplicate(t_stack_node *stack, int value);
void			free_errors(t_stack_node **stack);
long			ft_atol(const char *s);

// Initialisation des piles

int				stack_len(t_stack_node *stack);
void			free_stack(t_stack_node **stack);
t_stack			*init_stack(void);
void			append_node(t_stack_node **stack, int n);
void			init_stack_a(t_stack_node **stack, char **argv);

// Opérations de push

void			pa(t_stack_node **a, t_stack_node **b, bool print);
void			pb(t_stack_node **b, t_stack_node **a, bool print);

// Opérations de rotation

void			ra(t_stack_node **a, bool print);
void			rb(t_stack_node **b, bool print);
void			rr(t_stack_node **a, t_stack_node **b, bool print);

// Opérations de reverse rotation

void			rra(t_stack_node **a, bool print);
void			rrb(t_stack_node **b, bool print);
void			rrr(t_stack_node **a, t_stack_node **b, bool print);

// Opérations de swap

void			sa(t_stack_node **a, bool print);
void			sb(t_stack_node **b, bool print);
void			ss(t_stack_node **a, t_stack_node **b, bool print);

// Fonctions d'algorithme
bool			stack_sorted(t_stack_node *stack);
int				is_digit(int c);
t_stack_node	*find_max(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node *stack);

void			current_index(t_stack_node *stack);
void			set_target_a(t_stack_node *a, t_stack_node *b);
void			cost_analysis_a(t_stack_node *a, t_stack_node *b);
void			set_cheapest(t_stack_node *stack);
void			init_nodes_a(t_stack_node **a, t_stack_node **b);
void			set_target_b(t_stack_node *a, t_stack_node *b);
void			init_nodes_b(t_stack_node **a, t_stack_node **b);
void			prep(t_stack_node **a, t_stack_node **b, t_stack_node *n,
					char name);
void			update_all_stacks(t_stack_node **a, t_stack_node **b);
void			prep_push(t_stack_node **stack, t_stack_node *tar, char name);

void			push_to_b(t_stack_node **a, t_stack_node **b);
void			push_back_to_a(t_stack_node **a, t_stack_node **b);
void			final_sort(t_stack_node **a);
void			sort_three(t_stack_node **a);
void			sort_stacks(t_stack_node **a, t_stack_node **b);

#endif
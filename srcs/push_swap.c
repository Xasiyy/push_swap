/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdiallo <asiya040906@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:44:56 by asdiallo          #+#    #+#             */
/*   Updated: 2024/12/02 21:08:43 by asdiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void current_index(t_stack_node *stack)
{
    int i = 0;
    int len = stack_len(stack);
    int median = len / 2;
    t_stack_node *curr = stack;
    while (curr) {
        curr->index = i;
        curr->above_median = (i <= median);
        i++;
        curr = curr->next;
    }
}

void set_target_a(t_stack_node *a, t_stack_node *b)
{
    t_stack_node *currA = a;
    while (currA) {
        long best_match = LONG_MIN;
        t_stack_node *target = NULL;
        t_stack_node *currB = b;
        while (currB) {
            if (currB->value < currA->value && currB->value > best_match) {
                best_match = currB->value;
                target = currB;
            }
            currB = currB->next;
        }
        if (!target)
            currA->target_node = find_max(b);
        else
            currA->target_node = target;
        currA = currA->next;
    }
}

void cost_analysis_a(t_stack_node *a, t_stack_node *b) {
    int len_a = stack_len(a);
    int len_b = stack_len(b);
    t_stack_node *currA = a;
    while (currA) {
        if (currA->above_median)
            currA->cost = currA->index;
        else
            currA->cost = len_a - currA->index;
        if (currA->target_node) {
            if (currA->target_node->above_median)
                currA->cost += currA->target_node->index;
            else
                currA->cost += len_b - currA->target_node->index;
        }
        currA = currA->next;
    }
}

void set_cheapest(t_stack_node *stack) {
    t_stack_node *curr = stack;
    while (curr) {
        curr->cheapest = false;
        curr = curr->next;
    }
    long cheapest_value = LONG_MAX;
    t_stack_node *cheapest_node = NULL;
    curr = stack;
    while (curr) {
        if (curr->cost < cheapest_value) {
            cheapest_value = curr->cost;
            cheapest_node = curr;
        }
        curr = curr->next;
    }
    if (cheapest_node)
        cheapest_node->cheapest = true;
}

void init_nodes_a(t_stack_node **a, t_stack_node **b) {
    if (*a)
        current_index(*a);
    if (b && *b)
        current_index(*b);
    if (*a && b && *b) {
        set_target_a(*a, *b);
        cost_analysis_a(*a, *b);
    }
    if (*a)
        set_cheapest(*a);
}

void set_target_b(t_stack_node *a, t_stack_node *b)
{
    t_stack_node *currB = b;
    while (currB)
    {
        long best_match = LONG_MAX;
        t_stack_node *target = NULL;
        t_stack_node *currA = a;
        while (currA) {
            if (currA->value > currB->value && currA->value < best_match) {
                best_match = currA->value;
                target = currA;
            }
            currA = currA->next;
        }
        if (!target)
            currB->target_node = find_min(a);
        else
            currB->target_node = target;
        currB = currB->next;
    }
}

void init_nodes_b(t_stack_node **a, t_stack_node **b)
{
    if(*a) current_index(*a);
    if(*b) current_index(*b);
    if(*a && *b)
        set_target_b(*a, *b);
}

long ft_atol(const char *s)
{
    long result;
    int sign;

    result = 0;
    sign = 1;
    while (*s == ' ' || *s == '\t' || *s == '\n' || \
           *s == '\r' || *s == '\f' || *s == '\v')
        s++;
    if (*s == '-' || *s == '+')
    {
        if (*s == '-')
            sign = -1;
        s++;
    }
    while (is_digit(*s))
        result = result * 10 + (*s++ - '0');
    return (result * sign);
}

void append_node(t_stack_node **stack, int n)
{
    t_stack_node *node = malloc(sizeof(t_stack_node));
    if (!node)
        return;
    node->value = n;
    node->cost = 0;
    node->index = 0;
    node->above_median = false;
    node->cheapest = false;
    node->target_node = NULL;
    node->next = NULL;
    node->prev = NULL;
    if (!*stack) {
        *stack = node;
    } else {
        t_stack_node *last = find_last(*stack);
        last->next = node;
        node->prev = last;
    }
}

void init_stack_a(t_stack_node **a, char **argv) {
    long n;
    int i = 0;
    while (argv[i]) {
        if (error_syntax(argv[i]))
            free_errors(a);
        n = atol(argv[i]);
        if (n > INT_MAX || n < INT_MIN)
            free_errors(a);
        if (error_duplicate(*a, (int)n))
            free_errors(a);
        append_node(a, (int)n);
        i++;
    }
}

void prep_push(t_stack_node **stack, t_stack_node *target, char stack_name) {
    while (*stack != target) {
        if (stack_name == 'a')
            ra(stack, false);
        else
            rb(stack, false);
        update_all_stacks(stack, NULL);
    }
}

void prep(t_stack_node **a, t_stack_node **b, t_stack_node *node, char stack_name) {
    (void)stack_name;
    while ((*a)->value != node->value) {
        if (node->above_median)
            ra(a, false);
        else
            rra(a, false);
        current_index(*a);
    }
    if (b && *b && node->target_node) {
        while ((*b)->value != node->target_node->value) {
            if (node->target_node->above_median)
                rb(b, false);
            else
                rrb(b, false);
            current_index(*b);
        }
    }
    update_all_stacks(a, b);
}

void update_all_stacks(t_stack_node **a, t_stack_node **b) {
    init_nodes_a(a, b);
}



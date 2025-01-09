/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdiallo <asiya040906@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:18:20 by asdiallo          #+#    #+#             */
/*   Updated: 2024/12/31 22:51:16 by asdiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *init_stack()
{
	t_stack *stack;
	
	stack = malloc(sizeof(t_stack));
	if (!stack)
	{
		perror("Erreur : Allocation de mémoire pour la pile échouée");	
		return (NULL);
	}
	stack->top = NULL;
	return (stack);
}

void	add_elem(t_stack *stack, int value)
{
	t_node *new_node;
	t_node *current;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return;
	new_node->value = value;
	new_node->next = NULL;
	if (!stack->top)
	{
		stack->top = new_node;
		new_node->prev = NULL;
	}
	else 
	{
		current = stack->top;
		while (current->next)
			current = current->next;
		current->next = new_node;
		new_node->prev = current;
	}
}

t_stack *create_stack(int argc, char **argv)
{
	t_stack *stack;
	int		i;
	int		value;

	stack = init_stack();
	if (!stack)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		add_elem(stack, value);
		i++;
	}
	return (stack);
}

void	free_stack(t_stack **stack)
{
	t_node *current;
	t_node *next_node;

	if (!stack || !*stack)
		return;
	current = (*stack)->top;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	(*stack)->top = NULL;
	free(*stack);
	*stack = NULL;
}

void	remove_elem(t_stack *stack, int value)
{
	t_node *current;
	t_node *temp;
	
	if (!stack || !stack->top)
		return ;
	current = stack->top;
	while (current)
	{
		if (current->value == value)
		{
			if (current->prev)
				current->prev->next = current->next;
			else
				stack->top = current->next;
			if (current->next)
				current->next->prev = current->prev;
			temp = current;
			current = current->next;
			free(temp);
			return ;
		}
		else
			current = current->next;
	}
}

t_node *pop(t_stack *stack)
{
	t_node *top_node;

	if (!stack || !stack->top)
		return (NULL);
	top_node = stack->top;
	stack->top = top_node->next;
	if (stack->top)
		stack->top->prev = NULL;
	top_node->next = NULL;
	return (top_node);
}

int	stack_size(t_stack *stack)
{
	t_node *current;
	int size;

	size = 0;
	current = stack->top;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}

void sort_three(t_stack *stack)
{
    int first;
    int second;
    int third;

    if (stack_size(stack) != 3)
        return;

    first = stack->top->value;
    second = stack->top->next->value;
    third = stack->top->next->next->value;

    if (first > second && second < third && first < third)
        sa(stack);
    else if (first > second && second > third && first > third)
    {
        sa(stack);
        rra(stack);
    }
    else if (first > second && second < third && first > third)
        ra(stack);
    else if (first < second && second > third && first < third)
    {
        sa(stack);
        ra(stack);
    }
    else if (first < second && second > third && first > third)
        rra(stack);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdiallo <asiya040906@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:18:20 by asdiallo          #+#    #+#             */
/*   Updated: 2024/12/20 11:17:22 by asdiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *init_stack()
{
	t_stack *stack;
	
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

void	add_elem(t_stack *stack, int value)
{
	t_node *new_node;
	t_node *current;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (stack->top == NULL)
		stack->top = new_node;
	else 
	{
		current = stack->top;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
		new_node->prev = current;
	}
	stack->size++;
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

void	free_stack(t_stack *stack)
{
	t_node *current;
	t_node *next_node;

	current = stack->top;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
		stack->size--;
	}
	free(stack);
}

void	remove_elem(t_stack *stack, int value)
{
	t_node *current;
	t_node *temp;
	
	if (!stack || stack->top)
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
			stack->size--;
			return ;
		}
		else
			current = current->next;
	}
}
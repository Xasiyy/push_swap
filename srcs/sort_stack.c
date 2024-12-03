/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdiallo <asiya040906@gmailc.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:18:20 by asdiallo          #+#    #+#             */
/*   Updated: 2024/12/03 11:12:41 by asdiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *init_stack()
{
	t_stack *stack;
	
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		exit (1);
	stack->top = NULL;
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
	if (stack->top == NULL)
		stack->top = new_node;
	else 
	{
		current = stack->top;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
}

t_stack *creat_stack(int argc, char **argv)
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
	print_stack (stack);
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
	}
	free(stack);
}
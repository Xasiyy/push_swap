/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdiallo <asiya040906@gmailc.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:43:41 by asdiallo          #+#    #+#             */
/*   Updated: 2025/02/15 12:32:59 by asdiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_order_code(t_stack_node **a)
{
	int	f;
	int	s;
	int	t;

	f = (*a)->value;
	s = (*a)->next->value;
	t = (*a)->next->next->value;
	if (f < s && s < t)
		return (0);
	if (f > s && s < t && f < t)
		return (1);
	if (f > s && s > t)
		return (2);
	if (f > s && s < t && f > t)
		return (3);
	if (f < s && s > t && f < t)
		return (4);
	if (f < s && s > t && f > t)
		return (5);
	return (-1);
}

static void	sort_three_by_code(t_stack_node **a, int code)
{
	if (code == 0)
		return ;
	else if (code == 1)
		sa(a, false);
	else if (code == 2)
	{
		sa(a, false);
		rra(a, false);
	}
	else if (code == 3)
		ra(a, false);
	else if (code == 4)
	{
		sa(a, false);
		ra(a, false);
	}
	else if (code == 5)
		rra(a, false);
}

void	sort_three(t_stack_node **a)
{
	int	code;

	if (stack_len(*a) != 3)
		return ;
	code = get_order_code(a);
	sort_three_by_code(a, code);
}

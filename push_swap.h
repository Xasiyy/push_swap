/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdiallo <asiya040906@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:45:41 by asdiallo          #+#    #+#             */
/*   Updated: 2024/11/28 16:39:57 by asdiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef MAX
#  define MAX 100
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> // a enlever


typedef struct s_stack{
	int *data;
	int top;
	int capacity;
}	t_stack;

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_generator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdiallo <asiya040906@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:37:23 by asdiallo          #+#    #+#             */
/*   Updated: 2024/11/28 12:05:58 by asdiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int is_abs(int value)
{
    if (value < 0)
        return (-value);
    else
        return (value);
}

int lcg(int *seed)
{
    int a = 1103515245;
    int c = 12345;
    int m = 32768;

    *seed = (a * (*seed) + c) % m;

    return (is_abs(*seed % 501));
}

int main ()
{
    int *seed;
    int i;
    i = 0;
    while (i < 100) {
        printf("%d\n", lcg(seed));
        i++;
    }
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arrays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toramo <toramo.student@hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:15:40 by toramo            #+#    #+#             */
/*   Updated: 2023/11/27 11:18:56 by toramo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_arrays(t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	ft_printf("a\n");
	while (i < arrsize(a))
	{
		ft_printf("%i	%i\n", a[i]->n, a[i]->pnum);
		i++;
	}
	ft_printf("b\n");
	i = 0;
	while (i < arrsize(b))
	{
		ft_printf("%i	%i\n", b[i]->n, b[i]->pnum);
		i++;
	}
	ft_printf("=======================\n");
}

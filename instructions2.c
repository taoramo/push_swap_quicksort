/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toramo <toramo.student@hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:40:30 by toramo            #+#    #+#             */
/*   Updated: 2023/11/27 15:48:11 by toramo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack **a, t_stack **b, char **inst)
{
	int	i;
	int	asize;
	int	bsize;

	asize = arrsize(a);
	bsize = arrsize(b);
	i = asize - 1;
	if (arrsize(b) == 0)
		return ;
	while (i >= 0)
	{
		a[i + 1] = a[i];
		i--;
	}
	a[0] = b[0];
	i = 0;
	while (b[i + 1] != 0)
	{
		b[i] = b[i + 1];
		i++;
	}
	b[bsize - 1] = 0;
	add_instruction(a, b, "pa", inst);
}

void	push_b(t_stack **a, t_stack **b, char **inst)
{
	int	i;
	int	asize;
	int	bsize;

	if (arrsize(a) == 0)
		return ;
	bsize = arrsize(b);
	asize = arrsize(a);
	i = bsize - 1;
	while (i >= 0)
	{
		b[i + 1] = b[i];
		i--;
	}
	b[0] = a[0];
	i = 0;
	while (a[i + 1] != 0)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[asize - 1] = 0;
	add_instruction(a, b, "pb", inst);
}

void	swap_a(t_stack **a, t_stack **b, char **inst)
{
	t_stack	*temp;

	temp = a[0];
	a[0] = a[1];
	a[1] = temp;
	add_instruction(a, b, "sa", inst);
}

void	swap_b(t_stack **a, t_stack **b, char **inst)
{
	t_stack	*temp;

	temp = b[0];
	b[0] = b[1];
	b[1] = temp;
	add_instruction(a, b, "sb", inst);
}

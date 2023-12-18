/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toramo <toramo.student@hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:13:25 by toramo            #+#    #+#             */
/*   Updated: 2023/12/01 12:13:26 by toramo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reset_place_b(t_stack **a, t_stack **b, int pnum, char **inst)
{
	while (b[0]->n != pnum_max_x(b, pnum))
		rrotate_b(a, b, inst, 1);
}

void	insert_b(t_stack **a, t_stack **b, char **inst, int *pnum)
{
	int	pnum_current;

	pnum_current = a[0]->pnum;
	*pnum = *pnum + 10;
	while (p_size(a, pnum_current))
	{
		find_place_b(a, b, a[0], inst);
		b[0]->pnum = pnum_current + 8;
	}
	if (p_size(b, 1))
	{
		while (b[arrsize(b) - 1]->pnum != 1)
			rrotate_b(a, b, inst, 1);
	}
	else
		reset_place_b(a, b, pnum_current + 8, inst);
}

void	insert_a(t_stack **a, t_stack **b, char **inst)
{
	int	pnum_current;

	pnum_current = b[0]->pnum;
	while (p_size(b, pnum_current))
	{
		find_place_a(a, b, b[0]->n, inst);
		push_a(a, b, inst);
		a[0]->pnum = 0;
	}
	find_place_a(a, b, 0, inst);
}

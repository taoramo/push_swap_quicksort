/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toramo <toramo.student@hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:04:57 by toramo            #+#    #+#             */
/*   Updated: 2023/11/28 14:43:29 by toramo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	pivotpush_init(t_stack **a, t_stack **b, char **inst, int *pnum)
{
	while (!(p_size(a, 1) == 0 && p_size(a, 2) == 0))
	{
		if (a[0]->pnum != 2 && a[0]->pnum != 1)
			rotate_a(a, b, inst, 1);
		else if (a[0]->pnum == 1)
		{
			push_b(a, b, inst);
			rotate_b(a, b, inst, 1);
		}
		else if (a[0]->pnum == 2)
			push_b(a, b, inst);
	}
	*pnum = *pnum + 2;
}

void	pivotpush_b_phaseone(t_stack **a, t_stack **b, char **inst, int *pnum)
{
	if (*pnum == 2)
		pivotpush_init(a, b, inst, pnum);
	else
	{
		while (!(p_size(a, *pnum - 1) == 0 && p_size(a, *pnum) == 0))
		{
			if (a[0]->pnum != *pnum && a[0]->pnum != *pnum - 1)
				rotate_a(a, b, inst, 1);
			else if (a[0]->pnum == *pnum)
			{
				push_b(a, b, inst);
				rotate_b(a, b, inst, 1);
			}
			else if (a[0]->pnum == *pnum - 1)
				push_b(a, b, inst);
		}
		if (b[arrsize(b) - 1]->pnum != 1)
			reset_rotation_b_phaseone(a, b, inst, pnum);
	}
	*pnum = *pnum + 2;
}

void	phase_one(t_stack **a, t_stack **b, char **inst)
{
	int	pnum;

	pnum = 2;
	if (arrsize(a) < 12)
		small_n(a, b, inst);
	while (arrsize(a) > 3)
	{
		if (arrsize(a) >= 12)
		{
			partition_init6(a, pnum);
			pivotpush_b_phaseone(a, b, inst, &pnum);
		}
		else if (arrsize(a) > 3)
		{
			partition_init2(a, pnum);
			pivotpush_b_phaseone(a, b, inst, &pnum);
		}
		else
			small_arrays(a, b, inst, 0);
	}
	if (arrsize(a) <= 3)
		small_arrays(a, b, inst, 0);
	phase_two(a, b, inst, &pnum);
	endgame(a, b, inst);
}

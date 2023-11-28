/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toramo <toramo.student@hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:04:57 by toramo            #+#    #+#             */
/*   Updated: 2023/11/27 17:12:34 by toramo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pivotpush_b_phaseone(t_stack **a, t_stack **b, char **inst, int *pnum)
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
	reset_rotation_b_phaseone(a, b, inst);
	*pnum = *pnum + 2;
}

void	partition(t_stack **a, int *pnum)
{
	int	i;

	i = 0;
	while (i < arrsize(a))
	{
		if (a[i]->n <= find_largest(a) / 2)
			a[i]->pnum = *pnum - 1;
		if (a[i]->n > find_largest(a) / 2)
			a[i]->pnum = *pnum;
		i++;
	}
}

void	partition_init(t_stack **a, int *pnum)
{
	int	i;

	i = 0;
	while (i < arrsize(a))
	{
		if (a[i]->n <= find_largest(a) / 4)
			a[i]->pnum = *pnum - 1;
		if (a[i]->n > find_largest(a) / 4 && a[i]->n <= find_largest(a))
			a[i]->pnum = *pnum;
		i++;
	}
}

void	phase_one(t_stack **a, t_stack **b, char **inst)
{
	int	pnum;

	pnum = 2;
	if (is_sorted(a))
		free_everything(a, b, inst);
	while (arrsize(a))
	{
		if (arrsize(a) > 7)
		{
			partition_init(a, &pnum);
			pivotpush_b_phaseone(a, b, inst, &pnum);
		}
		if (arrsize(a) > 3)
		{
			partition(a, &pnum);
			pivotpush_b_phaseone(a, b, inst, &pnum);
		}
		else
			small_arrays(a, b, inst, 0);
	}
	endgame(a, b, inst);
}

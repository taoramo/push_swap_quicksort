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

void	pivotpush_init(t_stack **a, t_stack **b, char **inst)
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
}

void	pivotpush_b_phaseone(t_stack **a, t_stack **b, char **inst, int *pnum)
{
	if (*pnum == 2)
		pivotpush_init(a, b, inst);
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
		reset_rotation_b(a, b, inst);
	}
	*pnum = *pnum + 2;
}

void	partition_init2(t_stack **a, int pnum)
{
	int	i;
	int	median;

	i = 0;
	median = pnum_median_x(a, 0);
	while (i < arrsize(a))
	{
		if (a[i]->n <= median)
			a[i]->pnum = pnum - 1;
		if (a[i]->n > median)
			a[i]->pnum = pnum;
		i++;
	}
}

void	partition_init4(t_stack **a, int pnum)
{
	int	i;
	int	median;
	int	minimum;

	median = pnum_median_x(a, 0);
	minimum = pnum_min_x(a, 0);
	i = 0;
	while (i < arrsize(a))
	{
		if (a[i]->n <= median && a[i]->n <= (median - (median - minimum) / 2))
			a[i]->pnum = pnum - 1;
		if (a[i]->n <= median && a[i]->n > (median - (median - minimum) / 2))
			a[i]->pnum = pnum;
		i++;
	}
}

void	phase_one(t_stack **a, t_stack **b, char **inst)
{
	int	pnum;

	pnum = 2;
	if (is_sorted(a))
		free_everything(a, b, inst);
	while (arrsize(a) > 3)
	{
		if (arrsize(a) >= 12)
		{
			partition_init4(a, pnum);
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
	if (arrsize(a))
	{
		small_arrays(a, b, inst, 0);
	}
	phase_two(a, b, inst, &pnum);
	endgame(a, b, inst);
}

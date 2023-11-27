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

void	pivotpush_b(t_stack **a, t_stack **b, char **inst, int pnum)
{
	while (!(p_size(a, pnum - 1) == 0 && p_size(a, pnum) == 0))
	{
		if (a[0]->pnum == 0)
			rotate_a(a, b, inst, 1);
		if (a[0]->pnum == pnum - 1 && (b[0] == 0 || b[0]->pnum == pnum - 1))
			push_b(a, b, inst);
		else if (a[0]->pnum == pnum - 1 && (b[0]->pnum == pnum))
		{
			if (arrsize(b) > 2)
				rrotate_b(a, b, inst, 1);
			push_b(a, b, inst);
		}
		else if (a[0]->pnum == pnum && (b[0] == 0 || b[0]->pnum == pnum))
			push_b(a, b, inst);
		else if (a[0]->pnum == pnum && (b[0]->pnum == pnum - 1))
		{
			if (arrsize(b) > 2)
				rotate_b(a, b, inst, 1);
			push_b(a, b, inst);
		}
	}
	reset_rotation_b(a, b, inst);
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
	*pnum = *pnum + 2;
}

void	partition_init(t_stack **a, int *pnum)
{
	int	size;
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
	size = arrsize(a);
	*pnum = *pnum + 2;
}

void	sorted_run(t_stack **a)
{
	int	i;
	int	sorted;
	int	ione;

	i = 0;
	ione = 0;
	sorted = 0;
	while (i < arrsize(a) && a[i]->n != 1)
		i++;
	ione = i;
	while (i + 1 < arrsize(a) && a[i + 1] == a[i] + 1)
	{
		sorted++;
		i++;
	}
	i++;
	if (sorted <= 3)
		return ;
	while (sorted)
	{
		a[i]->pnum = -1;
		sorted--;
		i--;
	}
}

void	phase_one(t_stack **a, t_stack **b, char **inst)
{
	int	pnum;

	pnum = 2;
//	sorted_run(a);
	while (arrsize(a))
	{
		if (arrsize(a) > 7)
		{
			partition_init(a, &pnum);
			pivotpush_b(a, b, inst, pnum - 2);
		}
		if (arrsize(a) > 3)
		{
			partition(a, &pnum);
			pivotpush_b(a, b, inst, pnum - 2);
		}
		else
			small_arrays(a, b, inst, pnum - 2);
	}
	endgame(a, b, inst);
}

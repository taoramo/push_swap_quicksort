/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toramo <toramo.student@hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:04:57 by toramo            #+#    #+#             */
/*   Updated: 2023/11/27 16:07:26 by toramo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pivotpush_b(t_stack **a, t_stack **b, char **inst, int pnum)
{
	while (!(p_size(a, b, pnum - 1) == 0 && p_size(a, b, pnum) == 0)
		&& arrsize(a))
	{
		if (a[0]->pnum == pnum - 1 && (b[0] == 0 || b[0]->pnum == pnum - 1))
			push_b(a, b, inst);
		else if (a[0]->pnum == pnum - 1 && (b[0]->pnum == pnum)
			&& arrsize(b) > 1)
		{
			rrotate_b(a, b, inst, 1);
			push_b(a, b, inst);
		}
		else if (a[0]->pnum == pnum && (b[0] == 0 || b[0]->pnum == pnum))
			push_b(a, b, inst);
		else if (a[0]->pnum == pnum && (b[0]->pnum == pnum - 1)
			&& arrsize(b) > 1)
		{
			rotate_b(a, b, inst, 1);
			push_b(a, b, inst);
		}
		else
			rotate_a(a, b, inst, 1);
	}
	reset_rotation_b(a, b, inst);
}

void	partition(t_stack **a, int *pnum)
{
	int	size;
	int	i;

	i = 0;
	size = arrsize(a);
	while (i < size)
	{
		if (a[i]->n <= size / 2 && a[i]->pnum >= 0)
			a[i]->pnum = *pnum + 1;
		if (a[i]->n > size / 2 && a[i]->pnum >= 0)
			a[i]->pnum = *pnum + 2;
		i++;
	}
	*pnum = *pnum + 2;
}

void	partition_init(t_stack **a, int *pnum)
{
	int	size;
	int	i;

	i = 0;
	size = arrsize(a);
	while (i < size)
	{
		if (a[i]->n <= size / 4 && a[i]->pnum >= 0)
			a[i]->pnum = *pnum + 1;
		if (a[i]->n > size / 4 && a[i]->n <= size / 2 && a[i]->pnum >= 0)
			a[i]->pnum = *pnum + 2;
		i++;
	}
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

	pnum = 0;
	sorted_run(a);
	while (arrsize(a))
	{
		if (arrsize(a) > 7)
		{
		partition_init(a, &pnum);
		pivotpush_b(a, b, inst, pnum);
		}
		if (arrsize(a) > 3)
		{
			partition(a, &pnum);
			pivotpush_b(a, b, inst, pnum);
		}
		else
		small_arrays(a, b, inst, pnum);
	}
	endgame(a, b, inst);
}

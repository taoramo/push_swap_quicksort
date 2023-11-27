/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toramo <toramo.student@hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:04:57 by toramo            #+#    #+#             */
/*   Updated: 2023/11/27 11:46:46 by toramo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pivotpush_b(t_stack **a, t_stack **b, char **inst, int pnum)
{
	while (!(p_size(a, pnum - 1) == 0 && p_size(a, pnum) == 0))
	{
		if (a[0]->pnum == pnum - 1 && (b[0] == 0 || b[0]->pnum == pnum - 1))
			push_b(a, b, inst);
		else if (a[0]->pnum == pnum - 1 && (b[0]->pnum == pnum))
		{
			rrotate_b(a, b, inst, 1);
			push_b(a, b, inst);
		}
		else if (a[0]->pnum == pnum && (b[0] == 0 || b[0]->pnum == pnum))
			push_b(a, b, inst);
		else if (a[0]->pnum == pnum && (b[0]->pnum == pnum - 1))
		{
			rotate_b(a, b, inst, 1);
			push_b(a, b, inst);
		}
		else
			rotate_a(a, b, inst, 1);
	}
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

	i = 0;
	while (a[i]->n != 1 && i + 1 < arrsize(a))
		i++;
	if (a[i + 1] != 0)
		if (a[i + 1]->n == a[i]->n + 1)
			a[i]->pnum = -1;
	if (a[i + 1] != 0)
	{
		while ((a[i + 1]->n == a[i]->n + 1) && (i + 2 < arrsize(a)))
		{
			a[i + 1]->pnum = -1;
			i++;
		}
	}
}

void	phase_one(t_stack **a, t_stack **b, char **inst)
{
	int	pnum;

	pnum = 0;
	sorted_run(a);
	while (arrsize(a) > 6 && !is_sorted(a))
	{
		partition_init(a, &pnum);
		pivotpush_b(a, b, inst, pnum);
	}
	partition(a, &pnum);
	pivotpush_b(a, b, inst, pnum);
	endgame(a, b, inst);
}

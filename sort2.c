/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toramo <toramo.student@hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:09:45 by toramo            #+#    #+#             */
/*   Updated: 2023/12/01 12:09:46 by toramo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	partition_2(t_stack **a, int pnum_max, int *pnum)
{
	int	i;
	int	median;

	i = 0;
	median = pnum_median_x(a, pnum_max);
	*pnum = *pnum + 2;
	if (p_size(a, pnum_max))
	{
		while (i < arrsize(a))
		{
			if (a[i]->pnum == pnum_max && a[i]->n <= median)
				a[i]->pnum = *pnum - 1;
			if (a[i]->pnum == pnum_max && a[i]->n > median)
				a[i]->pnum = *pnum;
			i++;
		}
	}
}

int	pnum_selector(t_stack **a, t_stack **b)
{
	int	pnum_max;
	int	i;

	i = 0;
	pnum_max = 0;
	if (a[0])
	{
		while (i < arrsize(a))
		{
			if (a[i]->pnum > pnum_max)
				pnum_max = a[i]->pnum;
			i++;
		}
	}
	if (pnum_max != 0)
		return (pnum_max);
	i = 0;
	while (i < arrsize(b) && b[0])
	{
		if (b[i]->pnum > pnum_max)
			pnum_max = b[i]->pnum;
		i++;
	}
	return (pnum_max);
}

void	pivotpush_a(t_stack **a, t_stack **b, char **inst, int pnum)
{
	int	n;

	n = 0;
	while (!(p_size(b, pnum - 1) == 0 && p_size(b, pnum) == 0))
	{
		if (b[0]->pnum == pnum)
			push_a(a, b, inst);
		else if (b[0]->pnum == pnum - 1)
		{
			push_a(a, b, inst);
			rotate_a(a, b, inst, 1);
			n++;
		}
	}
	if (p_size(a, pnum) <= 3 && (a[3]->pnum == 0 || p_size(a, 0) == 0))
		small_arrays(a, b, inst, pnum);
	rrotate_a(a, b, inst, n);
}

void	pivotpush_b(t_stack **a, t_stack **b, char **inst, int pnum)
{
	int	n;

	n = 0;
	while (!(p_size(a, pnum - 1) == 0 && p_size(a, pnum) == 0))
	{
		if (a[0]->pnum == pnum)
		{
			push_b(a, b, inst);
			rotate_b(a, b, inst, 1);
			n++;
		}
		else if (a[0]->pnum == pnum - 1)
			push_b(a, b, inst);
	}
	rrotate_b(a, b, inst, n);
}

void	phase_two(t_stack **a, t_stack **b, char **inst, int *pnum)
{
	int	pnum_select;

	while (!(is_sorted(a)) || arrsize(b))
	{
		pnum_select = pnum_selector(a, b);
		if ((p_size(a, pnum_select) <= 3 && p_size(a, pnum_select)))
			small_arrays(a, b, inst, a[0]->pnum);
		else if ((p_size(b, pnum_select) <= 3 && p_size(b, pnum_select)))
			small_arrays(a, b, inst, b[0]->pnum);
		else if (p_size(a, pnum_select) && p_size(a, a[0]->pnum) > 24)
		{
			partition_2(a, a[0]->pnum, pnum);
			pivotpush_b(a, b, inst, pnum_selector(a, b));
		}
		else if (p_size(a, pnum_select) && p_size(a, a[0]->pnum) <= 24)
			insert_b(a, b, inst, pnum);
		else if (p_size(b, b[0]->pnum) > 24 && p_size(b, pnum_select))
		{
			partition_2(b, b[0]->pnum, pnum);
			pivotpush_a(a, b, inst, pnum_selector(a, b));
		}
		else if (p_size(b, b[0]->pnum) <= 24 && p_size(b, pnum_select))
			insert_a(a, b, inst);
	}
}

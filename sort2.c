#include "push_swap.h"

void	partition_2(t_stack **a, int pnum_max, int *pnum)
{
	int	i;
	int	median;

	i = 0;
	median = pnum_median_x(a, pnum_max);
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

int	pnum_largest(t_stack **a, t_stack **b)
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

void	pivotpush_a(t_stack **a, t_stack **b, char **inst, int *pnum)
{
	while (!(p_size(b, *pnum - 1) == 0 && p_size(b, *pnum) == 0))
	{
		if (b[0]->pnum == *pnum)
			push_a(a, b, inst);
		else if (b[0]->pnum == *pnum - 1)
		{
			push_a(a, b, inst);
			rotate_a(a, b, inst, 1);
		}
	}
	if (p_size(a, *pnum) <= 3 && a[3]->pnum == 0)
		small_arrays(a, b, inst, *pnum);
	reset_rotation_a(a, b, inst);
}

void	pivotpush_b(t_stack **a, t_stack **b, char **inst, int *pnum)
{
	while (!(p_size(a, *pnum - 1) == 0 && p_size(a, *pnum) == 0))
	{
		if (a[0]->pnum == *pnum)
		{
			push_b(a, b, inst);
			rotate_b(a, b, inst, 1);
		}
		else if (a[0]->pnum == *pnum - 1)
			push_b(a, b, inst);
	}
	reset_rotation_b(a, b, inst);
}

void	phase_two(t_stack **a, t_stack **b, char **inst, int *pnum)
{
	int	pnum_max;

	while (p_size(b, 1) || p_size(a, 1))
	{
		print_arrays(a, b);
		pnum_max = pnum_largest(a, b);
		if ((p_size(a, pnum_max) <= 3 && p_size(a, pnum_max))
			|| (p_size(b, pnum_max) <= 3 && p_size(b, pnum_max)))
			small_arrays(a, b, inst, pnum_max);
		if (p_size(a, pnum_max) > 3)
		{
			partition_2(a, pnum_max, pnum);
			pivotpush_b(a, b, inst, pnum);
		}
		if (p_size(b, pnum_max) > 3)
		{
			partition_2(b, pnum_max, pnum);
			pivotpush_a(a, b, inst, pnum);
		}
	}
}

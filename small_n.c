#include "push_swap.h"

int	partition_threes(t_stack **a)
{
	int	pnum;
	int	i;

	pnum = 0;
	while (p_size(a, 0))
	{
		i = 0;
		while (i < arrsize(a))
		{
			if (pnum_min_x(a, 0) == a[i]->n)
				a[i]->pnum = pnum;
			if (p_size(a, pnum) >= 3 && p_size(a, 0))
				pnum++;
			i++;
		}
	}
	return (pnum);
}

void	sort_last_three_a(t_stack **a, t_stack **b, char **inst)
{
	if (a[0]->n < a[1]->n && a[1]->n < a[2]->n)
		set_three_pnum(a);
	if (a[0]->n < a[2]->n && a[2]->n < a[1]->n)
	{
		swap_a(a, b, inst);
		rotate_a(a, b, inst, 1);
	}
	if (a[1]->n < a[0]->n && a[0]->n < a[2]->n)
		swap_a(a, b, inst);
	if (a[1]->n < a[2]->n && a[2]->n < a[0]->n)
		rotate_a(a, b, inst, 1);
	if (a[2]->n < a[0]->n && a[0]->n < a[1]->n)
		rrotate_a(a, b, inst, 1);
	if (a[2]->n < a[1]->n && a[1]->n < a[0]->n)
	{
		swap_a(a, b, inst);
		rrotate_a(a, b, inst, 1);
	}
	set_three_pnum(a);
}

void	small_n2(t_stack **a, t_stack **b, char **inst)
{
	int	pnum;
	int	pnum_current;

	pnum_current = 1;
	pnum = partition_threes(a);
	while (pnum_current < pnum)
	{
		if (a[0]->pnum == pnum_current)
			push_b(a, b, inst);
		else
			rotate_a(a, b, inst, 1);
		if (p_size(a, pnum_current) == 0)
			pnum_current++;
	}
	if (arrsize(a) == 3)
		sort_last_three_a(a, b, inst);
	else
		small_arrays(a, b, inst, a[0]->pnum);
	while (arrsize(b))
		small_arrays(a, b, inst, b[0]->pnum);
	endgame(a, b, inst);
}

void	small_n(t_stack **a, t_stack **b, char **inst)
{
	if (arrsize(a) == 3)
	{
		sort_last_three_a(a, b, inst);
		endgame(a, b, inst);
	}
	if (arrsize(a) < 3)
	{
		small_arrays(a, b, inst, 0);
		endgame(a, b, inst);
	}
	small_n2(a, b, inst);
}

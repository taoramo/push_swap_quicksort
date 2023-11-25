#include "push_swap.h"

void	sort_three(t_stack **a, t_stack **b, char **inst, int argc)
{
	if (a[0]->n == argc - 3 && a[1]->n == argc - 2 && a[2]->n == argc - 1)
		return ;
	else if (a[0]->n == argc - 3 && a[1]->n == argc - 1 && a[2]->n == argc - 2)
	{
		swap_a(a, b, inst);
		rotate_a(a, b, inst, 1);
	}
	else if (a[0]->n == argc - 2 && a[1]->n == argc - 3 && a[2]->n == argc - 1)
		swap_a(a, b, inst);
	else if (a[0]->n == argc - 2 && a[1]->n == argc - 1 && a[2]->n == argc - 3)
		rrotate_a(a, b, inst, 1);
	else if (a[0]->n == argc - 1 && a[1]->n == argc - 3 && a[2]->n == argc - 2)
		rotate_a(a, b, inst, 1);
	else if (a[0]->n == argc - 1 && a[1]->n == argc - 2 && a[2]->n == argc - 3)
	{
		swap_a(a, b, inst);
		rrotate_a(a, b, inst, 1);
	}
}

void	pivotpush_b(t_stack **a, t_stack **b, char **inst, int i)
{
	int	pivot;

	pivot = a[i]->pivot;
	if (a[i]->n <= pivot && (b[0]->n < pivot || b[0] == 0))
		push_b(a, b, inst);
	if (a[i]->n <= pivot && (b[0]->n >= pivot || b[0] == 0))
	{
		rrotate_b(a, b, inst, 1);
		push_b(a, b, inst);
	}
	if (a[i]->n > pivot && (b[0]->n >= pivot || b[0] == 0))
		push_b(a, b, inst);
	if (a[i]->n > pivot && (b[0]->n < pivot))
	{
		rotate_b(a, b, inst, 1);
		push_b(a, b, inst);
	}
}

void	initsort_a(t_stack **a, t_stack **b, char **inst, int pnum)
{
	int	i;
	int	pivot;

	pivot = arrsize(a) / 4;
	i = 0;
	while (a[i])
	{
		if (a[i]->n <= pivot * 2)
		{
			a[i]->pivot = pivot;
			pivotpush_b(a, b, inst, i);
			a[i]->pnum = pnum;
		}
		else if (a[i]->n > pivot && a[i + 1]->n > pivot
			&& a[i]->n > a[i + 1]->n)
			swap_a(a, b, inst);
		else
			rotate_a(a, b, inst, 1);
	}
}

void	phase_one(t_stack **a, t_stack **b, char **inst, int argc)
{
	int	pnum;

	pnum = 1;
	while (arrsize(a) > 3 && !is_sorted(a))
		initsort_a(a, b, inst, pnum);
	sort_three(a, b, inst, argc);
}

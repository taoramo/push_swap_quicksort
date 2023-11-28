#include "push_swap.h"

int	pnum_median_x(t_stack **x, int pnum)
{
	int	i;
	int	n;
	int	sum;

	i = 0;
	n = 0;
	sum = 0;
	while (i < arrsize(x))
	{
		if (x[i]->pnum == pnum)
		{
			n++;
			sum += x[i]->n;
		}
		i++;
	}
	if (n)
		return (sum / n);
	else
		return (0);
}

int	pnum_median(t_stack **a, t_stack **b, int pnum)
{
	if (p_size(a, pnum))
		return (pnum_median_x(a, pnum));
	if (p_size(b, pnum))
		return (pnum_median_x(b, pnum));
	else
		return (0);
}

int	pnum_min_x(t_stack **x, int pnum)
{
	int	smallest;
	int	i;

	i = 0;
	smallest = 2147483647;
	while (i < arrsize(x))
	{
		if (x[i]->n < smallest && x[i]->pnum == pnum)
			smallest = x[i]->n;
		i++;
	}
	return (smallest);
}

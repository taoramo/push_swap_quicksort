/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toramo <toramo.student@hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:12:18 by toramo            #+#    #+#             */
/*   Updated: 2023/12/01 12:12:20 by toramo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	partition_init6(t_stack **a, int pnum)
{
	int	i;
	int	min;
	int	max;
	int	pivot;

	min = pnum_min_x(a, 0);
	max = pnum_max_x(a, 0);
	pivot = min + (max - min) / 6;
	i = 0;
	while (i < arrsize(a))
	{
		if (a[i]->n <= pivot)
			a[i]->pnum = pnum - 1;
		if (a[i]->n > pivot && a[i]->n < pivot + (max - min) / 6)
			a[i]->pnum = pnum;
		i++;
	}
}

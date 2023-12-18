/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pnum_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toramo <toramo.student@hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:09:24 by toramo            #+#    #+#             */
/*   Updated: 2023/12/01 12:09:25 by toramo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	pnum_max_x(t_stack **x, int pnum)
{
	int	largest;
	int	i;

	i = 0;
	largest = -2147483648;
	while (i < arrsize(x))
	{
		if (x[i]->n > largest && x[i]->pnum == pnum)
			largest = x[i]->n;
		i++;
	}
	return (largest);
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

void	reset_rotation_a(t_stack **a, t_stack **b, char **inst, int n)
{
	if (!a[0])
		return ;
	if (p_size(a, 0))
	{
		while (a[arrsize(a) - 1]->pnum != 0)
			rrotate_a(a, b, inst, 1);
	}
	else
		rrotate_a(a, b, inst, n);
}

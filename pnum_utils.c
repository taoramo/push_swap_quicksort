/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pnum_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toramo <toramo.student@hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:34:21 by toramo            #+#    #+#             */
/*   Updated: 2023/11/27 17:06:13 by toramo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reset_rotation_b_phaseone(t_stack **a, t_stack **b, char **inst)
{
	if (!b[0])
		return ;
	while (b[arrsize(b) - 1]->pnum != 1 || b[0]->pnum == 1)
	{
		if (a[0])
		{
			if (a[0]->pnum != 1 && a[0]->pnum != 2)
			{
				rrotate_a(a, b, inst, 1);
				rrotate_b(a, b, inst, 1);
			}
		}
		else
			rrotate_b(a, b, inst, 1);
	}
}

void	reset_rotation_b(t_stack **a, t_stack **b, char **inst, int pnum)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (i < arrsize(b))
	{
		if (b[i]->pnum == pnum)
			n++;
		i++;
	}
	if (!b[0])
		return ;
	if (p_size(b, 1))
	{
		while (b[arrsize(b) - 1]->pnum != 1 || b[0]->pnum == 1)
			rrotate_b(a, b, inst, 1);
	}
	else
		rrotate_b(a, b, inst, n);
}

int	p_size(t_stack **a, int pnum)
{
	int	i;
	int	psize;

	i = 0;
	psize = 0;
	while (i < arrsize(a))
	{
		if (a[i]->pnum == pnum)
			psize++;
		i++;
	}
	return (psize);
}

void	set_three_pnum(t_stack **a)
{
	a[0]->pnum = 0;
	a[1]->pnum = 0;
	a[2]->pnum = 0;
}

int	find_largest(t_stack **a)
{
	int	i;
	int	largest;

	i = 0;
	largest = 0;
	while (i < arrsize(a))
	{
		if (a[i]->n > largest)
			largest = a[i]->n;
		i++;
	}
	return (largest);
}

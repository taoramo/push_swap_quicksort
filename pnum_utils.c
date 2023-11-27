/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pnum_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toramo <toramo.student@hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:34:21 by toramo            #+#    #+#             */
/*   Updated: 2023/11/27 16:04:34 by toramo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reset_rotation_b(t_stack **a, t_stack **b, char **inst)
{
	int	i;

	i = 0;
	if (!b[0])
		return ;
	while (i < arrsize(b) && b[i]->pnum != 1)
		i++;
	while (i < arrsize(b) && b[i]->pnum == 1)
		i++;
	if (i < arrsize(b) / 2)
		rrotate_b(a, b, inst, (i - arrsize(b)) * -1);
	else
		rotate_b(a, b, inst, arrsize(b) - i);
}

int	p_size(t_stack **a, t_stack **b, int pnum)
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
	if (psize > 0)
		return (psize);
	i = 0;
	while (i < arrsize(b))
	{
		if (b[i]->pnum == pnum)
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

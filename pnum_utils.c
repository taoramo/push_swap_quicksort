/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pnum_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toramo <toramo.student@hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:34:21 by toramo            #+#    #+#             */
/*   Updated: 2023/11/27 10:25:04 by toramo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	p_size(t_stack **x, int pnum)
{
	int	i;
	int	psize;

	i = 0;
	psize = 0;
	while (i < arrsize(x))
	{
		if (x[i]->pnum == pnum)
			psize++;
		i++;
	}
	return (psize);
}

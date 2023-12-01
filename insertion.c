/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toramo <toramo.student@hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:12:46 by toramo            #+#    #+#             */
/*   Updated: 2023/12/01 12:13:11 by toramo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	distance_a(int *dup, int size, int n)
{
	int	i;

	i = 0;
	if (n < arr_find_smallest(dup, size) || n > arr_find_largest(dup, size))
	{
		while (dup[0] != arr_find_smallest(dup, size))
			i = i + rotate_arr(dup, size);
	}
	else
		while (!(n < dup[0] && n > dup[size - 1]))
			i = i + rotate_arr(dup, size);
	if (i <= size / 2)
		return (i);
	else
		return (i - size);
}

int	distance_b(int *dup, int size, int n)
{
	int	i;

	i = 0;
	while (!(n > dup[0] && n < dup[size - 1]))
		i = i + rotate_arr(dup, size);
	if (i <= size / 2)
		return (i);
	else
		return (i - size);
}

void	find_place_a(t_stack **a, t_stack **b, int n, char **inst)
{
	int	*dup;
	int	distance;

	if (arrsize(a) != 0)
	{
		dup = dup_arr_a(a, b, inst);
		distance = distance_a(dup, arrsize(a), n);
		free(dup);
		if (distance > 0)
			rotate_a(a, b, inst, distance);
		else if (distance < 0)
			rrotate_a(a, b, inst, distance * -1);
	}
}

void	find_place_b2(t_stack **a, t_stack **b, t_stack *n, char **inst)
{
	int	*dup;
	int	distance;

	dup = dup_arr_b(a, b, inst);
	distance = distance_b(dup, arrsize(b), n->n);
	free(dup);
	if (distance > 0)
		rotate_b(a, b, inst, distance);
	else if (distance < 0)
		rrotate_b(a, b, inst, distance * -1);
	push_b(a, b, inst);
}

void	find_place_b(t_stack **a, t_stack **b, t_stack *n, char **inst)
{
	if (p_size(b, n->pnum + 8) == 0)
		push_b(a, b, inst);
	else if (p_size(b, n->pnum + 8) == 1)
	{
		if (a[0]->n < b[0]->n)
			rotate_b(a, b, inst, 1);
		push_b(a, b, inst);
	}
	else if (p_size(b, n->pnum + 8) >= 2 && n->n < pnum_min_x(b, n->pnum + 8))
	{
		while (b[arrsize(b) - 1]->n != pnum_min_x(b, n->pnum + 8))
			rotate_b(a, b, inst, 1);
		push_b(a, b, inst);
	}
	else if (p_size(b, n->pnum + 8) >= 2 && n->n > pnum_max_x(b, n->pnum + 8))
	{
		while (b[0]->n != pnum_max_x(b, n->pnum + 8))
			rrotate_b(a, b, inst, 1);
		push_b(a, b, inst);
	}
	else if (p_size(b, n->pnum + 8) >= 2)
		find_place_b2(a, b, n, inst);
}

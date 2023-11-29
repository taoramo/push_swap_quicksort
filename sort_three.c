/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toramo <toramo.student@hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:19:13 by toramo            #+#    #+#             */
/*   Updated: 2023/11/27 15:21:39 by toramo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_a2(t_stack **a, t_stack **b, char **inst)
{
	if (a[2]->n < a[0]->n && a[0]->n < a[1]->n)
	{
		rotate_a(a, b, inst, 1);
		swap_a(a, b, inst);
		rrotate_a(a, b, inst, 1);
		swap_a(a, b, inst);
		set_three_pnum(a);
	}
	else if (a[2]->n < a[1]->n && a[1]->n < a[0]->n)
	{
		swap_a(a, b, inst);
		rotate_a(a, b, inst, 1);
		swap_a(a, b, inst);
		rrotate_a(a, b, inst, 1);
		swap_a(a, b, inst);
		set_three_pnum(a);
	}
}

void	sort_three_a(t_stack **a, t_stack**b, char **inst)
{
	if (a[0]->n < a[1]->n && a[1]->n < a[2]->n)
		set_three_pnum(a);
	else if (a[0]->n < a[2]->n && a[2]->n < a[1]->n)
	{
		rotate_a(a, b, inst, 1);
		swap_a(a, b, inst);
		rrotate_a(a, b, inst, 1);
		set_three_pnum(a);
	}
	else if (a[1]->n < a[0]->n && a[0]->n < a[2]->n)
	{
		swap_a(a, b, inst);
		set_three_pnum(a);
	}
	else if (a[1]->n < a[2]->n && a[2]->n < a[0]->n)
	{
		swap_a(a, b, inst);
		rotate_a(a, b, inst, 1);
		swap_a(a, b, inst);
		rrotate_a(a, b, inst, 1);
		set_three_pnum(a);
	}
	else
		sort_three_a2(a, b, inst);
}

void	push_two_a(t_stack **a, t_stack **b, char **inst)
{
	push_a(a, b, inst);
	push_a(a, b, inst);
}

void	sort_three_b2(t_stack **a, t_stack **b, char **inst)
{
	if (b[1]->n > b[2]->n && b[2]->n > b[0]->n)
	{
		rotate_b(a, b, inst, 1);
		push_two_a(a, b, inst);
		rrotate_b(a, b, inst, 1);
		push_a(a, b, inst);
	}
	else if (b[2]->n > b[0]->n && b[0]->n > b[1]->n)
	{
		rotate_b(a, b, inst, 1);
		swap_b(a, b, inst);
		push_a(a, b, inst);
		rrotate_b(a, b, inst, 1);
		push_two_a(a, b, inst);
	}
	else if (b[2]->n > b[1]->n && b[1]->n > b[0]->n)
	{
		rotate_b(a, b, inst, 1);
		swap_b(a, b, inst);
		push_two_a(a, b, inst);
		rrotate_b(a, b, inst, 1);
		push_a(a, b, inst);
	}
	set_three_pnum(a);
}

void	sort_three_b(t_stack **a, t_stack **b, char **inst)
{
	if (b[0]->n > b[1]->n && b[1]->n > b[2]->n)
	{
		push_a(a, b, inst);
		push_a(a, b, inst);
		push_a(a, b, inst);
		set_three_pnum(a);
	}
	else if (b[0]->n > b[2]->n && b[2]->n > b[1]->n)
	{
		push_a(a, b, inst);
		swap_b(a, b, inst);
		push_a(a, b, inst);
		push_a(a, b, inst);
		set_three_pnum(a);
	}
	else if (b[1]->n > b[0]->n && b[0]->n > b[2]->n)
	{
		swap_b(a, b, inst);
		push_a(a, b, inst);
		push_a(a, b, inst);
		push_a(a, b, inst);
		set_three_pnum(a);
	}
	else
		sort_three_b2(a, b, inst);
}

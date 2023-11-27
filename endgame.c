/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endgame.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toramo <toramo.student@hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:17:56 by toramo            #+#    #+#             */
/*   Updated: 2023/11/27 15:19:17 by toramo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a, t_stack**b, char **inst, int pnum)
{
	int	i;

	i = 0;
	while (i < arrsize(a))
	{
		if (a[i]->pnum == pnum)
			sort_three_a(a, b, inst);
		i++;
	}
	i = 0;
	while (i < arrsize(b))
	{
		if (b[i]->pnum == pnum)
			sort_three_b(a, b, inst);
		i++;
	}
}

void	small_arrays2(t_stack **a, t_stack **b, char **inst, int pnum)
{
	if (b[0])
	{
		if (p_size(a, b, pnum) == 1 && b[0]->pnum == pnum)
			push_a(a, b, inst);
		if (p_size(a, b, pnum) == 2 && a[0]->pnum == pnum
			&& a[1]->n == a[0]->n + 1)
		{
			push_a(a, b, inst);
			push_a(a, b, inst);
			a[0]->pnum = 0;
			a[1]->pnum = 0;
		}
		if (p_size(a, b, pnum) == 2 && a[0]->pnum == pnum
			&& a[0]->n == a[1]->n + 1)
		{
			swap_a(a, b, inst);
			push_a(a, b, inst);
			push_a(a, b, inst);
			a[0]->pnum = 0;
			a[1]->pnum = 0;
		}
	}
}

void	small_arrays(t_stack **a, t_stack **b, char **inst, int pnum)
{
	if (p_size(a, b, pnum) == 3)
		sort_three(a, b, inst, pnum);
	if (a[0])
	{
		if (p_size(a, b, pnum) == 1 && a[0]->pnum == pnum && a[1] == a[0] + 1)
			a[0]->pnum = 0;
		if (p_size(a, b, pnum) == 2 && a[0]->pnum == pnum
			&& a[1]->n == a[0]->n + 1)
		{
			a[0]->pnum = 0;
			a[1]->pnum = 0;
		}
		if (p_size(a, b, pnum) == 2 && a[0]->pnum == pnum
			&& a[0]->n == a[1]->n + 1)
		{
			swap_a(a, b, inst);
			a[0]->pnum = 0;
			a[1]->pnum = 0;
		}
	}
	small_arrays2(a, b, inst, pnum);
}

void	optimize(char **inst)
{
	int	i;

	i = 0;
	while (inst[i + 1])
	{
		if ((!ft_strncmp("ra", inst[i], 2) && !ft_strncmp("rb", inst[i + 1], 2))
			|| (!ft_strncmp("ra", inst[i + 1], 2)
				&& !ft_strncmp("rb", inst[i], 2)))
		{
			ft_strlcpy(inst[i], "rr", 3);
			ft_strlcpy(inst[i + 1], "na", 3);
		}
		if ((!ft_strncmp("rra", inst[i], 2)
				&& !ft_strncmp("rrb", inst[i + 1], 2))
			|| (!ft_strncmp("rra", inst[i + 1], 2)
				&& !ft_strncmp("rrb", inst[i], 2)))
		{
			ft_strlcpy(inst[i], "rx", 3);
			ft_strlcpy(inst[i + 1], "na", 3);
		}
		i++;
	}
}

void	endgame(t_stack **a, t_stack **b, char **inst)
{
	int	i;

	i = 0;
//	optimize(inst);
	while (inst[i])
	{
//		if (!ft_strncmp("rx", inst[i], 2))
//			ft_printf("rrr\n");
//		else if (ft_strncmp("na", inst[i], 2))
		ft_printf("%s\n", inst[i]);
		i++;
	}
	(void)a;
	(void)b;
	print_arrays(a, b);
	free_everything(a, b, inst);
}

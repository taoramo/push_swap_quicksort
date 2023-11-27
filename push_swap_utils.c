/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toramo <toramo.student@hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:57:42 by toramo            #+#    #+#             */
/*   Updated: 2023/11/27 14:57:43 by toramo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack **a)
{
	int	i;
	int	size;

	i = 0;
	size = arrsize(a);
	while (i <= size - 2)
	{
		if (a[i]->n > a[i + 1]->n)
			return (0);
		i++;
	}
	return (1);
}

void	add_instruction(t_stack **a, t_stack **b, char *str, char **inst)
{
	int	i;

	i = 0;
	while (inst[i])
		i++;
	inst[i] = ft_strdup(str);
	if (!inst[i])
		free_everything(a, b, inst);
}

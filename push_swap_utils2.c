/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toramo <toramo.student@hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:26:35 by toramo            #+#    #+#             */
/*   Updated: 2023/12/11 11:26:36 by toramo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_split(char **split)
{
	int	i;

	if (!split)
		return (0);
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (0);
}

void	free_everything(t_stack **a, t_stack **b, char **inst)
{
	int	i;

	i = 0;
	if (a)
	{
		while (a[i])
			free(a[i++]);
		free(a);
	}
	i = 0;
	if (b)
	{
		while (b[i] && b)
			free(b[i++]);
		free(b);
	}
	i = 0;
	if (inst)
	{
		while (inst[i])
			free(inst[i++]);
		free(inst);
	}
	exit(0);
}

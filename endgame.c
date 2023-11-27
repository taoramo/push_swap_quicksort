/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endgame.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toramo <toramo.student@hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:01:57 by toramo            #+#    #+#             */
/*   Updated: 2023/11/27 11:22:05 by toramo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	optimize(inst);
	while (inst[i])
	{
		if (!ft_strncmp("rx", inst[i], 2))
			ft_printf("rrr\n");
		else if (ft_strncmp("na", inst[i], 2))
			ft_printf("%s\n", inst[i]);
		i++;
	}
	(void)a;
	(void)b;
//	print_arrays(a, b, argc);
//	free_everything(a, b, inst);
}

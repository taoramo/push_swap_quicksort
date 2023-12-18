/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toramo <toramo.student@hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:09:33 by toramo            #+#    #+#             */
/*   Updated: 2023/12/01 12:09:35 by toramo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	**a;
	t_stack	**b;
	char	**inst;
	int		size;

	if (argc < 2 || !check_input(argc, argv))
		return (1);
	a = make_array(argc, argv, 1);
	b = make_array(argc, argv, 0);
	if (!a || !b)
		free_everything(a, b, 0);
	size = 0;
	if (a)
	{
		while (a[size])
			size++;
	}
	inst = ft_calloc(sizeof(char *), size * size);
	if (!inst)
		free_everything(a, b, inst);
	if (!is_sorted(a))
		phase_one(a, b, inst);
	else
		free_everything(a, b, inst);
}

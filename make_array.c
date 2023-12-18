/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toramo <toramo.student@hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:58:54 by toramo            #+#    #+#             */
/*   Updated: 2023/12/01 12:58:55 by toramo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_structs2(t_stack **arr, int size, char **ints, int *input)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (i < size)
	{
		arr[i] = (t_stack *)ft_calloc(sizeof(t_stack), 1);
		arr[i]->n = ft_rank(ft_atoi(ints[i]), input, size);
		i++;
	}
}

t_stack	**make_structs(t_stack **arr, int size, char **ints, int intsissplit)
{
	int	*input;
	int	i;

	input = ft_calloc(sizeof(int), size);
	if (!input)
	{
		if (intsissplit)
			free_split(ints);
		return (0);
	}
	i = 0;
	while (i < size)
	{
		input[i] = ft_atoi(ints[i]);
		i++;
	}
	if (!check_duplicates(input, size))
	{
		free(input);
		free_everything(arr, 0, 0);
		arr = 0;
	}
	make_structs2(arr, size, ints, input);
	free(input);
	return (arr);
}

t_stack	**split_array(char **argv, int *size)
{
	char	**ints;
	int		i;
	t_stack	**arr;

	ints = ft_split(argv[1], ' ');
	i = 0;
	if (!ints)
		return (0);
	while (ints[i])
	{
		if (!ft_strlen(ints[i]))
			return (0);
		i++;
	}
	*size = i;
	arr = (t_stack **)ft_calloc(sizeof(t_stack *), i + 1);
	free_split(ints);
	return (arr);
}

t_stack	**make_array(int argc, char **argv, int flag)
{
	t_stack	**arr;
	char	**ints;
	int		size;
	int		intsissplit;

	intsissplit = 0;
	if (argc > 2)
	{
		arr = (t_stack **)ft_calloc(sizeof(t_stack *), argc);
		ints = &argv[1];
		size = argc - 1;
	}
	if (argc == 2)
	{
		arr = split_array(argv, &size);
		ints = ft_split(argv[1], ' ');
		intsissplit = 1;
		if (!ints)
			return (0);
	}
	if (flag)
		make_structs(arr, size, ints, intsissplit);
	if (intsissplit)
		free_split(ints);
	return (arr);
}

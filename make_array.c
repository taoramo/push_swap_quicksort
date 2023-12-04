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

int	check_duplicates(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (arr[i] == arr[j] && i != j)
			{
				write(2, "Error\n", 6);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_rank(int n, int *input, int size)
{
	int	smaller;
	int	i;

	i = 0;
	smaller = 0;
	while (i < size)
	{
		if (n > input[i])
			smaller++;
		i++;
	}
	return (smaller + 1);
}

t_stack	**make_structs(t_stack **arr, int size, char **ints)
{
	int	*input;
	int	i;

	input = ft_calloc(sizeof(int), size);
	if (!input)
		return (0);
	i = 0;
	while (i < size)
	{
		input[i] = ft_atoi(ints[i]);
		i++;
	}
	if (!check_duplicates(input, size))
		return (0);
	i = 0;
	while (i < size)
	{
		arr[i] = (t_stack *)ft_calloc(sizeof(t_stack), 1);
		arr[i]->n = ft_rank(ft_atoi(ints[i]), input, size);
		i++;
	}
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
	}
	if (flag == 0)
		return (arr);
	return (make_structs(arr, size, ints));
}

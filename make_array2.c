/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_array2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toramo <toramo.student@hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:43:28 by toramo            #+#    #+#             */
/*   Updated: 2023/12/15 12:43:29 by toramo           ###   ########.fr       */
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

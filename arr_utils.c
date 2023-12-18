/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toramo <toramo.student@hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:09:11 by toramo            #+#    #+#             */
/*   Updated: 2023/12/01 12:09:13 by toramo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*dup_arr_a(t_stack **a, t_stack **b, char **inst)
{
	int	*dup;
	int	i;

	dup = ft_calloc(sizeof(int), arrsize(a));
	if (!dup)
		free_everything(a, b, inst);
	i = 0;
	while (i < arrsize(a))
	{
		dup[i] = a[i]->n;
		i++;
	}
	return (dup);
}

int	*dup_arr_b(t_stack **a, t_stack **b, char **inst)
{
	int	*dup;
	int	i;

	dup = ft_calloc(sizeof(int), arrsize(b));
	if (!dup)
		free_everything(a, b, inst);
	i = 0;
	while (i < arrsize(b))
	{
		dup[i] = b[i]->n;
		i++;
	}
	return (dup);
}

int	arr_find_largest(int *arr, int size)
{
	int	largest;
	int	i;

	i = 0;
	largest = -2147483648;
	while (i < size)
	{
		if (arr[i] > largest)
			largest = arr[i];
		i++;
	}
	return (largest);
}

int	arr_find_smallest(int *arr, int size)
{
	int	smallest;
	int	i;

	i = 0;
	smallest = 2147483647;
	while (i < size)
	{
		if (arr[i] < smallest)
			smallest = arr[i];
		i++;
	}
	return (smallest);
}

int	rotate_arr(int *arr, int size)
{
	int	temp;
	int	i;

	i = 0;
	temp = arr[0];
	while (i < size - 1)
	{
		arr[i] = arr[i + 1];
		i++;
	}
	arr[size - 1] = temp;
	return (1);
}

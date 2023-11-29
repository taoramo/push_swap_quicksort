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

int	distance_a(int *dup, int size, int n)
{
	int	i;

	i = 0;
	if (n < arr_find_smallest(dup, size) || n > arr_find_largest(dup, size))
	{
		while (dup[0] != arr_find_smallest(dup, size))
			i = i + rotate_arr(dup, size);
	}
	else
		while (!(n < dup[0] && n > dup[size - 1]))
			i = i + rotate_arr(dup, size);
	if (i <= size / 2)
		return (i);
	else
		return (i - size);
}

int	distance_b(int *dup, int size, int n)
{
	int	i;

	i = 0;
	if (n < arr_find_smallest(dup, size) || n > arr_find_largest(dup, size))
	{
		while (dup[0] != arr_find_largest(dup, size))
			i = i + rotate_arr(dup, size);
	}
	else
		while (!(n > dup[0] && n < dup[size - 1]))
			i = i + rotate_arr(dup, size);
	if (i <= size / 2)
		return (i);
	else
		return (i - size);
}

void	find_place_a(t_stack **a, t_stack **b, int n, char **inst)
{
	int	*dup;
	int	distance;

	if (arrsize(a) != 0)
	{
		dup = dup_arr_a(a, b, inst);
		distance = distance_a(dup, arrsize(a), n);
		free(dup);
		if (distance > 0)
			rotate_b(a, b, inst, distance);
		else if (distance < 0)
			rrotate_b(a, b, inst, distance);
	}
}

void	find_place_b(t_stack **a, t_stack **b, int n, char **inst)
{
	int	*dup;
	int	distance;

	if (arrsize(b) != 0)
	{
		dup = dup_arr_b(a, b, inst);
		distance = distance_b(dup, arrsize(b), n);
		free(dup);
		if (distance > 0)
			rotate_b(a, b, inst, distance);
		else if (distance < 0)
			rrotate_b(a, b, inst, distance * -1);
	}
}

/*
void	push_swap(t_stack *a, t_stack *b, char **inst, int argc)
{
	int		pivot;
	int		rounds;

	rounds = a->size / 2;
	pivot = argc - 1 - a->size / 2;
	if (a->size == 4)
		pivot--;
	while (rounds && !is_sorted(a) && a->size > 3)
	{
		while (a->n[0] < pivot && rounds)
		{
			find_place_b(a, b, a->n[0], inst);
			push_b(a, b, inst);
			rounds--;
		}
		if (a->n[0] > pivot && a->n[1] > pivot && a->n[0] > a->n[1])
			swap_a(a, b, inst);
		else
			rotate_a(a, b, inst, 1);
	}
	if (!is_sorted(a) && a->size > 3)
		push_swap(a, b, inst, argc);
	else
		endgame(a, b, inst, argc);
}*/

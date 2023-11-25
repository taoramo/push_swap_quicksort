#include "push_swap.h"

int	arrsize(t_stack **a)
{
	int	i;

	i = 0;
	while (a[i])
		i++;
	return (i);
}

void	rotate_a(t_stack **a, t_stack **b, char **inst, int times)
{
	t_stack *temp;
	int		i;
	int		size;

	size = arrsize(a);
	while (times && a[0])
	{
		temp = a[0];
		i = 1;
		while (i <= size - 1)
		{
			a[i - 1] = a[i];
			i++;
		}
		a[size - 1] = temp;
		add_instruction(a, b, "ra", inst);
		times--;
	}
}

void	rotate_b(t_stack **a, t_stack **b, char **inst, int times)
{
	t_stack *temp;
	int		i;
	int		size;

	size = arrsize(b);
	while (times && b[0])
	{
		temp = b[0];
		i = 1;
		while (i <= size - 1)
		{
			b[i - 1] = b[i];
			i++;
		}
		b[size - 1] = temp;
		add_instruction(a, b, "rb", inst);
		times--;
	}
}

void	rrotate_a(t_stack **a, t_stack **b, char **inst, int times)
{
	t_stack *temp;
	int		i;
	int		size;

	size = arrsize(a);
	while (times && size != 0)
	{
		temp = a[size - 1];
		i = size - 2;
		while (i >= 0)
		{
			a[i + 1] = a[i];
			i--;
		}
		a[0] = temp;
		add_instruction(a, b, "rra", inst);
		times--;
	}
}

void	rrotate_b(t_stack **a, t_stack **b, char **inst, int times)
{
	t_stack *temp;
	int		i;
	int		size;

	size = arrsize(b);
	while (times && size != 0)
	{
		temp = b[size - 1];
		i = size - 2;
		while (i >= 0)
		{
			b[i + 1] = b[i];
			i--;
		}
		b[0] = temp;
		add_instruction(a, b, "rrb", inst);
		times--;
	}
}

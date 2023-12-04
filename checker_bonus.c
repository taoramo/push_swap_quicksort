#include "push_swap.h"

void	execute_inst2(t_stack **a, t_stack **b, char *inst)
{
	if (!ft_strncmp("rrr\n", inst, 4))
	{
		rrotate_a(a, b, 0, 1);
		rrotate_b(a, b, 0, 1);
	}
	if (!ft_strncmp("sa\n", inst, 3))
		swap_a(a, b, 0);
	if (!ft_strncmp("sb\n", inst, 3))
		swap_b(a, b, 0);
	if (!ft_strncmp("ss\n", inst, 3))
	{
		swap_b(a, b, 0);
		swap_a(a, b, 0);
	}
	if (!ft_strncmp("pa\n", inst, 3))
		push_a(a, b, 0);
	if (!ft_strncmp("pb\n", inst, 3))
		push_b(a, b, 0);
}

void	execute_inst( t_stack **a, t_stack **b)
{
	char	*inst;

	inst = "";
	while (inst)
	{
		if (!ft_strncmp("ra\n", inst, 3))
			rotate_a(a, b, 0, 1);
		if (!ft_strncmp("rb\n", inst, 3))
			rotate_b(a, b, 0, 1);
		if (!ft_strncmp("rr\n", inst, 3))
		{
			rotate_a(a, b, 0, 1);
			rotate_b(a, b, 0, 1);
		}
		if (!ft_strncmp("rra\n", inst, 4))
			rrotate_a(a, b, 0, 1);
		if (!ft_strncmp("rrb\n", inst, 4))
			rrotate_b(a, b, 0, 1);
		execute_inst2(a, b, inst);
		inst = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_stack	**a;
	t_stack	**b;

	if (argc < 2 || !check_input(argc, argv))
		return (1);
	a = make_array(argc, argv, 1);
	b = make_array(argc, argv, 0);
	if (!a || !b)
		free_everything(a, b, 0);
	execute_inst(a, b);
	if (is_sorted(a) && !arrsize(b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

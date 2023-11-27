#include "push_swap.h"

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

t_stack	**make_array(int argc, char **argv)
{
	t_stack	**arr;
	int		*input;
	int		i;

	i = 0;
	arr = (t_stack **)ft_calloc(sizeof(t_stack *), argc);
	if (!arr)
		return (0);
	input = ft_calloc(sizeof(int), argc - 1);
	if (!input)
		return (0);
	while (i < argc - 1)
	{
		if (argv)
			input[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	i = 0;
	while (i < argc - 1)
	{
		arr[i] = (t_stack *)ft_calloc(sizeof(t_stack), 1);
		if (argv)
			arr[i]->n = ft_rank(ft_atoi(argv[i + 1]), input, argc - 1);
		else
			arr[i] = 0;
		i++;
	}
	return (arr);
}

void	free_everything(t_stack **a, t_stack **b, char **inst)
{
	int	i;

	i = 0;
	while (a[i] && a)
	{
		free(a[i]);
		i++;
	}
	i = 0;
	while (b[i + 1] && b)
	{
		free(b[i]);
		i++;
	}
	if (a)
		free(a);
	if (b)
		free(b);
	i = 0;
	while (inst[i] && inst)
	{
		free(inst[i]);
		i++;
	}
	free(inst);
	exit(0);
}

void	check_input(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc - 1)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				ft_printf("Error.\n");
				exit(1);
			}
			j++;
		}
		if (!ft_strlen(argv[i]))
		{
			ft_printf("Error.\n");
			exit(1);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	**a;
	t_stack	**b;
	char	**inst;

	if (argc < 2)
		return (1);
	check_input(argc, argv);
	a = make_array(argc, argv);
	b = make_array(argc, 0);
	inst = ft_calloc(sizeof(char *), argc * argc);
	if (!a || !b || !inst)
		free_everything(a, b, inst);
	phase_one(a, b, inst);
}

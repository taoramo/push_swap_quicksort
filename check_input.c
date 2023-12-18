/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toramo <toramo.student@hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:12:33 by toramo            #+#    #+#             */
/*   Updated: 2023/12/01 12:12:35 by toramo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_ints(int argc, char **argv)
{
	char	**ints;
	int		i;
	int		ret;

	ret = 1;
	if (argc == 2)
		ints = ft_split(argv[1], ' ');
	else
		ints = &argv[1];
	if (!ints)
		return (0);
	i = 0;
	while (i < argc - 1)
	{
		if (ft_atoi(ints[i]) == 0 && ft_strncmp("0", ints[i], 64))
			ret = 0;
		i++;
	}
	if (!ret)
		write(2, "Error\n", 6);
	if (ints && argc == 2)
		free_split(ints);
	return (ret);
}

void	check_str(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((!ft_isdigit(s[i]) && s[i] != '-' && s[i] != ' '))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		if (i > 0)
		{
			if ((s[i] == '-' && s[i - 1] != ' ')
				|| (s[i] == ' ' && s[i - 1] == '-'))
			{
				write(2, "Error\n", 6);
				exit(1);
			}
		}
		i++;
	}
}

int	check_mult_str(int argc, char **argv)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	while (i < argc - 1)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(ft_isdigit(argv[i][j]) || argv[i][j] == '-'
					|| argv[i][j] == ' ') || (argv[i][j] == '-' && j != 0))
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			j++;
		}
		i++;
	}
	return (check_ints(argc, argv));
}

int	check_single_str(int argc, char **argv)
{
	if (argv[1][0] == 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	check_str(argv[1]);
	return (check_ints(argc, argv));
}

int	check_input(int argc, char **argv)
{
	if (argc == 2)
		return (check_single_str(argc, argv));
	else
		return (check_mult_str(argc, argv));
}

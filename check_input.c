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
		ft_printf("Error.\n");
	if (ints && argc == 2)
		free_split(ints);
	return (ret);
}

int	check_mult_str(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc - 1)
	{
		j = 1;
		while (argv[i][j])
		{
			if ((!ft_isdigit(argv[i][1]) && argv[i][1] != '-')
				|| !ft_isdigit(argv[i][j]))
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
	return (check_ints(argc, argv));
}

int	check_single_str(int argc, char **argv)
{
	int	i;

	i = 0;
	while (argv[1][i])
	{
		if (!ft_isdigit(argv[1][i]) && argv[1][i] != '-' && argv[1][i] != ' ')
		{
			ft_printf("Error.\n");
			exit(1);
		}
		i++;
	}
	return (check_ints(argc, argv));
}

int	check_input(int argc, char **argv)
{
	if (argc == 2)
		return (check_single_str(argc, argv));
	else
		return (check_mult_str(argc, argv));
}

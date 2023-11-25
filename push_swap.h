/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toramo <toramo.student@hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:25:03 by toramo            #+#    #+#             */
/*   Updated: 2023/11/20 15:33:44 by toramo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "ft_printf.h"

typedef struct s_stack {
	int	n;
	int	pnum;
	int	psize;
	int	size;
	int	pivot;
}	t_stack;
void	phase_one(t_stack **a, t_stack **b, char **inst, int argc);
t_stack	**make_array(int argc, char **argv);
void	free_everything(t_stack **a, t_stack **b, char **inst);
int		is_sorted(t_stack **a);
int		arrsize(t_stack **a);
void	find_place_a(t_stack *a, t_stack *b, int n, char **inst);
void	find_place_b(t_stack *a, t_stack *b, int n, char **inst);
void	endgame(t_stack *a, t_stack *b, char **inst, int argc);
void	swap_a(t_stack **a, t_stack **b, char **inst);
void	swap_b(t_stack **a, t_stack **b, char **inst);
void	rotate_a(t_stack **a, t_stack **b, char **inst, int times);
void	rotate_b(t_stack **a, t_stack **b, char **inst, int times);
void	rrotate_a(t_stack **a, t_stack **b, char **inst, int times);
void	rrotate_b(t_stack **a, t_stack **b, char **inst, int times);
void	add_instruction(t_stack **a, t_stack **b, char *str, char **inst);
int		is_largest(int n, t_stack *b);
int		is_smallest(int n, t_stack *b);
void	push_swap(t_stack *a, t_stack *b, char **inst, int argc);
void	bubble_a(t_stack *a, t_stack *b, char **inst, int argc);
void	push_a(t_stack **a, t_stack **b, char **inst);
void	push_b(t_stack **a, t_stack **b, char **inst);
void	print_arrays(t_stack *a, t_stack *b, int argc);
#endif

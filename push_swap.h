/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toramo <toramo.student@hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:25:03 by toramo            #+#    #+#             */
/*   Updated: 2023/11/27 17:05:46 by toramo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "ft_printf.h"

typedef struct s_stack {
	int	n;
	int	pnum;
}	t_stack;
int		pnum_min_x(t_stack **x, int pnum);
int		pnum_max_x(t_stack **x, int pnum);
int		pnum_median_x(t_stack **x, int pnum);
int		pnum_median(t_stack **a, t_stack **b, int pnum);
int		find_largest(t_stack **a);
void	reset_rotation_a(t_stack **a, t_stack **b, char **inst, int pnum);
void	reset_rotation_b(t_stack **a, t_stack **b, char **inst, int pnum);
void	reset_rotation_b_phaseone(t_stack **a,
			t_stack **b, char **inst, int *pnum);
void	phase_one(t_stack **a, t_stack **b, char **inst);
void	phase_two(t_stack **a, t_stack **b, char **inst, int *pnum);
t_stack	**make_array(int argc, char **argv, int flag);
void	free_everything(t_stack **a, t_stack **b, char **inst);
int		is_sorted(t_stack **a);
int		arrsize(t_stack **a);
void	endgame(t_stack **a, t_stack **b, char **inst);
void	swap_a(t_stack **a, t_stack **b, char **inst);
void	swap_b(t_stack **a, t_stack **b, char **inst);
void	rotate_a(t_stack **a, t_stack **b, char **inst, int times);
void	rotate_b(t_stack **a, t_stack **b, char **inst, int times);
void	rrotate_a(t_stack **a, t_stack **b, char **inst, int times);
void	rrotate_b(t_stack **a, t_stack **b, char **inst, int times);
void	add_instruction(t_stack **a, t_stack **b, char *str, char **inst);
void	push_swap(t_stack *a, t_stack *b, char **inst, int argc);
void	push_a(t_stack **a, t_stack **b, char **inst);
void	push_b(t_stack **a, t_stack **b, char **inst);
void	print_arrays(t_stack **a, t_stack **b);
void	set_three_pnum(t_stack **a);
void	sort_three(t_stack **a, t_stack **b, char **inst, int pnum);
void	sort_three_a(t_stack **a, t_stack **b, char **inst);
void	sort_three_b(t_stack **a, t_stack **b, char **inst);
int		p_size(t_stack **a, int pnum);
void	small_arrays(t_stack **a, t_stack **b, char **argv, int pnum);
int		*dup_arr_a(t_stack **a, t_stack **b, char **inst);
int		*dup_arr_b(t_stack **a, t_stack **b, char **inst);
int		arr_find_largest(int *arr, int size);
int		arr_find_smallest(int *arr, int size);
int		rotate_arr(int *arr, int size);
int		distance_a(int *dup, int size, int n);
int		distance_b(int *dup, int size, int n);
void	find_place_a(t_stack **a, t_stack **b, int n, char **inst);
void	find_place_b(t_stack **a, t_stack **b, t_stack *n, char **inst);
void	reset_place_b(t_stack **a, t_stack **b, int pnum, char **inst);
int		pnum_selector(t_stack **a, t_stack **b);
void	insert_a(t_stack **a, t_stack **b, char **inst);
void	insert_b(t_stack **a, t_stack **b, char **inst, int *pnum);
int		check_ints(int argc, char **argv);
int		check_mult_str(int argc, char **argv);
int		check_single_str(int argc, char **argv);
int		check_input(int argc, char **argv);
void	partition_init2(t_stack **a, int pnum);
void	partition_init4(t_stack **a, int pnum);
void	partition_init6(t_stack **a, int pnum);
int		free_split(char **split);
int		check_duplicates(int *arr, int size);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <oalvera@student.21-school.r       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:38:10 by oalvera           #+#    #+#             */
/*   Updated: 2022/02/19 16:38:32 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int	data;
	int	step_a;
	int	step_b;
	int	step_sum;
	int	opt_way;
	int	sort_numb;
}				t_stack;

typedef struct s_stacks
{
	int		num_of_a;
	int		num_of_b;
	int		min;

	t_stack	**a;
	t_stack	**b;
}				t_stacks;

int		find_max(t_stacks *v_n);
int		find_min(t_stacks *v_n);
void	sort_two(t_stacks *valid_num);
void	sort_three(t_stacks *valid_num);
void	sort_four_or_five(t_stacks *valid_num);
int		cleaning_b(t_stacks *valid_num, int i);
int		cleaning(t_stacks *valid_num, int i);
int		free_stacks(t_stacks *valid_num);
int		uniq_validator(int *nums, int size);
int		arg_validator(char **s, int size, int *nums);
int		validate_and_init(int argc, char **argv, t_stacks *valid_num, int size);
int		sort_checker(t_stacks *valid_num, int size);
long	ft_atoi(char *str);
long	ft_error(int i);
int		init_stack_a(int *nums, int size, t_stacks *valid_num);
int		init_stack_b(t_stacks *valid_num, int size);
int		ev_b_rr(t_stacks *v_n, int sort_numb);
int		ev_b_rrr(t_stacks *v_n, int s_n);
int		compration(int sum_rr, int sum_rrr, int sum_mix);
void	i_v(t_stack *valid_num, int i, int b, int way);
void	stack_work(t_stacks *v, int i);
void	f_sort(t_stacks *valid_num);
int		part(int *sort_mas, int index, int key);
void	sort_arr(int *sort_mas, int index, int size);
void	sort_elem(t_stacks *valid_num, int size, int i);
void	sa(t_stacks *valid_num);
void	sb(t_stacks *valid_num);
void	ss(t_stacks *valid_num);
void	pa(t_stacks *valid_num);
void	pb(t_stacks *valid_num);
void	ra(t_stacks *valid_num);
void	rb(t_stacks *valid_num);
void	rra(t_stacks *valid_num);
void	rrb(t_stacks *valid_num);
void	rr(t_stacks *valid_num);
void	rrr(t_stacks *valid_num);
int		sum_step(int a, int b, int i);
int		find_place_b(t_stacks *v_n, int s, int m, int x);
void	push_w_1(t_stacks *v_n, int r);
void	push_w_2(t_stacks *v_n, int r);
void	push_w_3(t_stacks *v_n, int r);
void	push_w_4(t_stacks *v_n, int r);
void	push_to_b(t_stacks *v_n, int r);
void	push_to_a(t_stacks *v_n, int i);

#endif

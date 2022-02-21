/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulation_func.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <oalvera@student.21-school.r       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:40:03 by oalvera           #+#    #+#             */
/*   Updated: 2022/02/19 16:40:04 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ev_b_rr(t_stacks *v_n, int sort_numb)
{
	int	i;

	i = find_place_b(v_n, sort_numb, 2147483647, -2147483647);
	if (i == 0)
	{
		if (sort_numb < v_n->b[0]->sort_numb)
			return (1);
		else
			return (0);
	}
	else if (i > 0)
		return (i + 1);
	else
		return (i * (-1));
}

int	ev_b_rrr(t_stacks *v_n, int s_n)
{
	int	i;

	i = find_place_b(v_n, s_n, 2147483647, -2147483647);
	if (i == 0)
	{
		if (s_n < v_n->b[0]->sort_numb)
			return (v_n->num_of_b - 1);
		else
			return (0);
	}
	if (i > 0)
		return (v_n->num_of_b - (i + 1));
	else
		return (v_n->num_of_b - (-1) * i);
}

int	compration(int sum_rr, int sum_rrr, int sum_mix)
{
	if (sum_rr >= sum_rrr)
	{
		if (sum_rrr <= sum_mix)
			return (sum_rrr);
		else
			return (sum_mix);
	}
	else if (sum_rr <= sum_mix)
		return (sum_rr);
	else
		return (sum_mix);
}

void	i_v(t_stack *valid_num, int i, int b, int way)
{
	valid_num->step_a = i;
	valid_num->opt_way = way;
	valid_num->step_b = b;
}

void	push_to_a(t_stacks *v_n, int i)
{
	int	max;
	int	remember;

	max = 0;
	while (++i < v_n->num_of_b)
	{
		if (v_n->b[i]->sort_numb >= max)
		{
			max = v_n->b[i]->sort_numb;
			remember = i;
		}
	}
	i = -1;
	if (remember <= v_n->num_of_b / 2)
	{
		while (++i < remember)
			rb(v_n);
	}
	else
	{
		while (++i < v_n->num_of_b - remember)
			rrb(v_n);
	}
	while (v_n->num_of_b > 0)
		pa(v_n);
}

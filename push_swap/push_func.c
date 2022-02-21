/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <oalvera@student.21-school.r       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:40:12 by oalvera           #+#    #+#             */
/*   Updated: 2022/02/19 16:40:13 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_w_1(t_stacks *v_n, int r)
{
	int	count;
	int	i;
	int	diff_a;
	int	diff_b;

	i = 0;
	diff_a = v_n->a[r]->step_a - v_n->a[r]->step_b;
	diff_b = v_n->a[r]->step_b - v_n->a[r]->step_a;
	if (v_n->a[r]->step_a >= v_n->a[r]->step_b)
		count = v_n->a[r]->step_b;
	else
		count = v_n->a[r]->step_a;
	while (count > i++)
		rr(v_n);
	while (diff_a-- > 0)
		ra(v_n);
	while (diff_b-- > 0)
		rb(v_n);
}

void	push_w_2(t_stacks *v_n, int r)
{
	int	count;
	int	i;
	int	diff_a;
	int	diff_b;

	i = 0;
	diff_a = v_n->a[r]->step_a - v_n->a[r]->step_b;
	diff_b = v_n->a[r]->step_b - v_n->a[r]->step_a;
	if (v_n->a[r]->step_a >= v_n->a[r]->step_b)
		count = v_n->a[r]->step_b;
	else
		count = v_n->a[r]->step_a;
	while (count > i++)
		rrr(v_n);
	while (diff_a-- > 0)
		rra(v_n);
	while (diff_b-- > 0)
		rrb(v_n);
}

void	push_w_3(t_stacks *v_n, int r)
{
	int	diff_a;
	int	diff_b;

	diff_a = v_n->a[r]->step_a;
	diff_b = v_n->a[r]->step_b;
	while (diff_a-- > 0)
		ra(v_n);
	while (diff_b-- > 0)
		rrb(v_n);
}

void	push_w_4(t_stacks *v_n, int r)
{
	int	diff_a;
	int	diff_b;

	diff_a = v_n->a[r]->step_a;
	diff_b = v_n->a[r]->step_b;
	while (diff_a-- > 0)
		rra(v_n);
	while (diff_b-- > 0)
		rb(v_n);
}

void	push_to_b(t_stacks *v_n, int r)
{
	if (v_n->a[r]->opt_way == 1)
		push_w_1(v_n, r);
	else if (v_n->a[r]->opt_way == 2)
		push_w_2(v_n, r);
	else if (v_n->a[r]->opt_way == 3)
		push_w_3(v_n, r);
	else
		push_w_4(v_n, r);
	pb(v_n);
}

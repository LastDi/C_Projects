/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <oalvera@student.21-school.r       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:41:12 by oalvera           #+#    #+#             */
/*   Updated: 2022/02/19 16:41:13 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stacks *valid_num)
{
	t_stack	*t;

	t = valid_num->a[0];
	valid_num->a[0] = valid_num->a[1];
	valid_num->a[1] = t;
	t = valid_num->b[0];
	valid_num->b[0] = valid_num->b[1];
	valid_num->b[1] = t;
	write (1, "ss\n", 3);
}

int	sum_step(int a, int b, int i)
{
	if (i == 1)
		a = 0;
	if (a >= b)
		return (a);
	else
		return (b);
}

int	find_place_b(t_stacks *v_n, int s, int m, int x)
{
	int	i;
	int	remember;
	int	remember_m;

	i = -1;
	while (++i < v_n->num_of_b)
	{
		if (v_n->b[i]->sort_numb - s == 1)
			return (i);
		else if (v_n->b[i]->sort_numb - s > 0 && v_n->b[i]->sort_numb - s < m)
		{
			remember = i;
			m = v_n->b[i]->sort_numb - s;
		}
		else if (v_n->b[i]->sort_numb - s == -1)
			return (-i);
		else if (v_n->b[i]->sort_numb - s < 0 && v_n->b[i]->sort_numb - s > x)
		{
			remember_m = i;
			x = v_n->b[i]->sort_numb - s;
		}
	}
	if (m > x * (-1))
		remember = remember_m * (-1);
	return (remember);
}

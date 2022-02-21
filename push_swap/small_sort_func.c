/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <oalvera@student.21-school.r       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:40:21 by oalvera           #+#    #+#             */
/*   Updated: 2022/02/19 16:40:22 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_stacks *v_n)
{
	int	i;
	int	max;

	i = 0;
	max = v_n->a[0]->data;
	while (i < v_n->num_of_a)
	{
		if (v_n->a[i]->data > max)
			max = v_n->a[i]->data;
		i++;
	}
	return (max);
}

int	find_min(t_stacks *v_n)
{
	int	i;
	int	min;

	i = 0;
	min = v_n->a[0]->data;
	while (i < v_n->num_of_a)
	{
		if (v_n->a[i]->data < min)
			min = v_n->a[i]->data;
		i++;
	}
	return (min);
}

void	sort_two(t_stacks *valid_num)
{
	if (valid_num->a[0]->data > valid_num->a[1]->data)
		sa(valid_num);
}

void	sort_three(t_stacks *valid_num)
{
	int	max;
	int	i;

	i = 0;
	max = valid_num->a[0]->data;
	while (i < valid_num->num_of_a)
	{
		if (valid_num->a[i]->data > max)
			max = valid_num->a[i]->data;
		i++;
	}
	if (valid_num->a[0]->data == max)
		ra(valid_num);
	if (valid_num->a[1]->data == max)
		rra(valid_num);
	if (valid_num->a[0]->data > valid_num->a[1]->data)
		sa(valid_num);
}

void	sort_four_or_five(t_stacks *valid_num)
{
	int	max;
	int	min;

	max = find_max(valid_num);
	min = find_min(valid_num);
	while (valid_num->num_of_a > 3)
	{
		if (valid_num->a[0]->data == max || valid_num->a[0]->data == min)
			pb(valid_num);
		else
			ra(valid_num);
	}
	sort_three(valid_num);
	pa(valid_num);
	pa(valid_num);
	if (valid_num->a[0]->data == max)
		ra(valid_num);
	else if (valid_num->a[1]->data < valid_num->a[2]->data)
		return ;
	else
	{
		sa(valid_num);
		ra(valid_num);
	}
}

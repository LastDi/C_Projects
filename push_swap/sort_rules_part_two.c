/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rules_part_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <oalvera@student.21-school.r       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:41:01 by oalvera           #+#    #+#             */
/*   Updated: 2022/02/19 16:41:02 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_stacks *valid_num)
{
	int		i;
	t_stack	*t;

	i = 0;
	t = valid_num->b[i];
	while (valid_num->num_of_b > i + 1)
	{
		valid_num->b[i] = valid_num->b[i + 1];
		i++;
	}
	valid_num->b[i] = t;
	write (1, "rb\n", 3);
}

void	rra(t_stacks *valid_num)
{
	int		i;
	t_stack	*temp_stack;

	i = valid_num->num_of_a - 1;
	temp_stack = valid_num->a[valid_num->num_of_a - 1];
	while (i > 0)
	{
		valid_num->a[i] = valid_num->a[i - 1];
		i--;
	}
	valid_num->a[0] = temp_stack;
	write (1, "rra\n", 4);
}

void	rrb(t_stacks *valid_num)
{
	int		i;
	t_stack	*t;

	i = valid_num->num_of_b - 1;
	t = valid_num->b[valid_num->num_of_b - 1];
	while (i > 0)
	{
		valid_num->b[i] = valid_num->b[i - 1];
		i--;
	}
	valid_num->b[0] = t;
	write (1, "rrb\n", 4);
}

void	rr(t_stacks *valid_num)
{
	int		i;
	t_stack	*t;

	i = 0;
	t = valid_num->a[i];
	while (valid_num->num_of_a - 1 > i)
	{
		valid_num->a[i] = valid_num->a[i + 1];
		i++;
	}
	valid_num->a[i] = t;
	i = 0;
	t = valid_num->b[i];
	while (valid_num->num_of_b - 1 > i)
	{
		valid_num->b[i] = valid_num->b[i + 1];
		i++;
	}
	valid_num->b[i] = t;
	write (1, "rr\n", 3);
}

void	rrr(t_stacks *valid_num)
{
	int		i;
	t_stack	*t;

	i = valid_num->num_of_a - 1;
	t = valid_num->a[valid_num->num_of_a - 1];
	while (i > 0)
	{
		valid_num->a[i] = valid_num->a[i - 1];
		i--;
	}
	valid_num->a[0] = t;
	i = valid_num->num_of_b - 1;
	t = valid_num->b[valid_num->num_of_b - 1];
	while (i > 0)
	{
		valid_num->b[i] = valid_num->b[i - 1];
		i--;
	}
	valid_num->b[0] = t;
	write (1, "rrr\n", 4);
}

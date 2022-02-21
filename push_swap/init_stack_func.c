/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <oalvera@student.21-school.r       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:39:53 by oalvera           #+#    #+#             */
/*   Updated: 2022/02/19 16:39:55 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stack_b(t_stacks *valid_num, int size)
{
	int	i;

	i = 0;
	valid_num->b = malloc(sizeof(char **) * (size + 1));
	if (!valid_num->b)
	{
		free(valid_num);
		return (0);
	}
	while (i < size)
	{
		valid_num->b[i] = malloc(sizeof(t_stack));
		if (!valid_num->b[i])
		{
			cleaning_b(valid_num, size);
			return (0);
		}
		valid_num->b[i]->sort_numb = 0;
		i++;
	}
	return (1);
}

int	init_stack_a(int *nums, int size, t_stacks *valid_num)
{
	int	i;

	i = 0;
	valid_num->a = malloc(sizeof(char **) * (size + 1));
	if (!valid_num->a)
		return (cleaning(valid_num, i));
	while (i < size)
	{
		valid_num->a[i] = malloc(sizeof(t_stack));
		if (!valid_num->a[i])
			return (cleaning(valid_num, i));
		valid_num->a[i]->data = nums[i];
		valid_num->a[i]->sort_numb = 0;
		i++;
	}
	if (!init_stack_b(valid_num, size))
		return (cleaning(valid_num, size));
	free(nums);
	return (1);
}

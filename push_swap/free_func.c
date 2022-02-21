/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <oalvera@student.21-school.r       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:39:44 by oalvera           #+#    #+#             */
/*   Updated: 2022/02/19 16:39:46 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_stacks(t_stacks *valid_num)
{
	free(valid_num);
	return (0);
}

int	cleaning(t_stacks *valid_num, int i)
{
	while (--i >= 0)
	{
		free(valid_num->a[i]);
	}
	free(valid_num->a);
	free(valid_num);
	return (0);
}

int	cleaning_b(t_stacks *valid_num, int i)
{
	int	c;

	c = 0;
	while (i > c)
	{
		free(valid_num->b[c]);
		c++;
	}
	free(valid_num->b);
	return (cleaning(valid_num, i));
}

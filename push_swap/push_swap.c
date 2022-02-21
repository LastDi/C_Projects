/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <oalvera@student.21-school.r       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:37:48 by oalvera           #+#    #+#             */
/*   Updated: 2022/02/19 16:37:52 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_checker(t_stacks *valid_num, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (valid_num->a[i]->data < valid_num->a[i + 1]->data)
			i++;
		else
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stacks	*valid_num;
	int			size;

	valid_num = malloc(sizeof(t_stacks));
	if (!valid_num)
		return (0);
	size = argc - 1;
	if (!validate_and_init(argc, argv, valid_num, size))
		return (0);
	valid_num->num_of_a = size;
	valid_num->num_of_b = 0;
	if (sort_checker(valid_num, size) || size == 1)
		return (cleaning_b(valid_num, size));
	else if (size == 2)
		sort_two(valid_num);
	else if (size == 3)
		sort_three(valid_num);
	else if (size == 4 || size == 5)
		sort_four_or_five(valid_num);
	else
		sort_elem(valid_num, size, -1);
	return (cleaning_b(valid_num, size));
}

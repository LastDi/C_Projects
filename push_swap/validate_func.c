/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <oalvera@student.21-school.r       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:41:21 by oalvera           #+#    #+#             */
/*   Updated: 2022/02/19 16:41:22 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_error(int i)
{
	if (i == 1)
	{
		write (i, "Error\n", 6);
		return (2147483648);
	}
	else
	{
		write (1, "Error\n", 6);
		return (0);
	}
}

long	ft_atoi(char *str)
{
	int		sign;
	int		num;
	int		i;

	sign = 1;
	num = 0;
	i = 0;
	if (!str[i])
		return (2147483648);
	if ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		return (ft_error(1));
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i++] - '0') * sign;
		if ((sign > 0 && num < 0) || (sign < 0 && num > 0))
			return (2147483648);
	}
	if (str[i])
		return (2147483648);
	return (num);
}

int	uniq_validator(int *nums, int size)
{
	int	i;
	int	j;
	int	temp_size;

	i = 0;
	temp_size = size;
	while (temp_size > 0)
	{
		j = i + 1;
		while (j < size)
		{
			if (nums[i] == nums[j])
				return (0);
			j++;
		}
		i++;
		temp_size--;
	}
	return (1);
}

int	arg_validator(char **s, int size, int *nums)
{
	int		temp_size;
	long	temp_num;

	if (size <= 0)
		return (0);
	temp_size = size;
	while (temp_size > 0)
	{
		temp_num = ft_atoi(s[temp_size]);
		if (temp_num <= 2147483647 && temp_num >= -2147483648)
			nums[temp_size - 1] = (int) temp_num;
		else
			return ((int) ft_error(0));
		temp_size--;
	}
	if (!uniq_validator(nums, size))
		return ((int) ft_error(0));
	return (1);
}

int	validate_and_init(int argc, char **argv, t_stacks *valid_num, int size)
{
	int		*nums;

	if (argc < 2)
		return (free_stacks(valid_num));
	nums = malloc(sizeof(int) * size);
	if (!arg_validator(argv, size, nums))
	{
		free(nums);
		return (free_stacks(valid_num));
	}
	return (init_stack_a(nums, size, valid_num));
}

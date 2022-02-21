/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <oalvera@student.21-school.r       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:40:44 by oalvera           #+#    #+#             */
/*   Updated: 2022/02/19 16:40:45 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_work(t_stacks *v, int i)
{
	int	sum_rr;
	int	sum_rrr;
	int	sum_mix;

	while (++i < v->num_of_a)
	{
		v->a[i]->step_b = ev_b_rr(v, v->a[i]->sort_numb);
		sum_rr = sum_step(i, v->a[i]->step_b, 0);
		v->a[i]->step_b = ev_b_rrr(v, v->a[i]->sort_numb);
		sum_rrr = sum_step(v->num_of_a - i, v->a[i]->step_b, v->num_of_a);
		if (i <= v->num_of_a / 2)
			sum_mix = i + v->a[i]->step_b;
		else
			sum_mix = v->num_of_a - i + ev_b_rr(v, v->a[i]->sort_numb);
		v->a[i]->step_sum = compration(sum_rr, sum_rrr, sum_mix);
		if (v->a[i]->step_sum == sum_rr)
			i_v(v->a[i], i, ev_b_rr(v, v->a[i]->sort_numb), 1);
		else if (v->a[i]->step_sum == sum_rrr)
			i_v(v->a[i], v->num_of_a - i, ev_b_rrr(v, v->a[i]->sort_numb), 2);
		else if (i <= v->num_of_a / 2)
			i_v(v->a[i], i, ev_b_rrr(v, v->a[i]->sort_numb), 3);
		else
			i_v(v->a[i], v->num_of_a - i, ev_b_rr(v, v->a[i]->sort_numb), 4);
	}
}

void	f_sort(t_stacks *valid_num)
{
	int	i;
	int	min;
	int	remember;

	i = -1;
	min = valid_num->a[0]->step_sum;
	if (valid_num->num_of_b == 0)
		pb(valid_num);
	stack_work(valid_num, -1);
	remember = 0;
	while (++i < valid_num->num_of_a)
	{
		if (valid_num->a[i]->step_sum <= min)
		{
			min = valid_num->a[i]->step_sum;
			remember = i;
		}
	}
	push_to_b(valid_num, remember);
	if (valid_num->num_of_a != 0)
		f_sort(valid_num);
}

int	part(int *sort_mas, int index, int key)
{
	int	less;
	int	temp;

	less = index;
	while (index < key)
	{
		if (sort_mas[index] < sort_mas[key])
		{
			temp = sort_mas[index];
			sort_mas[index] = sort_mas[less];
			sort_mas[less++] = temp;
		}
		index++;
	}
	temp = sort_mas[less];
	sort_mas[less] = sort_mas[key];
	sort_mas[key] = temp;
	return (less);
}

void	sort_arr(int *sort_mas, int index, int size)
{
	int	q;

	if (index < size)
	{
		q = part(sort_mas, index, size);
		sort_arr(sort_mas, index, q - 1);
		sort_arr(sort_mas, q + 1, size);
	}
}

void	sort_elem(t_stacks *valid_num, int size, int i)
{
	int	*sort_mas;
	int	count;

	sort_mas = malloc(sizeof(int) * size);
	if (!sort_mas)
		return ;
	while (++i < size)
		sort_mas[i] = valid_num->a[i]->data;
	sort_arr(sort_mas, 0, i - 1);
	i = 0;
	while (i < size)
	{
		count = -1;
		while (++count < size)
		{
			if (sort_mas[i] == valid_num->a[count]->data)
			{
				valid_num->a[count]->sort_numb = ++i;
				break ;
			}
		}
	}
	free(sort_mas);
	f_sort(valid_num);
	push_to_a(valid_num, -1);
}

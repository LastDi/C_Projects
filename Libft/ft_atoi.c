/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <oalvera@student.21-school.r       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 01:31:53 by oalvera           #+#    #+#             */
/*   Updated: 2021/10/23 20:18:13 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		res;
	long	l_res;
	int		znak;

	res = 0;
	l_res = 0;
	znak = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
			znak = -1;
		str++;
	}
	while (*str && (*str >= 48 && *str <= 57))
	{
		res = res * 10 + (*str - '0') * znak;
		l_res = l_res * 10 + (*str++ - '0') * znak;
		if (znak < 0 && l_res > 0)
			return (0);
		else if (znak > 0 && l_res < 0)
			return (-1);
	}
	return (res);
}

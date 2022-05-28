/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <oalvera@student.21-school.r       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 17:26:22 by oalvera           #+#    #+#             */
/*   Updated: 2022/05/28 17:26:24 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_print(t_bucket *bucket, t_philo *philo, char *str)
{
	if (bucket->death_flag)
		return ;
	pthread_mutex_lock(&bucket->print);
	if (bucket->death_flag)
		return ;
	printf("%lld %d %s\n", \
		get_timestamp() - philo->start_time, philo->id, str);
	pthread_mutex_unlock(&bucket->print);
}

int	print_error(char *error, char *msg)
{
	printf("%s: %s", error, msg);
	return (1);
}

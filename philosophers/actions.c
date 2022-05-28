/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <oalvera@student.21-school.r       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 17:25:41 by oalvera           #+#    #+#             */
/*   Updated: 2022/05/28 17:25:46 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_sleeping(t_bucket *bucket, t_philo *philo)
{
	if (bucket->death_flag)
		return ;
	philo_print(bucket, philo, "is sleeping");
	ft_usleep(philo->time_to_sleep);
}

void	philo_thinking(t_bucket *bucket, t_philo *philo)
{
	if (bucket->death_flag)
		return ;
	philo_print(bucket, philo, "is thinking");
}

int	philo_eating(t_bucket *bucket, t_philo *philo)
{
	if (bucket->death_flag)
		return (1);
	pthread_mutex_lock(&bucket->fork[philo->left_fork]);
	philo_print(bucket, philo, "has taken a fork");
	if (bucket->count_philo == 1)
		return (pthread_mutex_unlock(\
		&bucket->fork[bucket->philo->left_fork]), 1);
	pthread_mutex_lock(&bucket->fork[philo->right_fork]);
	philo_print(bucket, philo, "has taken a fork");
	philo_print(bucket, philo, "is eating");
	philo->count_eat++;
	philo->last_eat = get_timestamp();
	ft_usleep(philo->time_to_eat);
	pthread_mutex_unlock(&bucket->fork[philo->left_fork]);
	pthread_mutex_unlock(&bucket->fork[philo->right_fork]);
	return (0);
}

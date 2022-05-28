/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <oalvera@student.21-school.r       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 17:26:03 by oalvera           #+#    #+#             */
/*   Updated: 2022/05/28 17:26:04 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bucket	*init_bucket(int argc, char **argv)
{
	t_bucket	*all;

	all = malloc(sizeof(t_bucket));
	if (!all)
		return (NULL);
	all->count_philo = ft_atoi(argv[1]);
	all->time_to_die = ft_atoi(argv[2]);
	all->time_to_eat = ft_atoi(argv[3]);
	all->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		all->count_of_dinner = ft_atoi(argv[5]);
	all->death_flag = 0;
	all->start_time = 0;
	pthread_mutex_init(&all->print, NULL);
	all->philo = malloc(sizeof(t_philo) * all->count_philo);
	all->fork = malloc(sizeof(pthread_mutex_t) * all->count_philo);
	all->thread = malloc(sizeof(pthread_t) * all->count_philo);
	if (!all->thread || !all->fork || !all->philo)
		return (NULL);
	return (all);
}

int	init_philo(t_bucket *all)
{
	int	i;

	i = 0;
	while (i < all->count_philo)
	{
		all->philo[i].id = i + 1;
		all->philo[i].time_to_sleep = all->time_to_sleep;
		all->philo[i].time_to_eat = all->time_to_eat;
		all->philo[i].time_to_die = all->time_to_die;
		all->philo[i].count_eat = 0;
		all->philo[i].left_fork = i;
		if (i < all->count_philo - 1)
			all->philo[i].right_fork = i + 1;
		else
			all->philo[i].right_fork = 0;
		all->philo[i].last_eat = 0;
		all->philo[i].bucket = all;
		i++;
	}
	i = 0;
	while (i < all->count_philo)
		if (pthread_mutex_init(&all->fork[i++], NULL))
			return (1);
	return (0);
}

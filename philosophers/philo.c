/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <oalvera@student.21-school.r       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 17:26:15 by oalvera           #+#    #+#             */
/*   Updated: 2022/05/28 17:26:17 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_fight(void *tmp)
{
	t_philo		*philo;
	t_bucket	*bucket;

	philo = (t_philo *) tmp;
	bucket = philo->bucket;
	if (philo->id % 2 == 0)
	{
		philo_print(bucket, philo, "is thinking");
		usleep(50);
	}
	while (!bucket->death_flag)
	{
		if (bucket->count_of_dinner)
			if (philo->count_eat == bucket->count_of_dinner)
				return (NULL);
		if (philo_eating(bucket, philo))
			return (NULL);
		philo_sleeping(bucket, philo);
		philo_thinking(bucket, philo);
	}
	return (NULL);
}

int	philo_main(t_bucket *all)
{
	int			i;
	pthread_t	validator;

	i = -1;
	all->start_time = get_timestamp();
	while (++i < all->count_philo)
	{
		all->philo[i].start_time = all->start_time;
		all->philo[i].last_eat = all->start_time;
	}
	i = -1;
	while (++i < all->count_philo)
		pthread_create(&all->thread[i], NULL, &start_fight, &all->philo[i]);
	pthread_create(&validator, NULL, &death_check, all);
	pthread_mutex_unlock(&all->print);
	pthread_join(validator, NULL);
	i = -1;
	while (++i < all->count_philo)
		pthread_join(all->thread[i], NULL);
	return (0);
}

int	main(int argc, char **argv)
{
	t_bucket	*all;

	if (argv_validate(argc, argv))
		return (1);
	all = init_bucket(argc, argv);
	if (!all)
		return (ft_free(all));
	if (init_philo(all))
		return (ft_free(all));
	philo_main(all);
	ft_destroy_mutex(all);
	ft_free(all);
	return (0);
}

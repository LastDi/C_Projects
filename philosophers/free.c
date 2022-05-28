/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <oalvera@student.21-school.r       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 17:25:53 by oalvera           #+#    #+#             */
/*   Updated: 2022/05/28 17:25:55 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_free(t_bucket *all)
{
	if (all->philo)
		free(all->philo);
	if (all->fork)
		free(all->fork);
	if (all->thread)
		free(all->thread);
	free(all);
	return (1);
}

void	ft_destroy_mutex(t_bucket *all)
{
	int	i;

	i = -1;
	while (++i < all->count_philo)
		if (pthread_mutex_destroy(&all->fork[i]))
			printf("Error destroy mutex %d.\n", i);
	pthread_mutex_destroy(&all->print);
}

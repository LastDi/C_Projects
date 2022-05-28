/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <oalvera@student.21-school.r       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 17:26:30 by oalvera           #+#    #+#             */
/*   Updated: 2022/05/28 17:26:32 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

int	argv_validate(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (print_error("Error", "Wrong arguments number!\n"));
	else if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[2]) <= 0
		|| ft_atoi(argv[3]) <= 0 || ft_atoi(argv[4]) <= 0
		|| (argc == 6 && ft_atoi(argv[5]) <= 0))
		return (print_error("Error", "Wrong arguments!\n"));
	return (0);
}

long long	get_timestamp(void)
{
	struct timeval	time;
	long long		now;

	gettimeofday(&time, NULL);
	now = ((time.tv_sec * 1000) + (time.tv_usec / 1000));
	return (now);
}

void	ft_usleep(long long time)
{
	long long	start;

	start = get_timestamp();
	while (get_timestamp() - start < time)
		usleep(100);
}

void	*death_check(void *tmp)
{
	t_bucket	*all;
	t_philo		*philo;
	int			i;

	all = (t_bucket *) tmp;
	philo = all->philo;
	while (1)
	{
		i = -1;
		while (++i < all->count_philo)
		{
			if (all->count_of_dinner)
				if (philo->count_eat == all->count_of_dinner)
					return (NULL);
			if (get_timestamp() - philo[i].last_eat > philo[i].time_to_die)
			{
				all->death_flag = 1;
				pthread_mutex_lock(&all->print);
				printf("%lld %d is died \n", \
						get_timestamp() - philo->start_time, philo->id);
				return (NULL);
			}
		}
	}
}

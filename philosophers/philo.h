/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <oalvera@student.21-school.r       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 17:26:15 by oalvera           #+#    #+#             */
/*   Updated: 2022/05/28 17:26:17 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h> // usleep, write
# include <stdio.h> // printf
# include <string.h> // memset
# include <stdlib.h> // malloc, free
# include <sys/time.h> // gettimeofday
# include <pthread.h> //pthread_create

typedef struct s_philo
{
	int				id;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				count_eat;
	int				left_fork;
	int				right_fork;
	long long		start_time;
	long long		last_eat;
	struct s_bucket	*bucket;
}		t_philo;

typedef struct s_bucket
{
	int				count_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				count_of_dinner;
	int				death_flag;
	long long		start_time;
	pthread_t		*thread;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	t_philo			*philo;
}		t_bucket;

t_bucket	*init_bucket(int argc, char **argv);
int			ft_atoi(const char *str);
int			print_error(char *error, char *msg);
int			argv_validate(int argc, char **argv);
int			init_philo(t_bucket *all);
long long	get_timestamp(void);
void		ft_usleep(long long time);
void		philo_print(t_bucket *bucket, t_philo *philo, char *str);
void		*death_check(void *tmp);
int			philo_eating(t_bucket *bucket, t_philo *philo);
void		philo_sleeping(t_bucket *bucket, t_philo *philo);
void		philo_thinking(t_bucket *bucket, t_philo *philo);
void		*start_fight(void *tmp);
int			philo_main(t_bucket *all);
void		ft_destroy_mutex(t_bucket *all);
int			ft_free(t_bucket *all);

#endif

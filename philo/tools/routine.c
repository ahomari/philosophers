/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:07:35 by ahomari           #+#    #+#             */
/*   Updated: 2024/06/01 11:54:13 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_taken(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_left);
	pthread_mutex_lock(philo->is_live);
	if (*philo->live == 1)
	{
		pthread_mutex_lock(philo->print);
		printf("%zu %d has taken a fork\n", \
		ft_gettime() - philo->start_time, philo->id);
		pthread_mutex_unlock(philo->print);
	}
	pthread_mutex_unlock(philo->is_live);
	pthread_mutex_lock(philo->fork_rghit);
	pthread_mutex_lock(philo->is_live);
	if (*philo->live == 1)
	{
		pthread_mutex_lock(philo->print);
		printf("%zu %d has taken a fork\n", \
		ft_gettime() - philo->start_time, philo->id);
		pthread_mutex_unlock(philo->print);
	}
	pthread_mutex_unlock(philo->is_live);
}

void	ft_eating(t_philo *philo)
{
	size_t	time;

	time = ft_gettime();
	pthread_mutex_lock(philo->is_live);
	if (*philo->live == 1)
	{
		philo->start_time_eat = time;
		pthread_mutex_lock(philo->print);
		printf("%zu %d is eating\n", \
		ft_gettime() - philo->start_time, philo->id);
		pthread_mutex_unlock(philo->print);
		if (philo->number_eat > 0)
			philo->number_eat -= 1;
	}
	pthread_mutex_unlock(philo->is_live);
	ft_usleep(philo->time_to_eat);
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(philo->fork_rghit);
}

void	ft_sleeping(t_philo *philo)
{
	pthread_mutex_lock(philo->is_live);
	if (*philo->live == 1)
	{
		pthread_mutex_lock(philo->print);
		printf("%zu %d is sleeping\n", \
		ft_gettime() - philo->start_time, philo->id);
		pthread_mutex_unlock(philo->print);
	}
	pthread_mutex_unlock(philo->is_live);
	ft_usleep(philo->time_to_sleep);
}

void	ft_thinking(t_philo *philo)
{
	pthread_mutex_lock(philo->is_live);
	if (*philo->live == 1)
	{
		pthread_mutex_lock(philo->print);
		printf("%zu %d is thinking\n", \
		ft_gettime() - philo->start_time, philo->id);
		pthread_mutex_unlock(philo->print);
	}
	pthread_mutex_unlock(philo->is_live);
}

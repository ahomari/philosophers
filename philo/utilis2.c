/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:15:14 by ahomari           #+#    #+#             */
/*   Updated: 2024/05/31 22:39:15 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*thread_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->id % 2 == 0)
		ft_usleep(philo->time_to_eat);
	while (philo->number_eat != 0)
	{
		ft_taken(philo);
		ft_eating(philo);
		ft_sleeping(philo);
		ft_thinking(philo);
	}
	return (NULL);
}

int	create_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_philo)
	{
		if (pthread_create(&data->philo[i].tid, NULL, \
		thread_routine, &data->philo[i]) != 0)
			return (1);
		i++;
	}
	i = 0;
	while (i < data->nbr_philo)
	{
		if (pthread_detach(data->philo[i].tid) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	check_nbr_eat(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_philo)
	{
		if (data->philo[i].number_eat != 0)
			return (1);
		i++;
	}
	return (0);
}

void	check_died(t_data *data)
{
	int	i;

	while (1)
	{
		i = 0;
		pthread_mutex_lock(data->philo->is_live);
		if (check_nbr_eat(data) == 0)
			return (cleanup(data));
		pthread_mutex_unlock(data->philo->is_live);
		while (i < data->nbr_philo)
		{
			pthread_mutex_lock(data->philo[i].is_live);
			if (ft_gettime() - data->philo[i].start_time_eat > \
			data->time_to_die)
			{
				*data->philo[i].live = 0;
				pthread_mutex_lock(data->philo->print);
				printf("%zu %d died\n", \
				ft_gettime() - data->philo->start_time, data->philo->id);
				return (cleanup(data));
			}
			pthread_mutex_unlock(data->philo[i].is_live);
			i++;
		}
	}
}

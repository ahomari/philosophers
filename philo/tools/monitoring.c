/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 11:59:46 by ahomari           #+#    #+#             */
/*   Updated: 2024/06/06 21:15:00 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

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

void	monitoring(t_data *data)
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

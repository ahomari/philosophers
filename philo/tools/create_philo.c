/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:04:13 by ahomari           #+#    #+#             */
/*   Updated: 2024/06/05 11:04:36 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

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

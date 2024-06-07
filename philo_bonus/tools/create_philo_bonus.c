/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:04:13 by ahomari           #+#    #+#             */
/*   Updated: 2024/06/07 14:48:01 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	*thread_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	philo->pid = fork();
	if (philo->pid == 0)
	{
		pthread_create(&philo->tid_child, NULL, monitoring, philo);
		pthread_detach(philo->tid_child);
		while (philo->number_eat != 0)
		{
			ft_taken(philo);
			ft_eating(philo);
			ft_sleeping(philo);
			ft_thinking(philo);
		}
		exit (0);
	}
	else
		waitpid(philo->pid, NULL, 0);
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

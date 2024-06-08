/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 11:59:46 by ahomari           #+#    #+#             */
/*   Updated: 2024/06/08 00:31:27 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	*monitoring(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;

	while (1)
	{
		sem_wait(philo->check_d);
		if (ft_gettime() - philo->last_meal > \
		philo->time_to_die)
		{
			sem_wait(philo->print);
			printf("%zu %d died\n", \
			ft_gettime() - philo->start_time, philo->id);
			sem_post(philo->is_live);
			break ;
		}
		sem_post(philo->check_d);

	}
	return (NULL);
}

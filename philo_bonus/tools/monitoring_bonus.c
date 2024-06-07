/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 11:59:46 by ahomari           #+#    #+#             */
/*   Updated: 2024/06/07 01:17:49 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

// int	check_nbr_eat(t_data *data)
// {
// 	int	i;

// 	i = 0;
// 	while (i < data->nbr_philo)
// 	{
// 		if (data->philo[i].number_eat != 0)
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

void	*monitoring(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;

	while (1)
	{
		if (ft_gettime() - philo->start_time_eat > \
		philo->time_to_die)
		{
			sem_wait(philo->print);
			printf("%zu %d died\n", \
			ft_gettime() - philo->start_time, philo->id);
			sem_post(philo->is_live);
			break ;
		}
	}
	return (NULL);
}

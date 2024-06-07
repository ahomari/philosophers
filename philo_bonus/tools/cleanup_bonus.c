/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 20:49:08 by ahomari           #+#    #+#             */
/*   Updated: 2024/06/05 14:17:35 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

// void	cleanup(t_data *data)
// {
// 	int	i;

// 	i = 0;
// 	pthread_mutex_destroy(data->philo->print);
// 	pthread_mutex_destroy(data->philo->is_live);
// 	while (i < data->nbr_philo)
// 		pthread_mutex_destroy(&data->forks[i++]);
// 	free(data->philo->is_live);
// 	free(data->philo->live);
// 	free(data->philo->print);
// 	free(data->forks);
// 	free(data->philo);
// 	free(data);
// }

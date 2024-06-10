/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_eat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 12:25:37 by ahomari           #+#    #+#             */
/*   Updated: 2024/06/08 15:54:14 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	*nbr_repeat(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	usleep(50);
	while (waitpid(-1, NULL, 0) > 0)
		;
	sem_post(data->is_live);
	return (NULL);
}

void	repeat_eat(t_data *data)
{
	if (pthread_create(&data->tid_repeat, \
	NULL, nbr_repeat, data) != 0)
	{
		cleanup(data);
		exit (1);
	}
	if (pthread_detach(data->tid_repeat) != 0)
	{
		cleanup(data);
		exit (1);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 20:49:08 by ahomari           #+#    #+#             */
/*   Updated: 2024/06/08 15:55:29 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	cleanup(t_data *data)
{
	(sem_close(data->forks), sem_unlink("forks"));
	(sem_close(data->print), sem_unlink("print"));
	(sem_close(data->is_live), sem_unlink("is_live"));
	(sem_close(data->check_d), sem_unlink("check_d"));
	(free(data->philo), free(data));
}

void	kill_process(t_data *data)
{
	int	i;

	sem_wait(data->is_live);
	i = 0;
	while (i < data->nbr_philo)
	{
		kill(data->philo[i].pid, 2);
		i++;
	}
	cleanup(data);
	exit (0);
}

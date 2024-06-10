/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_philo_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 12:03:15 by ahomari           #+#    #+#             */
/*   Updated: 2024/06/08 15:51:47 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

int	init_semaphore(t_data *data)
{
	(sem_close(data->forks), sem_unlink("forks"));
	(sem_close(data->print), sem_unlink("print"));
	(sem_close(data->is_live), sem_unlink("is_live"));
	(sem_close(data->check_d), sem_unlink("check_d"));
	data->forks = sem_open("forks", O_CREAT, 0644, data->nbr_philo);
	data->print = sem_open("print", O_CREAT, 0644, 1);
	data->is_live = sem_open("is_live", O_CREAT, 0644, 0);
	data->check_d = sem_open("check_d", O_CREAT, 0644, 1);
	if (!data->forks || !data->print || !data->is_live || !data->check_d)
	{
		cleanup(data);
		exit (1);
	}
	return (0);
}

void	init_data(t_data *data, int ac, char **av)
{
	int	i;

	i = 0;
	while (i < data->nbr_philo)
	{
		data->philo[i].fork_left = data->forks;
		data->philo[i].fork_rghit = data->forks;
		data->philo[i].print = data->print;
		data->philo[i].is_live = data->is_live;
		data->philo[i].check_d = data->check_d;
		data->philo[i].id = i + 1;
		data->philo[i].time_to_die = ft_atoi(av[2]);
		data->philo[i].time_to_eat = ft_atoi(av[3]);
		data->philo[i].time_to_sleep = ft_atoi(av[4]);
		data->philo[i].start_time = ft_gettime();
		data->philo[i].last_meal = data->philo[i].start_time;
		if (ac == 6)
			data->philo[i].number_eat = ft_atoi(av[5]);
		else
			data->philo[i].number_eat = -1;
		i++;
	}
}

void	exec_philo(t_data *data, int ac, char **av)
{
	int	i;

	i = 0;
	data->philo = malloc(data->nbr_philo * sizeof(t_philo));
	if (!data->philo)
	{
		free(data);
		exit (1);
	}
	init_semaphore(data);
	init_data(data, ac, av);
	create_philo(data);
	repeat_eat(data);
	kill_process(data);
}

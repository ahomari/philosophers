/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_philo_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 12:03:15 by ahomari           #+#    #+#             */
/*   Updated: 2024/06/07 14:47:31 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

int	init_mutex(t_data *data)
{
	sem_close(data->forks);
	sem_unlink("forks");
	sem_close(data->print);
	sem_unlink("print");
	sem_close(data->is_live);
	sem_unlink("is_live");

	data->forks = sem_open("forks",  O_CREAT, 0644, data->nbr_philo);
	data->print = sem_open("print", O_CREAT, 0644, 1);
	data->is_live = sem_open("is_live", O_CREAT, 0644, 0);
	if (!data->print || !data->is_live || !data->forks)
		exit (1);
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

// int	check_nbr_eat(t_data *data)
// {
// 	int	i;

// 	i = 0;
// 	while (i < data->nbr_philo)
// 	{
// 		if (data->philo[i].number_eat == 0)
// 			i++;
// 		else
// 			break;
// 	}
// 	if (i == data->nbr_philo - 1)
// 		sem_post(data->is_live);
// 	return (0);
// }

void	*nbr_repeat(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	usleep(50);
	while (wait(NULL) != -1)
		;
	sem_post(data->is_live);
	return (NULL);
}

int	exec_philo(t_data *data, int ac, char **av)
{
	int	i;

	i = 0;
	data->philo = malloc(data->nbr_philo * sizeof(t_philo));
	if (!data->philo)
	{
		return (1);
	}
	init_mutex(data);
	init_data(data, ac, av);
	if (create_philo(data) == 1)
	{
		return (1);
	}
	pthread_create(&data->tid_repeat, NULL, nbr_repeat, data);
	pthread_detach(data->tid_repeat);
	sem_wait(data->is_live);
	i = 0;
	while (i < data->nbr_philo)
	{
		kill(data->philo[i].pid, 2);
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_philo_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 12:03:15 by ahomari           #+#    #+#             */
/*   Updated: 2024/06/07 01:32:06 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

// void	more_init(t_data *data)
// {
// 	int	i;

// 	i = 0;
// 	while (i < data->nbr_philo)
// 	{
		
// 		i++;
// 	}
// }

int	init_mutex(t_data *data)
{
	sem_close(data->forks);
	unlink("forks");
	sem_close(data->print);
	unlink("print");
	sem_close(data->is_live);
	unlink("is_live");

	printf(" sdfnkdnf %d\n", data->nbr_philo);
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
		data->philo[i].start_time_eat = data->philo[i].start_time;
		if (ac == 6)
			data->philo[i].number_eat = ft_atoi(av[5]);
		else
			data->philo[i].number_eat = -1;
		
		i++;
	}
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
	sem_wait(data->is_live);
	sem_close(data->forks);
	unlink("forks");
	sem_close(data->print);
	unlink("print");
	sem_close(data->is_live);
	unlink("is_live");
	i = 0;
	while (i < data->nbr_philo)
	{
		kill(data->philo[i].pid, 2);
		i++;
	}
	return (0);
}

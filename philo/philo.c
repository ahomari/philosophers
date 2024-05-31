/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:29:09 by ahomari           #+#    #+#             */
/*   Updated: 2024/05/31 22:52:48 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	more_init(t_data *data)
{
	int	i;

	(1) && (*data->live = 1, i = -1);
	while (++i < data->nbr_philo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		data->philo[i].print = data->print;
		data->philo[i].is_live = data->is_live;
		data->philo[i].live = data->live;
	}
}

int	init_mutex(t_data *data)
{
	data->print = malloc(sizeof(pthread_mutex_t));
	data->is_live = malloc(sizeof(pthread_mutex_t));
	data->live = malloc(sizeof(int));
	if (!data->print || !data->is_live || !data->live)
	{
		(free(data->print), free(data->is_live), free(data->live));
		(free(data->forks), free(data->philo), free(data));
		return (1);
	}
	if (pthread_mutex_init(data->print, NULL) != 0)
	{
		cleanup(data);
		return (1);
	}
	if (pthread_mutex_init(data->is_live, NULL) != 0)
	{
		cleanup(data);
		return (1);
	}
	more_init(data);
	return (0);
}

void	init_data(t_data *data, int ac, char **av)
{
	int	i;

	i = 0;
	while (i < data->nbr_philo)
	{
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
		data->philo[i].fork_left = &data->forks[i];
		if (i != data->nbr_philo - 1)
			data->philo[i].fork_rghit = &data->forks[i + 1];
		else
			data->philo[i].fork_rghit = &data->forks[0];
		i++;
	}
}

int	exec_philo(t_data *data, int ac, char **av)
{
	int	i;

	i = 0;
	data->philo = malloc(data->nbr_philo * sizeof(t_philo));
	data->forks = malloc(data->nbr_philo * sizeof(pthread_mutex_t));
	if (!data->forks || !data->philo)
	{
		(free(data->forks), free(data->philo), free(data));
		return (1);
	}
	init_mutex(data);
	init_data(data, ac, av);
	if (create_philo(data) == 1)
	{
		cleanup(data);
		return (1);
	}
	check_died(data);
	return (0);
}

int	parsing(t_data *data, int ac, char **av)
{
	int	i;
	int	nbr;

	i = 1;
	while (i < ac)
	{
		nbr = ft_atoi(av[i]);
		if (nbr < 0 || strlen(av[i]) == 0)
		{
			free(data);
			msg_error(-1, "Error Invalid Arg 2!!\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc (sizeof(t_data));
	if (!data)
		return (1);
	memset(data, 0, sizeof(t_data));
	if (ac != 5 && ac != 6)
	{
		msg_error(-1, "Error Invalid Arg!!\n");
		return (1);
	}
	data->nbr_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	if (data->nbr_philo == 0)
	{
		free(data);
		return (0);
	}
	if (parsing(data, ac, av) == 1)
		return (1);
	if (exec_philo(data, ac, av) == 1)
		return (1);
	return (0);
}

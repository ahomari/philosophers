/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:05:11 by ahomari           #+#    #+#             */
/*   Updated: 2024/05/24 11:49:12 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_gettime(void)
{
	struct timeval sp;

	if (gettimeofday(&sp, NULL) == -1)
		return (-1);
	return ((sp.tv_sec * 1000) + (sp.tv_usec / 1000));

}

void	*thread_routine(void *data)
{
	t_philo	*philo;
	
	philo = (t_philo *)data;
	philo->start_time = ft_gettime();
	while (1)
	{
		pthread_mutex_lock(philo->fork_left);
		printf("%zu %d took the fork left\n", ft_gettime() - philo->start_time, philo->id);
		pthread_mutex_lock(philo->fork_rghit);
		printf("%zu %d took the fork right\n", ft_gettime() - philo->start_time, philo->id);
		usleep(philo->time_to_eat * 1000);
		pthread_mutex_unlock(philo->fork_left);
		pthread_mutex_unlock(philo->fork_rghit);
		printf("%zu %d is Sleeping\n", ft_gettime() - philo->start_time, philo->id);
		usleep(philo->time_to_sleep * 1000);
		printf("%zu %d is Sleeping\n", ft_gettime() - philo->start_time, philo->id);
		printf("%zu %d is thinkingn\n", ft_gettime() - philo->start_time, philo->id);
	}
	return (NULL);
}

void	init_mutex(t_data *data, int nbr)
{
	int	i;

	i = 0;
	while (i < nbr)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	
}

void    init_data(int ac, char **av)
{
    t_data	*data;
    int		nbr;
	int		i;
    
	i = 0;
    nbr = ft_atoi(av[1]);
	data = malloc(sizeof(t_data));
    data->philo = malloc(nbr * sizeof(t_philo));
	data->forks = malloc(nbr * sizeof(pthread_mutex_t));
    if (!data || !data->forks || !data->philo)
        return (msg_error(-1, "Erorr Allocation\n"));
	init_mutex(data, nbr);
	while (i < nbr)
	{
		data->philo[i].id = i + 1;
		data->philo[i].time_to_die = ft_atoi(av[2]);
		data->philo[i].time_to_eat = ft_atoi(av[3]);
		data->philo[i].time_to_sleep = ft_atoi(av[4]);
		if (ac == 6)
			data->philo[i].number_eat = ft_atoi(av[5]);
		else
			data->philo[i].number_eat = -1;
		data->philo[i].fork_left = &data->forks[i];
		if (i != nbr - 1)
			data->philo[i].fork_rghit = &data->forks[i + 1];
		else
			data->philo[i].fork_rghit = &data->forks[0];
		i++;
	}
	i = 0;
	while (i < nbr)
	{
		pthread_create(&data->philo[i].tid, NULL, thread_routine, &data->philo[i]);
		i++;
	}
	i = 0;
	while (i < nbr)
	{
		// pthread_create(&data->philo->tid, NULL, thread_routine, &data->philo[i]);
		pthread_join(data->philo[i].tid, NULL);
		i++;
	}
}

void    parsing(int ac, char **av)
{
    int i;
    int nbr;

    i = 1;
    while (i < ac)
    {
        nbr = ft_atoi(av[i]);
        if (nbr < 0)
            return (msg_error(-1, "Erorr\n"));
        i++;
    }
}

int main(int ac, char **av)
{
    if (ac != 5 && ac != 6)
        printf("Erorr\n");
    parsing(ac, av);
    init_data(ac, av);
        
}
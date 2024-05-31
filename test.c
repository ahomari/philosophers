/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:05:11 by ahomari           #+#    #+#             */
/*   Updated: 2024/05/29 22:18:47 by ahomari          ###   ########.fr       */
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
	philo->start_time_eat = philo->start_time;
	if (philo->id % 2 == 0)
		ft_usleep(philo->time_to_eat);
	while (1)
	{
		ft_taken(philo);
		ft_eating(philo);
		ft_sleeping(philo);
		ft_thinking(philo);
	}
	return (NULL);
}

void	init_mutex(t_data *data, int nbr)
{
	pthread_mutex_t *print;
	pthread_mutex_t *is_live;
	int	*live;
	int	i;

	i = 0;
	print = malloc(sizeof(pthread_mutex_t));
	is_live = malloc(sizeof(pthread_mutex_t));
	live = malloc(sizeof(int));
	memset(print, 0, sizeof(pthread_mutex_t));
	memset(is_live, 0, sizeof(pthread_mutex_t));
	memset(live, 0, sizeof(int));
	
	if (!print || !is_live || !live)
		return ;
	pthread_mutex_init(print, NULL);
	pthread_mutex_init(is_live, NULL);
	*live = 1;
	while (i < nbr)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		data->philo[i].print = print;
		data->philo[i].is_live = is_live;
		data->philo[i].live = live;
		i++;
	}
	
}

// void	init_data(int ac, char **av, t_data **data)
// {
	
// }

void    exec_philo(int ac, char **av)
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
		pthread_detach(data->philo[i].tid);
		i++;
	}
	while (1)
	{
		i = 0;
		while (i < nbr)
		{
			pthread_mutex_lock(data->philo->is_live);
			if (ft_gettime() - data->philo[i].start_time_eat > data->philo->time_to_die)
			{
				data->philo->live = 0;
				printf("%zu %d died\n", ft_gettime() - data->philo->start_time, data->philo->id);
				return ;
			}
			pthread_mutex_unlock(data->philo->is_live);
			i++;
		}
		
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
        msg_error(-1, "Error Invalid Arg !!");
    parsing(ac, av);
    exec_philo(ac, av);
}
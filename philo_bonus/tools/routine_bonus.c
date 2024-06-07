/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:07:35 by ahomari           #+#    #+#             */
/*   Updated: 2024/06/07 01:27:08 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	ft_taken(t_philo *philo)
{

	sem_wait(philo->fork_left);
		printf("hehe\n");
	sem_wait(philo->print);
	printf("%zu %d has taken a fork\n", \
	ft_gettime() - philo->start_time, philo->id);
	sem_post(philo->print);
	sem_wait(philo->fork_rghit);
	sem_wait(philo->print);
	printf("%zu %d has taken a fork\n", \
	ft_gettime() - philo->start_time, philo->id);
	sem_post(philo->print);

}

void	ft_eating(t_philo *philo)
{
	size_t	time;

	time = ft_gettime();
	philo->start_time_eat = time;
	sem_wait(philo->print);
	printf("%zu %d is eating\n", \
	ft_gettime() - philo->start_time, philo->id);
	sem_post(philo->print);
	if (philo->number_eat > 0)
		philo->number_eat -= 1;
	ft_usleep(philo->time_to_eat);
	sem_post(philo->fork_left);
	sem_post(philo->fork_rghit);
}

void	ft_sleeping(t_philo *philo)
{
	sem_wait(philo->print);
	printf("%zu %d is sleeping\n", \
	ft_gettime() - philo->start_time, philo->id);
	sem_post(philo->print);
	ft_usleep(philo->time_to_sleep);
}

void	ft_thinking(t_philo *philo)
{
	sem_wait(philo->print);
	printf("%zu %d is thinking\n", \
	ft_gettime() - philo->start_time, philo->id);
	sem_post(philo->print);
}

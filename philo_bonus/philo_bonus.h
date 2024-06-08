/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:30:41 by ahomari           #+#    #+#             */
/*   Updated: 2024/06/08 00:13:04 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <limits.h>
#include <semaphore.h>
#include <signal.h>

typedef struct s_philo
{
	int				id;
	int				number_eat;
	int				*live;
	pid_t			pid;
	size_t			start_time;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			last_meal;
	pthread_t		tid;
	pthread_t		tid_child;
	sem_t	*fork_rghit;
	sem_t	*fork_left;
	sem_t	*print;
	sem_t	*is_live;
	sem_t	*check_d;
}	t_philo;

typedef struct s_data
{
	int				check_eat;
	int				nbr_philo;
	int				*live;
	pthread_t		tid_repeat;
	size_t			time_to_die;
	sem_t			*forks;
	sem_t			*print;
	sem_t			*is_live;
	sem_t	*check_d;

	t_philo			*philo;
}	t_data;

int		ft_atoi(char *str);
void	msg_error(int num, char *msg);
void	ft_eating(t_philo *philo);
void	ft_sleeping(t_philo *philo);
void	ft_thinking(t_philo *philo);
size_t	ft_gettime(void);
void	ft_usleep(size_t time);
void	ft_taken(t_philo *philo);
// void	cleanup(t_data *data);
int		create_philo(t_data *data);
void	*monitoring(void *data);
int		parsing(t_data *data, int ac, char **av);
int		exec_philo(t_data *data, int ac, char **av);
void	*ft_memset(void *b, int c, size_t len);

#endif
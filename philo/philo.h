/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:30:41 by ahomari           #+#    #+#             */
/*   Updated: 2024/06/09 17:16:46 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <limits.h>

#define malloc(x) NULL

typedef struct s_philo
{
	int				id;
	int				number_eat;
	int				*live;
	size_t			start_time;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time_eat;
	pthread_t		tid;
	pthread_mutex_t	*fork_rghit;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*print;
	pthread_mutex_t	*is_live;
}	t_philo;

typedef struct s_data
{
	int				check_eat;
	int				nbr_philo;
	int				*live;
	size_t			time_to_die;
	pthread_mutex_t	*print;
	pthread_mutex_t	*is_live;
	t_philo			*philo;
	pthread_mutex_t	*forks;
}	t_data;

int		ft_atoi(char *str);
void	msg_error(int num, char *msg);
void	ft_eating(t_philo *philo);
void	ft_sleeping(t_philo *philo);
void	ft_thinking(t_philo *philo);
size_t	ft_gettime(void);
void	ft_usleep(size_t time);
void	ft_taken(t_philo *philo);
void	cleanup(t_data *data);
int		create_philo(t_data *data);
void	monitoring(t_data *data);
int		parsing(int ac, char **av);
int		exec_philo(t_data *data, int ac, char **av);
void	*ft_memset(void *b, int c, size_t len);

#endif
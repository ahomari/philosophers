#ifndef PHILO_H
# define PHILO_H


# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_philo
{
    int id;
    pthread_t tid;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int number_eat;
    pthread_mutex_t *fork_rghit;
    pthread_mutex_t *fork_left;
    
}   t_philo;

typedef struct s_data
{
    t_philo         *philo;
    pthread_mutex_t	*forks;
}           t_data;






int     ft_atoi(char *str);
void	msg_error(int num, char *msg);

#endif
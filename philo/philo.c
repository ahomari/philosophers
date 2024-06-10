/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:29:09 by ahomari           #+#    #+#             */
/*   Updated: 2024/06/10 16:22:27 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void f()
{
	system("leaks philo");
}

int	main(int ac, char **av)
{
	t_data	*data;

	
	atexit(f);
	if (ac != 5 && ac != 6)
	{
		msg_error(-1, "Error Invalid Arg!!\n");
		return (1);
	}
	if (parsing(ac, av) == 1)
		return (1);
	if (ft_atoi(av[1]) == 0)
		return (0);
	data = malloc (sizeof(t_data));
	if (!data)
		return (1);
	ft_memset(data, 0, sizeof(t_data));
	data->nbr_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	if (exec_philo(data, ac, av) == 1)
		return (1);
	return (0);
}

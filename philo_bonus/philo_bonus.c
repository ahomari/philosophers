/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:29:09 by ahomari           #+#    #+#             */
/*   Updated: 2024/06/08 00:32:53 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc (sizeof(t_data));
	if (!data)
		return (1);
	ft_memset(data, 0, sizeof(t_data));
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

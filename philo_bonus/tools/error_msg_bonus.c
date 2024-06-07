/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:06:40 by ahomari           #+#    #+#             */
/*   Updated: 2024/06/05 14:00:41 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

static void	ft_print_msg(char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		write (2, &msg[i], 1);
		i++;
	}
}

void	msg_error(int num, char *msg)
{
	if (num == -1)
	{
		ft_print_msg(msg);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:16:15 by ahomari           #+#    #+#             */
/*   Updated: 2024/05/23 15:59:01 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int				i;
	int				n;
	unsigned long	r;

	i = 0;
	n = 1;
	r = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			n *= -1;
		i++;
	}
	while (str[i])
	{
        if (ft_isdigit(str[i]) == 0)
			return (-1);
		r = r * 10 +(str[i] - 48);
		i++;
	}
	return (r * n);
}



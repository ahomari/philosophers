/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:16:15 by ahomari           #+#    #+#             */
/*   Updated: 2024/05/31 20:48:22 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_gettime(void)
{
	struct timeval	sp;

	if (gettimeofday(&sp, NULL) == -1)
		return (-1);
	return ((sp.tv_sec * 1000) + (sp.tv_usec / 1000));
}

void	ft_usleep(size_t time)
{
	size_t	new;

	new = ft_gettime();
	while (ft_gettime() - new < time)
		usleep(60);
}

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

	(1) && (i = 0, n = 1, r = 0);
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			n *= -1;
		i++;
	}
	if (!str[i])
		return (-1);
	while (str[i])
	{
		//khasni nhandli int max
		if (ft_isdigit(str[i]) == 0)
			return (-1);
		r = r * 10 +(str[i] - 48);
		i++;
	}
	return (r * n);
}
